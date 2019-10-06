#include <stdio.h>

int main(void)
{
int tax = 108;	//税率は8%
int fax = 50000;
printf("50,000円から40,000円に値下げします\n");
fax = 40000;	//訂正版
printf("FAXの新価格(税込み) : %d円\n", fax*tax/100);
return 0;
}
