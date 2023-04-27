#include <stdio.h>
#include <stdlib.h>
#include <mm_malloc.h>

int main() {
	char arry[5] = {};
	char *ar = arry;
	arry[0] = 'H';
	arry[1] = 'E';
	arry[2] = 'l';
	arry[3] = 'l';
	arry[4] = 'O';
	for (int i = 0; i < 5; i++) {
		if (i == 4) {
			printf("%c\n", *(ar + i));
		} else {
			printf("%c", *(ar + i));
		}
	}

	char *arr = 0;
	arr = static_cast<char *>(malloc(sizeof(char) * 5));
	*arr = 'H';
	*(arr + 1) = 'E';
	*(arr + 2) = 'l';
	* (arr + 3) = 'l';
	* (arr + 4) = 'O';
	for (int i = 0; i < 6; i++)
	{
		printf("%c", arr[i]);
	}
	free(arr);
	return 0;
}
