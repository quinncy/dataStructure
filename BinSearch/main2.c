#include <stdio.h>

/*

*/
int BinSearch_H(int *a, int low, int high, int value)
{
	/*
	*如果value >= a[high]，此时不存在上界
	*/
	int min = low;
	int max = high;
	int middle = (min + max) / 2;
	while(min < max)
	{
		if(a[middle] > value)
		{
			max = middle;
		}
		else 
		{
			min = middle + 1;
		}
		middle = (min + max) / 2;
	}

	return middle;

	
}

int main(void)
{
	int a[5]={1,2,3,4,5};
	int found;
	found = BinSearch_H(a, 0, 4, 1);
	printf("found is %d\n", found);

	return 0;
}