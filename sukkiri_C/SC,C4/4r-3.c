#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    bool tenki = false ;
    if (tenki == true) {                    //ブロックが2行以上の場合は、{}で囲う
        printf ("洗濯をします\n") ;
        printf ("散歩に行きます") ;
    }   else{
            printf ("映画を観ます\n") ;    //ブロックが1行の場合は{}で囲わなくてもいい
            printf ("映画の感想をブログに書きます\n")
    }
    return 0 ;
}
