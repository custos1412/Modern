#include <stdio.h>

void input(int *n, int *data)
{
	int i;

	scanf_s("%d", n);
	for (i = 0; i < *n; i++)
	{
		scanf_s("%d", &data[i]);
	}

	return;
}

void bubble(int *n, int *data)
{
	int i, j;

	for (i = 0; i < *n-1; i++)
	{
		for (j = 0; j < *n - 1 - i; j++)
		{
			if (data[j] > data[j+1]) //ascending sort
			{
				int temp;

				temp = data[j];
				data[j] = data[j+1];
				data[j+1] = temp;
			}
			/*
			if (data[j] < data[j+1]) //indecennding sort
			{
				int temp;
				temp = data[j+1];
				data[j+1] = data[j];
				data[j] = temp;
			}
			*/
			/*
			if (data[j] > data[j+1]) //another solution
			{
				data[j+1] = data[j+1]^data[j];
				data[j] = data[j+1]^data[j];
				data[j+1] = data[j+1]^data[j];
			}*/
		}
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
	bubble(&n, &data[0]);
	output(&n, &data[0]);

	return 0;
}