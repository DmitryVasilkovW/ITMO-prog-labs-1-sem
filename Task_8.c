#include <stdio.h>
#include <string.h>

int main() {
	int n;
	char str1[] = "aaaab", str2[] = "bcdef";
	char c = 'a';
	scanf("%d", &n);
	printf("%d\n", strncmp(str1, str2, n));
	printf("%s\n", strncpy(str1, str2, n));
	printf("%s\n", strchr(str1, c));
	printf("%s\n", strstr(str1, str2));
	printf("%lu\n", strspn(str1, str2));
	return 0;
}
