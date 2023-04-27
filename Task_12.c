#include <stdio.h>
#include <stdlib.h> 

int main(int argc, char* argv[]) 
{
	if (argc < 4) 
	{ 
		printf("Not enough arguments\n");
		return 1;
	}
	int c = (atoi(argv[2]) + atoi(argv[3]));
	FILE *file = fopen("12lab.txt", "w");
	if (file == NULL) 
	{
		printf("Unable to open file\n");
		return 1;
	}
	fprintf(file, "%d", c);
	fclose(file);
	return 0;
}
