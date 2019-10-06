#include <stdio.h>
#include <stdlib.h>

//列挙型の宣言
typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;

//構造体型の宣言
typedef struct {
    char* name ;
    int HP ;
    int MaxHP ;
    Element element ;
    int Attack ;
    int Gard ;
} Monster ;

typedef struct {
    char* pName ;
    Monster* pMonster ;
    int pNumber ;
    int pHP ;
    const int pMaxHP ;
    const int pGard ;
} Party ;

//プロトタイプ宣言
Party organaizeParty (char* player, Monster* partyInfo, int partynumber) ;

int main (int argc, char** argv){
    if (argc != 2) {
        printf("エラー。文字列を1つ入力してください\n") ;
        return 0;
    }

    //全味方モンスターの情報
    Monster suzaku = {"朱雀",150,150,FIRE,25,10} ;
    Monster seiryu = {"青龍",150,150,WIND,15,10} ;
    Monster byakko = {"白虎",150,150,EARTH,20,5} ;
    Monster genbu = {"玄武",150,150,WATER,20,15} ;
    Monster PartyMonster[] = {suzaku,seiryu,byakko,genbu} ;
    int pNum = 4;               //パーティのモンスター数。手入力
    char* Player = argv[1] ;
    Party party = organaizeParty(Player, PartyMonster, pNum) ;
    printf("HP：%d　MaxHP：%d　Gard：%d\n", party.pHP, party.pMaxHP, party.pGard) ;
    printf("パーティ関数を通したプレイヤーの名前：%s\n", party.pName) ;
    return 0 ;
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
    printf("パーティ関数内におけるプレイヤー名の表示：%s\n", party.pName) ;
    return pParty ;
}
