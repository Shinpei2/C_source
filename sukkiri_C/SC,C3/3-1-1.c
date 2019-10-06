#include <stdio.h>

int main (void)
{
    int a;
    int b;
    int c = 0x22;       //16進数の22 ＝ 34
    a = 20;     //＝や＋を演算子、数字や変数をオペランドと言う
    b = a + 5;
    printf("%d\n", a);
    printf("%d\n", b);
    printf("%d\n", c);
    return 0;
}
