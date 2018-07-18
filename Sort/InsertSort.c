#include <stdio.h>


/*
Ä¬ÈÏ°´ÕÕµİÔöÅÅĞò
*/
void InsertSort(int *a, int number)
{
	int temp;
	int i = 0;
	int j = 1;

	for(j = 1; j < number; j++)
	{
		for(i = j; i > 0; i--)
		{
			if(a[i] < a[i - 1])
			{
				temp = a[i];
				a[i] = a[i - 1];
				a[i - 1] = temp;
			}
		}
	}
}

int main(void)
{
	int a[8] = {1,3,5,7,2,4,6,8};
	int i;
	InsertSort(a, 8);

	for(i = 0; i < 8; i++)
		printf("%d\n",a[i]);

	

	return 0;
}