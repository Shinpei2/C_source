#include <stdio.h>

typedef char String[1024] ;

int main (int argc,char** argv)
{
    printf("argc=%d\n",argc) ;      // "./a.out"を含んだ文字列の数
    for (int i = 0 ; i < argc ; i++){
        char* strAddr1 = argv[i] ;
        printf ("%d番目の情報:%s\n", i, strAddr1);
        printf ("%d番目のargcのアドレス:%ld\n", i, (long)strAddr1);
    }
    //for (int i = 0 ; i < argc ; i++){
        //char* strAddr2 = *(argv+i) ;
        //printf ("%d番目の情報:%s\n", i, strAddr2);
    //}

    return 0 ;
}
