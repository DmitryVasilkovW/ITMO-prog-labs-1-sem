#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <locale.h>

struct L{
	unsigned char bmp_header[54];
	unsigned long image_offset;
	unsigned long size;
	unsigned long w;
	unsigned long h;
};

int **arr_malloc(int h, int w) 
{
	int **arr = (int **)malloc(h * sizeof(int *));
	for (int i = 0; i < h; i++)
	{
		arr[i] = (int *)malloc(w * sizeof(int));
	}
	return arr;
}

int neighborCounter(int **cur_gen, unsigned long i, unsigned long j)
{
	int countOfNeighbors = 0;
	for (int k = -1; k <= 1; k++) 
	{
		for (int l = -1; l <= 1; l++)
		{
			if (!(k == 0 && l == 0) && cur_gen[i + k][j + l] == 1) 
			{
				countOfNeighbors++;
			}
		}
	}
	return countOfNeighbors;
}

char *transl_to_str(int **cur_gen, unsigned long w, unsigned long h) 
{
	char *pixelInfo = (char *)malloc(3 * w * h);
	for (unsigned long i = 0; i < h; i++) {
		for (unsigned long j = 0; j < w; j++) {
			if (cur_gen[i][j] == 0) {
				pixelInfo[3 * (i * w + j) + 0] = 0;
				pixelInfo[3 * (i * w + j) + 1] = 0;
				pixelInfo[3 * (i * w + j) + 2] = 0;
			} else {
				pixelInfo[3 * (i * w + j) + 0] = 255;
				pixelInfo[3 * (i * w + j) + 1] = 255;
				pixelInfo[3 * (i * w + j) + 2] = 255;
			}
		}
	}
	return pixelInfo;
}

int main(int argc, char *argv[]) 
{
	struct L inf;
	FILE *image;
	long dump_freq = 1;
	long max_iter = 1;
	char *dirName;
	int **cur_gen;
	int **next_gen;

	setlocale(LC_ALL, "Rus");
	for (int i = 1; i < argc; i += 2)
	{
		if (strcmp(argv[i], "--input") == 0) 
		{
			image = fopen(argv[i + 1], "rb");
			if (image == NULL) {
				printf("Cant open :(");
				return (0);
			}
		} else if (strcmp(argv[i], "--output") == 0) 
		{
			dirName = argv[i + 1];
		} else if (strcmp(argv[i], "--max_iter") == 0) 
		{
			max_iter = strtol(argv[i + 1], NULL, 10);
		} else if (strcmp(argv[i], "--dump_freq") == 0) 
		{
			dump_freq = strtol(argv[i + 1], NULL, 10);
		}
	}
	fread(inf.bmp_header, sizeof(unsigned char), 54, image);
	inf.image_offset = inf.bmp_header[0xD] << 24 | inf.bmp_header[0xC] << 16 |
	                   inf.bmp_header[0xB] << 8 | inf.bmp_header[0xA];
	inf.size = inf.bmp_header[0x5] << 24 | inf.bmp_header[0x4] << 16 |
	           inf.bmp_header[0x3] << 8 | inf.bmp_header[0x2];
	inf.w = inf.bmp_header[0x15] << 24 | inf.bmp_header[0x14] << 16 |
	        inf.bmp_header[0x13] << 8 | inf.bmp_header[0x12];
	inf.h = inf.bmp_header[0x19] << 24 | inf.bmp_header[0x18] << 16 |
	        inf.bmp_header[0x17] << 8 | inf.bmp_header[0x16];
	printf("offset - %lu\n", inf.image_offset);
	printf("size - %lu\n", inf.size);
	printf("height - %lu\n", inf.h);
	printf("width - %lu\n", inf.w);
	printf("\n");

	cur_gen = arr_malloc(inf.h, inf.w);
	next_gen = arr_malloc(inf.h, inf.w);
	fseek(image, inf.image_offset, SEEK_SET);

	char buffer[3];
	for (int i = inf.h - 1; i >= 0; i--) 
	{
		for (int j = 0; j < inf.w; j++) 
		{
			buffer[0] = fgetc(image);
			buffer[1] = fgetc(image);
			buffer[2] = fgetc(image);
			if (buffer[0] != 0 || buffer[1] != 0 || buffer[2] != 0) 
			{
				cur_gen[i][j] = 1;
			} 
			else 
			{
				cur_gen[i][j] = 0;
			}
		}
	}

	for (unsigned long i = 0; i < inf.h; i++) 
	{
		for (unsigned long j = 0; j < inf.w; j++) 
		{
			next_gen[i][j] = cur_gen[i][j];
		}
	}

	for (int gameIteration = 0; gameIteration < max_iter; gameIteration++) 
	{
		for (unsigned long i = 1; i < inf.h - 1; i++)
		{
			for (unsigned long j = 1; j < inf.w - 1; j++) 
			{
				int countOfNeighbors = neighborCounter(cur_gen, i, j);
				if (cur_gen[i][j] == 1)
				{
					if (countOfNeighbors < 2 || countOfNeighbors > 3) 
					{
						next_gen[i][j] = 0;
					}
				} 
				else 
				{
					if (countOfNeighbors == 3) 
					{
						next_gen[i][j] = 1;
					}
				}
			}
		}
		if (gameIteration % dump_freq == 0) 
		{
			char *pixelInfo = transl_to_str(next_gen, inf.w, inf.h);
			char *fileName = (char *)malloc(50 * sizeof(char));
			sprintf(fileName, "%s/%d.bmp", dirName, gameIteration / dump_freq);
			FILE *imageOutput = fopen(fileName, "wb");
			fwrite(inf.bmp_header, sizeof(unsigned char), 54, imageOutput);
			fseek(imageOutput, inf.image_offset, SEEK_SET);
			fwrite(pixelInfo, sizeof(char), 3 * inf.h * inf.w, imageOutput);
			fclose(imageOutput);
			free(fileName);
			free(pixelInfo);
		}
		for (unsigned long i = 0; i < inf.h; i++) 
		{
			for (unsigned long j = 0; j < inf.w; j++) 
			{
				cur_gen[i][j] = next_gen[i][j];
			}
		}
	}

	for (int i = 0; i < inf.h; i++)
	{
		free(cur_gen[i]);
		free(next_gen[i]);
	}
	free(cur_gen);
	free(next_gen);
	fclose(image);
	return 0;
}
