#include <stdio.h>

void input(int *n, int *data)
{
	int i;

	scanf_s("%d", n);
	for (i = 0; i < *n; i++)
	{
		scanf_s("%d", data + i);
	}

	return;
}

void quick(int *n, int *data, int left, int right)
{
	if (left < 0 || right < 0 || left >= right)
	{
		return;
	}

	int s = left;
	int l = left;
	int r = right;
	int pivot = data[l];
	int i;

	while (l < r)
	{
		while ((data[l] <= pivot) && (l < r))
		{
			l++;
		}
		while ((data[r] >= pivot) && (l < r))
		{
			r--;
		}

		if (l != r)
		{
			int temp;

			temp = data[l];
			data[l] = data[r];
			data[r] = temp;
		}
	}

	for (i = left; i < right; i++)
	{
		if (data[i+1] > pivot)
		{
			break;
		}
	}
	s = i;

	data[left] = data[s];
	data[s] = pivot;

	quick(n, &data[0], left, s-1);
	quick(n, &data[0], s + 1, right);

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
	quick(&n, &data[0], 0, n-1);
	output(&n, &data[0]);

	return 0;
}