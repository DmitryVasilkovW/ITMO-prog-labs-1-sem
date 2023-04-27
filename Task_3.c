#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;
	scanf("%o", &a);
	printf("%x\n", a);
	printf("%x ", a);
	printf("%x\n", a << 4);
	printf("%x, ", a);
	printf("%x\n", ~a);
	scanf("%x", &b);
	printf("%x\n",a & b);
	return 0;
}
