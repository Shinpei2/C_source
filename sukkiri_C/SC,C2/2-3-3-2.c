#include <stdio.h>

int main(void)
{
int tax = 108;	//税率は8%
int fax = 50000;
printf("50,000円から40,000円に値下げします\n");
tax = 40000;	//この行が誤り
printf("FAXの新価格(税込み) : %d円\n", fax*tax/100);
return 0;
}
