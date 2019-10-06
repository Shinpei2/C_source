#include <stdio.h>

int main(void)
{
const int tax = 108;	// constでtaxを定数化
int fax = 50000;
printf("50,000円から40,000円に値下げします\n");
tax = 40000;	//taxが定数化されてるので、コンパイル時にエラー
printf("FAXの新価格(税込み) : %d円\n", fax*tax/100);
return 0;
}
