#include <stdio.h>

int copy[10], ans[100005][10], temp[10], cnt, n, v[10],f;
char A[10];

void left(int k)
{
	int i,tmp;

	for (i = 0; i < k; i++)
	{
		tmp = copy[1];
		copy[1] = copy[2];
		copy[2] = copy[3];
		copy[3] = copy[4];
		copy[4] = tmp;
	}

	return;
}
void up(int k)
{
	int tmp,i;

	for (i = 0; i < k; i++)
	{
		tmp = copy[0];
		copy[0] = copy[1];
		copy[1] = copy[5];
		copy[5] = copy[3];
		copy[3] = tmp;
	}

	return;
}
void side(int k)
{
	int tmp, i;

	for (i = 0; i < k; i++)
	{
		tmp = copy[0];
		copy[0] = copy[2];
		copy[2] = copy[5];
		copy[5] = copy[4];
		copy[4] = tmp;
	}

	return;
}
bool check()
{
	int i, j, k, l;

	for (l = 0; l < cnt; l++)
	{
		for (i = 0; i < 4; i++)
		{
			for (j = 0; j < 4; j++)
			{
				for (f = 0; f < 4; f++)
				{
					if (i == 0 && j == 0)
					{
						continue;
					}
					for (k = 0; k < 6; k++)
					{
						copy[k] = ans[l][k];
					}

					left(i);
					up(j);
					side(f);

					for (k = 0; k < 6; k++)
					{
						if (copy[k] != temp[k])
						{
							break;
						}
					}
					if (k == 6)
					{
						return false;
					}
				}
			}
		}
	}

	return true;
}
void func(int k)
{
	int i;

	if (k == 6)
	{
		if (cnt == 0 || check())
		{
			for (i = 0; i < 6; i++)
			{
				ans[cnt][i] = temp[i];
			}
			cnt++;
		}
	}
	for (i = 0; i < 6; i++)
	{
		if (v[i] > 0)
		{
			v[i]--;
			temp[k] = i;
			func(k + 1);
			v[i]++;
		}
	}
	return;
}
int main()
{
	int i;

	scanf("%s", A);
	for (i = 0; i < 6; i++)
	{
		if (A[i] == 'R')
		{
			v[0]++;
		}
		else if (A[i] == 'O')
		{
			v[1]++;
		}
		else if (A[i] == 'Y')
		{
			v[2]++;
		}
		else if (A[i] == 'G')
		{
			v[3]++;
		}
		else if (A[i] == 'B')
		{
			v[4]++;
		}
		else if (A[i] == 'V')
		{
			v[5]++;
		}
	}

	func(0);

	printf("%d", cnt);

	return 0;
}