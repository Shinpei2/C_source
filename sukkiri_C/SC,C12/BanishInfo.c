#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

typedef enum Element { FIRE , WATER , WIND ,EARTH , LIFE , EMPTY} Element ;     //各属性値：0~5が対応
typedef enum SlotNum {A,B,C,D,E,F,G,H,I,J,K,L,M,N} SlotNum ;   //スロットナンバーに対応

typedef struct {
    Element element ;
    SlotNum startSlot ;
    int continuity ;
} BanishInfo;

//プロトタイプ宣言
BanishInfo* checkBanishable(Element* Slot, BanishInfo* BIArray, BanishInfo* BanishPattern) ;      //BanishPatternに値を格納して戻す。

int main (void)
{
    //構造体の作成
    BanishInfo BIArray[165] ;                  //全消滅情報を格納するための配列。(全消滅条件：33[種類/属性]×5属性=165種類)
    int ArrayNum = 0 ;
    for(int i=0;i<5;i+=1){                          // i：エレメントナンバー
        for ( int j =3; j <=5 ; j+=1 ){              //j：連続数
            for(int k = 0; k < (15-j) ; k+=1){   //k：連続回数毎に対応する開始位置

                BIArray[ArrayNum].element = i ;
                BIArray[ArrayNum].startSlot  = k ;
                BIArray[ArrayNum].continuity = j ;
                //printf("%dループ目　　属性値：%d　開始位置：%d　連続数：%d\n", ArrayNum+1, BIArray[ArrayNum].element, BIArray[ArrayNum].startSlot, BIArray[ArrayNum].continuity ) ;
                ArrayNum += 1;
            }
        }
    }
    //printf("ArrayNumの値(全ループ回数)：%d\n\n",ArrayNum) ;

    Element Slot[14] ; for(int i =0; i<14; i++){Slot[i] = EMPTY;}       //Element配列のSlotの全要素をEMPTYで初期化
    srand ((unsigned)time (0UL)) ;
    for (int i = 0; i <14 ; i+=1){                                                              //宝石14個のランダム生成
        if (Slot[i] == EMPTY){
            Slot[i] = rand()%3 ;
            printf("%d ",Slot[i]) ;
        }
    }    printf("(宝石番号の表示)\n") ;

    BanishInfo BanishPattern[4] ;       //攻撃パターンを格納するBanishInfo配列
    checkBanishable(Slot, BIArray,BanishPattern) ;   //BanishInfoの全パターンを配列として返す

    return 0 ;
}

//___________________________________________________________________________________


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
            if (Slot[j] == Slot[j+1] && Slot[j+1]== Slot[j+2] ){
                EleNum = Slot[j] ;
                StartNum =  j;
                ContNum = 3;
                //4連続との重複を調べる
                for (int k =0; k<2 ; k++){
                    if ( EleNum != EMPTY && (C4[k].startSlot == StartNum || C4[k].startSlot+1 == StartNum) ){
                        //printf("3連続がありましたが、4連続と重複していました\n") ;
                        EleNum =EMPTY ;
                        break ;
                    }
                }
                //5連続との重複を調べる
                for (int k =0; k<3 ; k++){
                    if ( EleNum != EMPTY && (C5[k].startSlot == StartNum || C5[k].startSlot+1 == StartNum || C5[k].startSlot+2 == StartNum) ){
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
    //printf("BanishNumber[i]に対応するBIArrayの配列番号：\n") ;
    for ( int i =0 ; i<9 ; i++){
        for (int j = 0 ; j<164; j++ ) {
            if ( ContArray[i].element == BIArray[j].element && ContArray[i].startSlot == BIArray[j].startSlot && ContArray[i].continuity == BIArray[j].continuity){
                BanishNumber[i] = j ;
                break ;
            }
        }
        printf("%d ",BanishNumber[i]) ;
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
