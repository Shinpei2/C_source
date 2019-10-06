/*=== puzumon:0 ソースコードひな形===*/
/*** インクルード宣言 ***/

#include <stdio.h>

/*** 列挙型宣言 ***/

/*** グローバル定数の宣言 ***/
int KnockMonster ;

/*** 構造体型宣言 ***/
struct {char } enemy
/*** プロトタイプ宣言 ***/
int goDungeon (char* playerName) ;       //ダンジョン全体に責任を持つ関数
int doBattle (敵モンスター) ;            //1回のバトル開始から終了までの流れに責任を持つ関数

/*** 関数宣言 ***/
int goDungeon (char* playerName) ;
    printf("%sはダンジョンに到着した\n" , playerName) ;
    int knockCount = 0 ;
    doBattle (スライム) ; knockCount += 1 ;
    doBattle (ゴブリン) ; knockCount += 1 ;
    doBattle (オオコウモリ) ; knockCount += 1 ;
    doBattle (ウェアウルフ) ; knockCount += 1 ;
    doBattle (ドラゴン) ; knockCount += 1 ;
    if ( KnockCount == 5){
        printf("%sはダンジョンを制覇した\n") ;
        return knockCount ;
    }
    return knockCount ;
}

int doBattle (敵モンスター ){       //敵モンスターはポインタ渡し？、戻り値：勝＝１、負け＝0
    int knock ;
    printf ("%sが現れた!" , 敵モンスター) ;
    if (勝った場合) {
        printf ("%sを倒した！" , 敵モンスター) ;
        knock =1
        return knock ;
    }
        knock = 0
        return knock ; 
}

int main (int argc, char** argv)
{
    if (argc != 2){
        printf("エラー：プレイヤー名を指定して起動してください\n")
        return 0;
    }   else {
        printf("*** Puzzle & Monsters ***\n") ;
        int Victory = goDungeon(argv) ;

        if (Victory == 5) {
            printf("*** GAME CLEARED! ***\n")
            printf("倒したモンスター数=%d", 　　)
        }   else {
            printf("*** GAME OVER ***\n")
            printf("倒したモンスター数=%d", 　　)
    }

    }
    return 0 ;
}

/*** ユーティリティ宣言 ***/
