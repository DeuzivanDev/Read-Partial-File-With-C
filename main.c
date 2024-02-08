#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <string.h>

int main(int argc, char *argv[])
{
	FILE *wall_file = fopen("wallet.dat", "r");
	char buff[4];

	fseek(wall_file, 9, SEEK_SET);
	size_t s = ftell(wall_file);

	fgets(buff, 4, wall_file);

	printf("The result is: \"%s\".\nBytes: %d.\nTell: %d.\n", buff, sizeof buff, s);
	
	printf("View bytes code...\n");
	for(size_t i = 0; i < strlen(buff); i++)
	{
		printf("[%d] - %d\n", i, buff[i]);
	}

	if(wall_file)
	{
		printf("Closing wallet...\n");
		fclose(wall_file);
		printf("Closed successfully!\n");
	}

	return EXIT_SUCCESS;
}
