#include <stdio.h>

int main(void){
    char* name[4] = {"井上","菊池","佐藤","田中"};
    int tensu[4] = {70,65,100,30,} ;
    int Gokei =0;
    for(int i =0; i<4; i++){
        Gokei += tensu[i];
    }
    double Heikin = (double)(Gokei/4);
    char* bikou ;

    printf("____________________\n");
    printf("氏名　　点数　　備考\n");
    printf("--------------------\n");
    for(int i =0; i<4; i++){
        if (tensu[i] >= Heikin+20){
            bikou = "***" ;
        }else if(tensu[i]>=Heikin+10){
            bikou = "**";
        }else if (tensu[i]>=Heikin+1){
            bikou = "*";
        }else{
            bikou = "　";
        }
        printf("%s　　%d",name[i],tensu[i]);
        if ( 10<=tensu[i] && tensu[i]<=99){
            printf(" ") ;
        }
        printf("　　　%s\n",bikou) ;
    }
    printf("平均　　%.1f　　\n",Heikin);
    printf("====================\n");
    return 0;
}
