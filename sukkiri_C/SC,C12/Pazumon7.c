/*** インクルード宣言 ***/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

/***乱数生成のための準備***/

/*** 列挙型宣言 ***/
typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;     //各属性値：0~5が対応
typedef enum SlotNum {A,B,C,D,E,F,G,H,I,J,K,L,M,N} SlotNum ;   //スロットナンバーに対応

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

//消去可能な宝石の並びに関する構造体型
typedef struct {
    Element element ;
    SlotNum startSlot ;
    int continuity ;
} BanishInfo;


/*** プロトタイプ宣言 ***/
int goDungeon (Party* pParty, Dungeon* pDungeon) ;        //ダンジョン全体に責任を持つ関数。パーティとダンジョンを引き渡す＋勝利回数をintで戻す
int doBattle (Party* pParty  ,Monster* pEneMonster) ;            //1回分の戦闘について
Party organaizeParty (char* player, Monster* PartyMonsters , int PartyNumber) ;           //パーティ編成について
void showParty (Party* pParty) ;                                                        //パーティ情報の提示

Field* onPlayerTurn ( Field* pField ) ;     //味方の1ターンについて
Field* doAttack ( Field* pField ) ;         //味方の1回の攻撃について
Field* onEnemyTurn ( Field* pField ) ;      //敵の1ターンについて
Field* doEnemyAttack ( Field* pField ) ;       //敵の1回の攻撃について

void showBattleField (Field* pField) ;


int checkValidCommand (char* Command) ;     //コマンド入力が正しいかどうか
Field* evaluateGems(Field* pField) ;        //バトルフィールドの宝石を評価
BanishInfo* checkBanishable(Element* Slot, BanishInfo* BIArray, BanishInfo* BanishPattern) ;      //BanishPatternに値を格納して戻す。
Field* banishGems(Field* pField , BanishInfo* BanishPattern) ;
Element* shiftGems (Element* Slot) ;



/*** ユーティリティ宣言 ***/
void  printMonsterName (Monster* monster) ;    //モンスターの色付け
Field* fillGems (Field* pField) ;           //宝石のランダム生成
void printGems (Element* pGemSlot) ;        //宝石14個を画面に表示
void printGem (Element Gem) ;                   //宝石1個を画面に表示
Element* moveGem (Element* Slot, char* Command) ;       //宝石を指定の位置まで動かす
Element* swapGem (Element* Slot, int LNum, int RNum) ;      //隣合う宝石どうしを交換する
Field* spawnGems (Field* pField) ;


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
    //バトルフィールドの表示
    printf("\n【%s】のターン\n", pField->pParty->pName) ;
    showBattleField (pField) ;

    //コマンド入力関連
    char Command[10] = {};
    int ComTF = 0 ;
    while(ComTF >= 0){
        printf("コマンド?>") ;
        scanf ("%s",Command) ;
        ComTF = checkValidCommand (Command) ;
        //printf("ComTFの値：%d\n",ComTF) ;
        if (ComTF == 1){
            break;
        }   else {
            printf("正しいコマンドを入力してください\n") ;
        }
    }

    //宝石移動関連
    moveGem (pField->Slot,Command) ;
    return evaluateGems(pField) ;
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
            //printf("%d ",pField->Slot[i]) ;
        }
    }
    //printf("(宝石番号の表示)\n") ;
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

//宝石移動のためのコマンド入力が正しいかどうかを判定する関数
int checkValidCommand (char* Command) {
    if ( (char)strlen(Command) != 2){
        return 0;
    }
    int count =0;
    for (int i =0; i<2; i+=1){
        if ( 65<=Command[i] && Command[i]<=78){
            count += 1;
        }
    }
    if (Command[0] == Command[1]){
        return 0;
    }
    if( count == 2){
        return 1;
    }   else {
        return 0;
    }
}

Element* moveGem ( Element* Slot,char* Command) {
    int Mae = Command[0] - 65 ;         //コマンド入力（A~N）をスロット番号（０〜１３）に変換
    int Ato =  Command[1] - 65 ;        //コマンド入力（A~N）をスロット番号（０〜１３）に変換
    if ( Mae<Ato ){     //右方向へ動かす場合
        for( int i =0; i < (Ato-Mae) ;i+=1){
            swapGem(Slot,Mae+i,Mae+i+1) ;
            printGems (Slot) ;
        }
    }   else {                //   左方向への移動(例：DAの場合)
            for(int i =0; i < (Mae-Ato); i+=1){
                swapGem(Slot,Mae-i-1,Mae-i) ;
                printGems (Slot) ;
            }
        }
}

Element* swapGem (Element* Slot, int LNum, int RNum) {
    Element Dam = Slot[LNum] ;
    Slot[LNum] = Slot[RNum] ;
    Slot[RNum] = Dam ;
    return Slot;
}


Field* evaluateGems(Field* pField) {
    //構造体の作成
    BanishInfo BIArray[166] ;                  //全消滅情報を格納するための配列。(全消滅条件：33[種類/属性]×5属性=165種類)＋1(ダミー用)
    int ArrayNum = 0 ;
    for(int i=0;i<5;i+=1){                          // i：エレメントナンバー
        for ( int j =3; j <=5 ; j+=1 ){              //j：連続数
            for(int k = 0; k < (15-j) ; k+=1){   //k：連続回数毎に対応する開始位置
                BIArray[ArrayNum].element = i ;
                BIArray[ArrayNum].startSlot  = k ;
                BIArray[ArrayNum].continuity = j ;
                ArrayNum += 1;
            }
        }
    }
    BIArray[165].element = EMPTY;
    BIArray[165].startSlot  = 0 ;
    BIArray[165].continuity = 0 ;

    BanishInfo BanishPattern[4] ;       //攻撃パターンを格納するBanishInfo配列
    checkBanishable(pField->Slot, BIArray, BanishPattern) ;       //消去可能な箇所を返す関数
    banishGems(pField,BanishPattern) ;              //doAttack関数が含まれている。
    shiftGems (pField->Slot) ;      //宝石を左詰めする
    spawnGems (pField) ;        //空いたスロットに宝石をランダム生成

}


/*　宝石消去判定に関するアルゴリズム　*/
BanishInfo* checkBanishable(Element* Slot, BanishInfo* BIArray, BanishInfo* BanishPattern){
    for(int i =0; i<4; i++){
        BanishPattern[i].element = EMPTY ;
        BanishPattern[i].startSlot  = 0 ;
        BanishPattern[i].continuity = 0 ;
    }

    //①フィールドの宝石判定：スロット内に3つ以上連続する値があるか調べる
    Element EleNum = EMPTY ;        //宝石属性
    int StartNum = 13;            //開始番号。13で初期化する理由は、連続が見つからない場合に、1ループ目でwhile分を抜けるようにするため。
    int EndNum = -1 ;       //ループの最初を確実に通すための初期化。0だと、Aから始まる宝石の連続がカウントされない。
    int ContNum = 0;        //連続数

    BanishInfo BIs[4] ;         //消去判定に対応するBIArrayを格納するための配列(連続の最大数：4)
    BanishInfo C5[2] ;        //5連続の情報を格納する配列
    BanishInfo C4[3] ;        //4連続の情報を格納する配列
    BanishInfo C3[4] ;        //4連続の情報を格納する配列

    //printf("ループ処理前：属性番号：%d　開始番号：%d　連続数：%d\n", EleNum, StartNum, ContNum) ;

    //5連続を探すアルゴリズム
    for (int i = 0; i<2; i++){
        EleNum = EMPTY ;
        for(int j = EndNum+1 ;  j <= J  ; j++ ){
                if ( Slot[j] == Slot[j+1]&& Slot[j+1]== Slot[j+2] && Slot[j+2]== Slot[j+3] && Slot[j+3] == Slot[j+4] ) {
                    EleNum = Slot[j] ;
                    StartNum = j ;
                    ContNum = 5;
                    break ;
                }
            }
            if (EleNum != EMPTY){
                EndNum = StartNum +4 ;
            }
            if ( EleNum== EMPTY){
                C5[i].element = EMPTY ;
                C5[i].startSlot = 13 ;
                C5[i].continuity = 0;
                EndNum = K ;
            }   else {
            //printf("5連続がありました！(%d個目)\n", i+1) ;
                C5[i].element = EleNum ;
                C5[i].startSlot = StartNum ;
                C5[i].continuity = ContNum ;
        }
    }


    //4連続を探すアルゴリズム
    EndNum = -1 ;
    StartNum = 13;
    for (int i = 0; i<3; i++){
        EleNum = EMPTY ;
        for( int j =EndNum+1; j <= K ; j++){
            if ( Slot[j] == Slot[j+1] && Slot[j+1]== Slot[j+2] && Slot[j+2]== Slot[j+3]) {
                EleNum = Slot[j] ;
                StartNum =  j;
                ContNum = 4;
                for (int k =0; k<2 ; k++){
                    if ( EleNum != EMPTY && (C5[k].startSlot == StartNum ||C5[k].startSlot+1 == StartNum) ){
                        //printf("4連続がありましたが、5連続と重複していました\n") ;
                        EleNum = EMPTY ;
                        break ;
                    }
                }
                if ( EleNum != EMPTY ){
                    break ;
                }
            }
        }
        EndNum = StartNum + 3 ;     //重複部分をうまくすれば、ループ回数減らせそう。
        //printf("EndNumの値4：%d\n", EndNum) ;

        //属性値に応じたC4への格納
        if (EleNum == EMPTY){
            C4[i].element = EMPTY ;
            C4[i].startSlot = 13 ;
            C4[i].continuity = 0 ;
        }   else{
                //printf("4連続がありました！(%d個目)\n", i+1) ;
                C4[i].element = EleNum ;
                C4[i].startSlot = StartNum ;
                C4[i].continuity = ContNum;
        }
    }

    //3連続を探すアルゴリズム
    EndNum = -1 ;
    StartNum = 13;
    for (int i = 0; i<4; i++){
        EleNum = EMPTY ;
        for (int j = EndNum+1 ; j <= L ; j++ ){
            if (Slot[j] == Slot[j+1] && Slot[j+1] == Slot[j+2] ){
                EleNum = Slot[j] ;
                StartNum =  j;
                ContNum = 3;
                //4連続との重複を調べる
                for (int k =0; k<3 ; k++){
                    if ( EleNum != EMPTY && (C4[k].startSlot == StartNum || C4[k].startSlot+1 == StartNum)){
                        //printf("3連続がありましたが、4連続と重複していました\n") ;
                        EleNum =EMPTY ;
                        break ;
                    }
                }
                //5連続との重複を調べる
                for (int k =0; k<2 ; k++){
                    if ( EleNum != EMPTY && (C5[k].startSlot == StartNum || (C5[k].startSlot)+1 == StartNum || C5[k].startSlot+2 == StartNum) ){
                        //printf("3連続がありましたが、5連続と重複していました\n") ;
                        EleNum =EMPTY ;
                        break ;
                    }
                }
                if ( EleNum != EMPTY ){
                    break ;
                }
            }
        }
        EndNum = StartNum + 2  ;
        //printf("EndNumの値3：%d\n", EndNum) ;

        //属性値に応じたC3への格納
        if (EleNum == EMPTY){
            C3[i].element = EMPTY ;
            C3[i].startSlot = 13 ;
            C3[i].continuity = 0 ;
        }   else{
                //printf("3連続がありました！(%d個目)\n", i+1) ;
                C3[i].element = EleNum ;
                C3[i].startSlot = StartNum ;
                C3[i].continuity = ContNum;
        }
    }

    //数値確認用
    //printf("C5に格納されている情報\n") ; for (int i =0 ; i<2; i++){ printf("属性番号：%d　開始番号：%d　連続数：%d\n", C5[i].element, C5[i].startSlot, C5[i].continuity) ;}
    //printf("C4に格納されている情報\n") ; for (int i =0 ; i<3; i++) { printf("属性番号：%d　開始番号：%d　連続数：%d\n", C4[i].element, C4[i].startSlot, C4[i].continuity) ;}
    //printf("C3に格納されている情報\n") ; for (int i =0 ; i<4; i++){ printf("属性番号：%d　開始番号：%d　連続数：%d\n", C3[i].element, C3[i].startSlot, C3[i].continuity) ;}

    //②C3〜C5に格納したパターンとBIArrayとの比較。
    BanishInfo ContArray[9] = { C3[0], C3[1] , C3[2] , C3[3], C4[0], C4[1], C4[2],C5[0],C5[1]} ;    //C3~C5をひとまとめにする。順番に注意
    int BanishNumber[9] = {165,165,165,165,165,165,165,165,165} ;
    for ( int i =0 ; i<9 ; i++){
        for (int j = 0 ; j<164; j++ ) {
            if ( ContArray[i].element == BIArray[j].element && ContArray[i].startSlot == BIArray[j].startSlot && ContArray[i].continuity == BIArray[j].continuity){
                BanishNumber[i] = j ;
                break ;
            }
        }
        //printf("%d ",BanishNumber[i]) ;
    }

    int Add =0;
    for (int i = 0; i<4 ; i++){
        for (int j =Add; j<9; j++ ){
            if (BanishNumber[j] != 165 ){
                BanishPattern[i] = BIArray[ BanishNumber[j] ] ;
                //printf("\nBanishPatern[%d]に対応するBanishNumber：%d\n", i+1,BanishNumber[j]);
                Add = j+1 ;
                break ;
            }
        }
    }
    return BanishPattern ;
}

Field* banishGems(Field* pField , BanishInfo* BanishPattern) {
    Element AtElement = EMPTY ;
    int Length = 0;
    int Combo = 0;
    for (int i=0; i<3; i++){
        if (BanishPattern[i].element != EMPTY){
            AtElement = BanishPattern[i].element ;
            Length = BanishPattern[i].continuity ;
            Combo = i+1 ;
            doAttack(pField) ;
            for(int j =BanishPattern[i].startSlot ; j < BanishPattern[i].startSlot+BanishPattern[i].continuity ; j++){
                pField->Slot[j] = EMPTY ;
            }
        }
    }
    return pField ;
}

Element* shiftGems (Element* Slot) {
    int EMPstart = 0 ;
    int EMPend = 0 ;
    int Move = 1;
    for (int i = 0; i < 11; i++){       //最大で10回の移動
        for (int j =EMPstart ; j<=12; j++){     //
            if( Slot[j] == EMPTY){
                EMPend = j;
                while ( Slot[EMPend+1] ==EMPTY && EMPend <= 12 ){
                    EMPend += 1 ;
                }
                if ( EMPend <=12 ){
                    Move = EMPend - j +1 ;
                    Element Dam = Slot [j+Move] ;
                    Slot[j+Move] = Slot[j] ;
                    Slot[j] = Dam ;
                }
                break ;
            }
        }
        EMPstart = EMPend - Move+1 ;
    }
    return Slot ;
}

Field* spawnGems (Field* pField) {
    fillGems (pField) ;
    return pField;
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
