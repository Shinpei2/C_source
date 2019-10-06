#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

int main (int argc, char** argv)        //第2引数はchar**型で良い。
{
    if (argc != 3){
        printf("エラー！ファイルを2つ指定してください\n") ;
    }
    File *fpr = fopen(argv[1], "rb")
    if ( fpr == NULL){
        fclose(fpr) ;
        printf("エラー！コピー元ファイルが開けませんでした\n");
        exit(1) ;
    } else{
        printf("コピー元ファイルを開きました\n") ;
    }

    File *fpw = fopen(argv[2], "wb") ;
    if ( fpw == NULL){
        fclose(fpw) ;
        printf("エラー！コピー先ファイルが開けませんでした\n");
        exit(1) ;
    } else{
        printf("コピー先ファイルを開きました\n") ;
    }

    int ch = fgetc(fpr) ;
    while ( ch  != EOF) {
        fputc ( fpr ,fpw) ;
    }

    fclose(fpr) ;
    fclose(fpw) ;
    return 0 ;
}
