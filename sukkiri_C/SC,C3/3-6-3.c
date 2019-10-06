#include <stdio.h>
#include <stdlib.h>   //乱数表を呼び出すのに必要
#include <time.h>   //srandを使うのに必要

int main(void)
{
  srand ((unsigned)time(0UL)) ;   //rand()の前に実行
  int r = rand() % 100 ;    // r：変数、 乱数の範囲：0~99(%右値-1;指定値を含まない)
  printf ("あなたはおそらく、%d歳ですね。\n" , r ) ;
  return 0;
}
