#include <stdio.h>

void input(int *n, int *data)
{
	int i;

	scanf_s("%d", n);
	for (i = 0; i < *n; i++)
	{
		scanf_s("%d", data+i);
	}

	return;
}

void selection(int *n, int *data)
{
	int i;
	int j;

	for (i = 0; i < *n-1; i++)
	{
		int min = data[i];
		int min_i = i;
		int temp;

		for (j = i + 1; j < *n; j++)
		{
			if (min > data[j])
			{
				min = data[j];
				min_i = j;
			}
		}
		
		temp = data[i];
		data[i] = data[min_i];
		data[min_i] = temp;
	}

	return;
}

void output(int *n, int *data)
{
	int i;

	for (i = 0; i < *n; i++)
	{
		printf("%d ", data[i]);
	}

	return;
}

int main()
{
	int n;
	int data[1000];

	input(&n, &data[0]);
	selection(&n, &data[0]);
	output(&n, &data[0]);

	return 0;
}