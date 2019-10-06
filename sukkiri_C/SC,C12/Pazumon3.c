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
  Monster* monsters ;
  const int numMonsters ;
} Dungeon;

//パーティ編成
typedef struct {
    char* pName ;
    Monster* pMonster ;
    int pNumber ;
    int pHP ;
    const int pMaxHP ;
    const int pGard ;
} Party ;


/*** プロトタイプ宣言 ***/
int goDungeon (Party* playparty, Dungeon* playdungeon) ;        //ダンジョン全体に責任を持つ関数。パーティとダンジョンを引き渡す＋勝利回数をintで戻す
int doBattle (Party* battleParty  ,Monster* eneMonster) ;            //1回分の戦闘
Party organaizeParty (char* player, Monster* partyInfo , int partynumber) ;           //プレイヤーと味方パーティを渡し、パーティを返す
void showParty (Party* shParty) ;

/*** ユーティリティ宣言 ***/
void  printMonsterName (Monster* monsterInfo) ;    //モンスターの色付け


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
int goDungeon (Party* playparty, Dungeon* playdungeon){       //パーティ情報とDungoenを引き渡す。
    printf("%sのパーティ(HP = %d)はダンジョンに到着した\n" , playparty->pName, playparty->pMaxHP) ;
    showParty (playparty) ;

    int knockCount = 0 ;
    for (int i = 0 ; i < (*playdungeon).numMonsters ; i+=1){
        knockCount += doBattle (playparty,&(playdungeon->monsters[i])) ;       //配列のある要素のアドレスを引き渡す書き方に注意
        //printf("knockCountのカウント：%d\n", knockCount ) ;
        if ( knockCount == i) {
            printf ("%sはダンジョンから逃げ出した\n", playparty->pName) ;
            return knockCount;
        }   else if ( knockCount == 5){
                printf("%sはダンジョンを制覇した\n", playparty->pName) ;
                return knockCount ;
        }   else {
                printf("%sは更に奥に進んだ\n", playparty->pName) ;
        }
    }
}

int doBattle (Party* battleParty  ,Monster* eneMonster){      //勝ったら１，負けたら0を返す
    printMonsterName(eneMonster) ;
    printf("が現れた!\n") ;
    int win ;
    printf("勝ちなら1,負けなら0\n入力：") ; scanf("%d", &win ) ;    //←ダミー。勝ち負けをキーボード入力。

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
void printMonsterName (Monster* monsterInfo){
    //printf ("\n受け取ったモンスターの属性番号：%d\n", (*monsterInfo).element) ;
    char symbol ;
    int color ;     //モンスターの属性に応じた色を格納する変数
    for (int i = 0 ; i<6 ; i++){
        if( (*monsterInfo).element == i){
                symbol = symbols[i] ;
                color = ColorNumber[i] ;
        }
    }
    printf("\x1b[3%dm", color) ;
    printf("%c%s%c", symbol, (*monsterInfo).name, symbol) ;
    printf("\x1b[0m") ;
    return ;
}

//パーティを編成する関数
Party organaizeParty (char* player, Monster* partyInfo, int partynumber) {
    // 総HP、総MaxHP、総防御力を計算するアルゴリズム
    int sumHP=0 ;
    int sumMaxHP=0 ;
    int sumGard=0 ;
    for (int i =0 ; i<partynumber ; i+=1){
        sumHP += (&partyInfo[i])->HP ;      //この書き方に慣れること。配列の特定の要素のアドレス＝構造体型があるアドレス
        sumMaxHP += (&partyInfo[i])->MaxHP ;
        sumGard += (&partyInfo[i])->Gard ;
    }
    Party pParty = {player, partyInfo, partynumber, sumHP, sumMaxHP, sumGard } ;
    return pParty ;
}

void showParty (Party* shParty){
    printf ("<パーティ編成>------------------------------\n") ;
    for (int i = 0 ; i < shParty->pNumber ; i+=1){
        printMonsterName( &(shParty->pMonster[i]) ) ;
        printf("　HP=%d　攻撃=%d　防御=%d\n", (shParty->pMonster[i]).MaxHP, (shParty->pMonster[i]).Attack, (shParty->pMonster[i]).Gard ) ;
    }
    printf ("--------------------------------------------------\n\n") ;
    return ;
}
