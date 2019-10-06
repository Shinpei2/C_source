/*** インクルード宣言 ***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/***乱数生成のための準備***/

/*** 列挙型宣言 ***/
typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;     //各属性値：0~5が対応
typedef enum SlotNum {A=1,B,C,D,E,F,G,H,I,J,K,L,M,N} SlotNum ;   //スロットナンバーに対応

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
    Monster* PartyMonsters ;
    int PartyNumber ;
    int PartyHP ;
    const int PartyMaxHP ;
    const int PartyGard ;
} Party ;

//フィールド
typedef struct {
    Party* pParty ;
    Monster* pEneMonster ;
    Element* Slot ;      //要素数14のELEMENT型配列
} Field ;


/*** プロトタイプ宣言 ***/
int goDungeon (Party* pParty, Dungeon* pDungeon) ;        //ダンジョン全体に責任を持つ関数。パーティとダンジョンを引き渡す＋勝利回数をintで戻す
int doBattle (Party* pParty  ,Monster* pEneMonster) ;            //1回分の戦闘
Party organaizeParty (char* player, Monster* PartyMonsters , int PartyNumber) ;           //プレイヤーと味方パーティを渡し、パーティを返す
void showParty (Party* pParty) ;                                                        //パーティ情報の提示

Field* onPlayerTurn ( Field* pField ) ;     //以下戦闘関連→フィールド構造体を渡す。
Field* doAttack ( Field* pField ) ;
Field* onEnemyTurn ( Field* pField ) ;
Field* doEnemyAttack ( Field* pField ) ;
Field* fillGems (Field* pField) ;

void showBattleField (Field* pField) ;
void printGems (Element* pGemSlot) ;
void printGem (Element Gem) ;



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
    Monster PartyMonsters[] = {suzaku,seiryu,byakko,genbu} ;
    int pNum = 4;               //パーティのモンスター数。手入力
    char* Player = argv[1] ;
    Party party = organaizeParty(Player, PartyMonsters, pNum) ;
    //printf("HP：%d　MaxHP：%d　Gard：%d\n", party.PartyHP, party.PartyMaxHP, party.PartyGard) ;      //ダミー。計算確認。
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
int goDungeon (Party* pParty, Dungeon* pDungeon){       //パーティ情報とDungoenを引き渡す。
    printf("%sのパーティ(HP = %d)はダンジョンに到着した\n" , pParty->pName, pParty->PartyMaxHP) ;
    showParty (pParty) ;

    int knockCount = 0 ;
    for (int i = 0 ; i <  pDungeon->numMonsters ; i+=1){
        knockCount += doBattle (pParty, &(pDungeon->pDungeonMonsters[i])) ;       //配列の特定要素をポインタで引き渡す→&( Pointa -> q[i] )　★この行が一番難しい
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


/*----------------------------↓136行目より下側の関数のみいじる-----------------------------------------------------------------------------------------------------*/
int doBattle (Party* pParty  ,Monster* pEneMonster){      //勝ったら１，負けたら0を返す
    printMonsterName(pEneMonster) ;
    printf("が現れた!\n") ;
    Element GemSlot[14] ;
    for (int i = 0; i< 14; i+=1){
        GemSlot[i] = EMPTY;
    }
    Field BattleField = { pParty , pEneMonster, GemSlot } ;
    fillGems (&BattleField) ;       //初期の宝石の14個のランダム生成

    //どちらかのHPが0になるまで
    int win;
    while (pParty->PartyHP > 0){
        showBattleField (&BattleField) ;         //バトルフィールドの状況を画面に表示
        onPlayerTurn ( &BattleField ) ;
        printf ("(敵残りHP：%d)\n", pEneMonster->HP) ;
        if ( pEneMonster->HP <= 0){
            win = 1 ;
            break ;
        }
        onEnemyTurn( &BattleField ) ;
        printf ("(味方残りHP：%d)\n", pParty->PartyHP) ;
        if ( pParty->PartyHP <= 0){
            win = 0 ;
        }
    }

    if (win == 1) {
        printMonsterName(pEneMonster) ;
        printf("を倒した！\n") ;
        return 1;
    }   else {
            return 0;
    }
    return 0;
}

//味方のターンに責任を持つ関数
Field* onPlayerTurn ( Field* pField ) {
    printf("【%s】のターン\n", pField->pParty->pName) ;
    return doAttack(pField) ;

}
//味方の1ターンの攻撃に責任を持つ関数
Field* doAttack ( Field* pField ) {
    int damage =80 ;
    printf("ダミー攻撃で%dのダメージを与えた", damage) ;
    pField->pEneMonster->HP -= damage ;
    return pField ;
}

//敵の1ターンに責任を持つ関数
Field* onEnemyTurn ( Field* pField ) {
    printf("【%s】のターン\n", pField->pEneMonster->name) ;
    return doEnemyAttack( pField ) ;
}

//敵の1ターンの攻撃に責任を持つ関数
Field* doEnemyAttack ( Field* pField ) {
    int damage =20 ;
    printf("%dのダメージを受けた", damage) ;
    pField->pParty->PartyHP -= damage ;
    return pField ;
}

//EMPTYのスロットに宝石を格納する関数
Field* fillGems (Field* pField){
    srand ((unsigned)time (0UL)) ;
    for (int i = 0; i <14 ; i+=1){
        if (pField->Slot[i] == EMPTY){
            pField->Slot[i] = rand()%5 ;
            printf("\n%d ",pField->Slot[i]) ;
        }
    }
}

//フィールド情報を表示する関数
void showBattleField (Field* pField){
    //バトルフィールド情報
    printf("---------------------------------------\n\n") ;
    printf("　　　　"); printMonsterName(pField->pEneMonster) ;printf("　　　　");
    printf("\n　　　　HP= %d / %d\n", pField->pEneMonster->HP, pField->pEneMonster->MaxHP ) ;
    printf("\n\n\n　") ;
    for(int i = 0; i< pField->pParty->PartyNumber ; i+=1){
        printMonsterName(&(pField->pParty->PartyMonsters[i])) ;
        printf(" ") ;
    }
    printf("\n　　　　HP=%d / %d\n", pField->pParty->PartyHP, pField->pParty->PartyMaxHP ) ;
    printf("\n") ;
    printf("---------------------------------------\n") ;

    printGems( pField->Slot) ;
    printf("---------------------------------------\n") ;
}

//宝石14個を表示する関数
void printGems (Element* pGemSlot) {        //アルファベットの表示を追加する。
    char Slot[14] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N'} ;
    for (int i=0; i<14 ; i+=1){
    printf("%c ",Slot[i]) ;
    }
    printf("\n") ;
    for (int i=0; i<14 ; i+=1){

        printGem( pGemSlot[i]);
    }
    printf("\n") ;
}

//宝石1個を表示する関数
void printGem (Element Gem) {
    char symbol ;       //シンボルを格納する変数
    int color ;             //属性に応じた背景色を格納する変数
    for (int i = 0 ; i<6 ; i++){
        if( Gem == i){
                symbol = symbols[i] ;
                color = ColorNumber[i] ;
        }
    }
    printf("\x1b[30m") ;
    printf("\x1b[4%dm", color) ;
    printf("%c", symbol) ;
    printf("\x1b[39m") ;
    printf("\x1b[49m") ;
    printf(" ") ;
    return ;
}








/*------------------以下、編集済みの関数------------------------------------------------------------------------------------------*/
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
Party organaizeParty (char* player, Monster* PartyMonsters, int PartyNumber) {
    // 総HP、総MaxHP、総防御力を計算するアルゴリズム
    int sumHP=0 ;
    int sumMaxHP=0 ;
    int sumGard=0 ;
    for (int i =0 ; i<PartyNumber ; i+=1){
        sumHP += (&PartyMonsters[i])->HP ;      //この書き方に慣れること。配列の特定の要素のアドレス＝構造体型があるアドレス
        sumMaxHP += (&PartyMonsters[i])->MaxHP ;
        sumGard += (&PartyMonsters[i])->Gard ;
    }
    Party party = {player, PartyMonsters, PartyNumber, sumHP, sumMaxHP, sumGard } ;
    return party ;
}

//パーティ編成を表示する関数
void showParty (Party* pParty){
    printf ("<パーティ編成>------------------------------\n") ;
    for (int i = 0 ; i < pParty->PartyNumber ; i+=1){
        printMonsterName( &(pParty->PartyMonsters[i]) ) ;
        printf("　HP=%d　攻撃=%d　防御=%d\n", (pParty->PartyMonsters[i]).MaxHP, (pParty->PartyMonsters[i]).Attack, (pParty->PartyMonsters[i]).Gard ) ;
    }
    printf ("--------------------------------------------------\n\n") ;
    return ;
}
