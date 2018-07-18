#include <stdio.h>

/*
Ä¬ÈÏÉýÐòÅÅÐò
*/

void BubbleSort(int *a, int number)
{
	int i,j;
	int temp;
	for(j = number - 1; j > 0; j--)
	{
		for(i = 0; i < j; i++)
		{
			if(a[i] > a[i+1])
			{
				temp = a[i];
				a[i] = a[i+1];
				a[i+1] = a[i];
			}
		}
	}
}

int main(void)
{
	int a[8] = {1,3,5,7,2,4,6,8};
	int i;
	BubbleSort(a, 8);

	for(i = 0; i < 8; i++)
		printf("%d\n", a[i]);

	return 0;
}