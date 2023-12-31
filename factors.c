#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1024

void factorize(long long n)
{
	long long i;

	for (i = 2; i <= sqrt(n); ++i)
	{
		if (n % i == 0)
		{
			printf("%lld=%lld*%lld\n", n, n / i, i);
			return;
		}
	}
	printf("%lld=%lld*%lld\n", n, n, 1);
}

int main(int argc, char *argv[])
{
	char line[MAX];
	FILE *file;
	long long num;

	if (argc != 2)
	{
		printf("Usage: %s <file>\n", argv[0]);
		return (1);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}

	while (fgets(line, sizeof(line), file) != NULL)
	{
		num = atoi(line);
		factorize(num);
	}
	fclose(file);
	exit(EXIT_SUCCESS);
}
