#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef char str[1024] ;

int main (void)
{
    srand ( (unsigned) time (0UL) ) ;

    //配列answerに1桁の数を格納するアルゴリズム
    printf ("***数当てゲーム(レベル2)***\n3桁の数を当ててください！\n") ;
    int answer[3] ;
    int input[3] ;
    for ( int i = 0 ; i < 3 ; i++){         //配列answerの各桁に0~9のどれかを格納
        answer[i] = rand()%10 ;          printf ("%d\n", answer[i]) ;
    }

    //ゲーム全体のループと配列inputに1桁の数を格納するアルゴリズム
    int hit =0 ;
    int blow = 0 ;
    int Con =1 ;  //ゲーム全体の継続○行目で用いている
    while ( Con == 1 ){
        for ( int i =0 ; i<3 ; i++){        //各桁の数の予想を入力する。
            str inputChar ;
            printf ("%d桁目の予想を0~9の数字で入力してください：" , i+1 ) ;
            scanf ("%s" , inputChar ) ;
            input[i] = atoi (inputChar) ;
        }

        //answerとinputを比較するアルゴリズム
        for (int i = 0 ; i <3 ; i++){
            if ( input[i] ==answer[i] ){
                hit ++ ;
            } else {
                for (int j =0 ; j<3 ; j++){
                    if ( input[i] == answer[j] && i != j ){
                        blow++ ;
                    }
                }
            }
        }

        //結果発表とゲームを続けるかについて
        printf ("%dヒット！%dブロー\n" , hit , blow ) ;
        switch ( hit ){
            case 3 :
                printf ("正解です!\n") ;
                Con = 0 ;
                break ;
            default :
                ; str ConNo ;
                printf ("続けますか?(1:続ける 0:終了)\n") ;
                     //switch文の：変数宣言を挟む場合は；を挟む「case :； 変数宣言」
                scanf ("%s" , ConNo ) ;
                Con = atoi ( ConNo ) ;
                hit =0 ;
                blow = 0 ;
                if ( Con != 1 ){
                    printf ("正解は%d%d%dでした。", answer[2], answer[1] , answer [0]) ;
                }
        }
    }
    return 0 ;
}
