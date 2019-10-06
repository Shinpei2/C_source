/*=== puzumon:0 ソースコードひな形===*/
/*** インクルード宣言 ***/

#include <stdio.h>
#include <string.h>

/*** 列挙型宣言 ***/
typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;     //各属性値：0~5が対応

/*** グローバル定数の宣言 ***/
char symbols[6] = {'$','~','@','#','&',' '} ;
int ColorNumber[6] = {1,6,2,3,5,0} ;      //赤、水色、緑、黄、紫、黒が対応

/*** 構造体型宣言 ***/
//モンスター情報
typedef struct {
    char* name ;
    int HP ;
    int MaxHP ;
    Element element ;
    int Attack ;
    int Gard ;
} Monster ;

//ダンジョン情報
typedef struct {
  Monster* pDungeonMonsters ;
  const int numMonsters ;
} Dungeon;

//パーティ編成
typedef struct {
    char* pName ;
    Monster* pMonster ;
    int PartyNumber ;
    int pHP ;
    const int pMaxHP ;
    const int pGard ;
} Party ;


/*** プロトタイプ宣言 ***/
int goDungeon (Party* pParty, Dungeon* playdungeon) ;        //ダンジョン全体に責任を持つ関数。パーティとダンジョンを引き渡す＋勝利回数をintで戻す
int doBattle (Party* pParty  ,Monster* eneMonster) ;            //1回分の戦闘
Party organaizeParty (char* player, Monster* PartyMonster , int PartyNumber) ;           //プレイヤーと味方パーティを渡し、パーティを返す
void showParty (Party* pParty) ;
int onPlayerTurn ( Party* pParty, Monster* eneMonster ) ;
int doAttack ( Party* pParty, Monster* eneMonster ) ;
int onEnemyTurn ( Party* pParty, Monster* eneMonster ) ;
int doEnemyAttack ( Party* pParty, Monster* eneMonster ) ;

/*** ユーティリティ宣言 ***/
void  printMonsterName (Monster* monster) ;    //モンスターの色付け


//ゲーム開始から終了まで
int main (int argc, char** argv)
{
    if (argc != 2){
        printf("エラー：プレイヤー名を指定して起動してください\n") ;
        return 0;
    }
    //正しく名前が入力されたら、ゲームスタート
    printf("*** Puzzle & Monsters ***\n") ;

    //全味方モンスターの情報
    Monster suzaku = {"朱雀",150,150,FIRE,25,10} ;
    Monster seiryu = {"青龍",150,150,WIND,15,10} ;
    Monster byakko = {"白虎",150,150,EARTH,20,5} ;
    Monster genbu = {"玄武",150,150,WATER,20,15} ;
    Monster PartyMonster[] = {suzaku,seiryu,byakko,genbu} ;
    int pNum = 4;               //パーティのモンスター数。手入力
    char* Player = argv[1] ;
    Party party = organaizeParty(Player, PartyMonster, pNum) ;
    //printf("HP：%d　MaxHP：%d　Gard：%d\n", party.pHP, party.pMaxHP, party.pGard) ;      //ダミー。計算確認。
    //printf("パーティ関数を通したプレイヤーの名前：%s\n", party.pName) ;                                //ダミー。名前確認。

    //敵モンスターの基本情報　→Mosnster型の配列にする。
    Monster slime = {"スライム",100,100, WATER ,10,  5} ;
    Monster goblin = {"ゴブリン",200,200, EARTH ,20,15} ;
    Monster bigCombat = {"オオコウモリ",300,300, WIND ,30,25} ;
    Monster wearWolf= {"ウェアウルフ",400,400,WIND,40,40} ;
    Monster Dragon = {"ドラゴン",800,800,FIRE,50,40} ;
    Monster DungeonMonster1[] ={slime,goblin,bigCombat,wearWolf,Dragon};
    Dungeon dungeon1 = {DungeonMonster1 , 5} ;   //DungeonMonster1は配列先頭要素のアドレスを示す。

    int Victory = goDungeon(&party, &dungeon1) ;
    if (Victory == dungeon1.numMonsters) {
        printf("*** GAME CLEARED! ***\n") ;
        printf("倒したモンスター数=%d\n", Victory) ;
    }   else {
        printf("*** GAME OVER ***\n") ;
        printf("倒したモンスター数=%d\n", Victory) ;
    }
    return 0 ;
}


/*** 関数宣言 ***/
int goDungeon (Party* pParty, Dungeon* playdungeon){       //パーティ情報とDungoenを引き渡す。
    printf("%sのパーティ(HP = %d)はダンジョンに到着した\n" , pParty->pName, pParty->pMaxHP) ;
    showParty (pParty) ;

    int knockCount = 0 ;
    for (int i = 0 ; i <  playdungeon->numMonsters ; i+=1){
        knockCount += doBattle (pParty, &(playdungeon->pDungeonMonsters[i])) ;       //配列の特定要素をポインタで引き渡す→&( Pointa -> q[i] )　★この行が一番難しい
        //printf("knockCountのカウント：%d\n", knockCount ) ;
        if ( knockCount == i) {
            printf ("%sはダンジョンから逃げ出した\n", pParty->pName) ;
            return knockCount;
        }   else if ( knockCount == 5){
                printf("%sはダンジョンを制覇した\n", pParty->pName) ;
                return knockCount ;
        }   else {
                printf("%sは更に奥に進んだ\n\n", pParty->pName) ;
        }
    }
}

int doBattle (Party* pParty  ,Monster* eneMonster){      //勝ったら１，負けたら0を返す
    printMonsterName(eneMonster) ;
    printf("が現れた!\n") ;
    int win = 1 ;
    //printf("勝ちなら1,負けなら0\n入力：") ; scanf("%d", &win ) ;    //←ダミー。勝ち負けをキーボード入力。

    //どちらかのHPが0になるまで
    while (pParty->pHP > 0){
        eneMonster->HP -= onPlayerTurn (pParty,eneMonster) ;
        printf ("(敵残りHP：%d)\n", eneMonster->HP) ;
        if ( eneMonster->HP <= 0){
            win = 1 ;
            break ;
        }
        pParty->pHP -= onEnemyTurn(pParty,eneMonster) ;
        printf ("(味方残りHP：%d)\n", pParty->pHP) ;
        if ( pParty->pHP <= 0){
            win = 0 ;
        }
    }

    if (win == 1) {
        printMonsterName(eneMonster) ;
        printf("を倒した！\n") ;
        return 1;
    }   else {
            return 0;
    }
    return 0;
}

//モンスター名に色と記号をつける関数
void printMonsterName (Monster* monster){
    //printf ("\n受け取ったモンスターの属性番号：%d\n", (*monster).element) ;
    char symbol ;
    int color ;     //モンスターの属性に応じた色を格納する変数
    for (int i = 0 ; i<6 ; i++){
        if( monster->element == i){
                symbol = symbols[i] ;
                color = ColorNumber[i] ;
        }
    }
    printf("\x1b[3%dm", color) ;
    printf("%c%s%c", symbol, monster->name, symbol) ;
    printf("\x1b[0m") ;
    return ;
}

//パーティを編成する関数
Party organaizeParty (char* player, Monster* PartyMonster, int PartyNumber) {
    // 総HP、総MaxHP、総防御力を計算するアルゴリズム
    int sumHP=0 ;
    int sumMaxHP=0 ;
    int sumGard=0 ;
    for (int i =0 ; i<PartyNumber ; i+=1){
        sumHP += (&PartyMonster[i])->HP ;      //この書き方に慣れること。配列の特定の要素のアドレス＝構造体型があるアドレス
        sumMaxHP += (&PartyMonster[i])->MaxHP ;
        sumGard += (&PartyMonster[i])->Gard ;
    }
    Party pParty = {player, PartyMonster, PartyNumber, sumHP, sumMaxHP, sumGard } ;
    return pParty ;
}

//パーティ編成を表示する関数
void showParty (Party* pParty){
    printf ("<パーティ編成>------------------------------\n") ;
    for (int i = 0 ; i < pParty->PartyNumber ; i+=1){
        printMonsterName( &(pParty->pMonster[i]) ) ;
        printf("　HP=%d　攻撃=%d　防御=%d\n", (pParty->pMonster[i]).MaxHP, (pParty->pMonster[i]).Attack, (pParty->pMonster[i]).Gard ) ;
    }
    printf ("--------------------------------------------------\n\n") ;
    return ;
}

//味方のターンに責任を持つ関数
int onPlayerTurn ( Party* pParty, Monster* eneMonster ) {
    printf("【%s】のターン\n", pParty->pName) ;
    return doAttack(pParty,eneMonster) ;

}
//味方の1ターンの攻撃に責任を持つ関数
int doAttack ( Party* pParty, Monster* eneMonster ) {
    int damage =80 ;
    printf("ダミー攻撃で%dのダメージを与えた", damage) ;
    return damage ;
}

//敵の1ターンに責任を持つ関数
int onEnemyTurn ( Party* pParty, Monster* eneMonster ) {
    printf("【%s】のターン\n", eneMonster->name) ;
    return doEnemyAttack(pParty,eneMonster) ;
}

//敵の1ターンの攻撃に責任を持つ関数
int doEnemyAttack ( Party* pParty, Monster* eneMonster ) {
    int damage =20 ;
    printf("%dのダメージを受けた", damage) ;
    return damage ;
}
