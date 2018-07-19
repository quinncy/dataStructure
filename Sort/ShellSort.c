#include <stdio.h>

void ShellSort(int *a, int length)
{
	int gap = length / 2;

	int i,j,k;

	while(gap > 0)
	{
		for(k = 0; k < gap; k++)
		{
			for(j = gap + k; j < length; j += gap)
			{
				for(i = j; i > k; i -= gap)
				{
					int temp;

					if(a[i] < a[i - gap])
					{
						temp = a[i];
						a[i] = a[i - gap];
						a[i - gap] = temp;
					}
				}
			}
		}


		if(gap == 1)
			break;

		gap /= 2;
	}
}

int main(void)
{
	int a[8] = {1,3,5,7,2,4,6,8};
	int i;
	ShellSort(a, 8);

	for(i = 0; i < 8; i++)
		printf("%d\n",a[i]);

	return 0;
}