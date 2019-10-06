#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    int W = 8 ;     //横8ピクセル
    int H = 8 ;     //縦8ピクセル
    //int imageSize = 3*W*H ;   ※配列の要素数に変数を使用することはできない。
    char header[54] = {} ;      //管理情報
    char image[192] = {} ;      //3×8ピクセル×8ピクセル

/*管理情報*/
    header[0] = 66;
    header[1] = 77;
    int *di ;       //char型配列の4つ分に相当
    di =(int*)(header+2);     //アドレス指定(header[2]~[5])。headerは&header[0]を意味する。
    *di = 54 + 3*W*H ;
    //header[6]~[9]は固定値0
    di = (int*)(header+10) ;    //header[10]~[13]に指定
    *di = 54 ;
    di = (int*)(header+14) ;
    *di = 40 ;
    di = (int*)(header+18) ;
    *di = W;
    di = (int*)(header+22) ;
    *di = H;

    short *ds ;     //char型配列2つ分に相当
    ds = (short*)(header+26) ;
    *ds = 1 ;
    ds = (short*)(header+28) ;
    *ds = 24;

    //header[28]~[53]までは固定値0

    /*画像データの作成*/
    for (int i = 0; i<192; i++ ){
        image[i] = -1;
        image[i+1] = 0 ;
        image[i+2] = 0 ;
    }

    FILE *fp = fopen("bluebox.bmp","wb") ;
    if (fp == NULL){
        fclose(fp) ;
        exit(1) ;
    }

    //データの書き込み
    fwrite(header,54,1,fp) ;
    fwrite(image,imageSize,1,fp) ;

    fclose(fp) ;
    return 0 ;
}
