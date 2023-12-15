#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void factorize(int n)
{
	int i;

	for (i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			printf("%d=%d*%d\n", n, i, n / i);
			return;
		}
	}
	printf("%d=%d*%d\n", n, n, 1);
}

int main(int argc, char *argv[])
{
	char line[20];
	FILE *file;
	int num;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		return (1);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		num = atoi(line);
		factorize(num);
	}
	fclose(file);
	return (0);
}

