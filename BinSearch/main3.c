#include <stdio.h>

/*

*/
int BinSearch_L(int *a, int low, int high, int value)
{
	/*
	*如果value <= a[low]，此时不存在下界
	*/
	int min = low;
	int max = high;
	int middle = (min + max + 1) / 2;
	while(min < max)
	{
		if(a[middle] < value)
		{
			min = middle;
		}
		else 
		{
			max = middle - 1;
		}
		middle = (min + max + 1) / 2;//待返回值一定要在循环的最后一步！！！
	}

	return middle;

	
}

int main(void)
{
	int a[5]={0,1,2,3,4};
	int found;
	found = BinSearch_L(a, 0, 4, 4);
	printf("found is %d\n", found);

	return 0;
}