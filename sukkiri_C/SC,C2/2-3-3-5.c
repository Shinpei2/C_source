#include <stdio.h>

int main(void)
{
	enum {a = 1, b, c, d};
	printf("%d\n", a);
	printf("%d\n", b);
	printf("c× dを計算すると%d\n", c*d);
	return 0;
}
