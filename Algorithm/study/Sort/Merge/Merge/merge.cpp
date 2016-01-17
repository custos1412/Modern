#include <stdio.h>

void input(int *n, int data[])
{
	int i;

	scanf_s("%d", n);
	for (i = 0; i < *n; i++)
	{
		scanf_s("%d", &data[0]+i);
	}

	return;
}

void merge(int data[], int *s, int *e, int *avr)
{
	int i = *s;
	int j = *e;
	int temp[1000];
	int cnt = 0;

	while (i <= *avr && *avr < j)
	{
		if (data[i] < data[j])
		{
			temp[cnt++] = data[i++];
		}
		else
		{
			temp[cnt++] = data[j--];
		}
	}

	while (i <= *avr)
	{
		temp[cnt++] = data[i++];
	}
	while (j > *avr)
	{
		temp[cnt++] = data[j--];
	}

	for (i = 0; i < cnt; i++)
	{
		data[*s+i] = temp[i];
	}

	return;
}

void mergeSort(int *n, int data[], int *s, int *e) {

	if (*s < *e)
	{
		int avr = (*s + *e) / 2;

		mergeSort(n, &data[0], s, &avr);
		avr++;
		mergeSort(n, &data[0], &avr, e);
		avr--;
		merge(&data[0], s, e, &avr);
	}

	return;
}

void output(int *n, int data[])
{
	int i;

	for (i = 0; i < *n; i++)
	{
		printf("%d ", data[0]+i);
	}

	return;
}

int main()
{
	int n;
	int data[1000];
	int s = 0;
	int e;

	input(&n, &data[0]);
	e = n - 1;
	mergeSort(&n, &data[0], &s, &e);
	output(&n, &data[0]);

	return 0;
}