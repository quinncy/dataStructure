#include <stdio.h>

/*

*/
int BinSearch_L(int *a, int low, int high, int value)
{
	/*
	*���value <= a[low]����ʱ�������½�
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
		middle = (min + max + 1) / 2;//������ֵһ��Ҫ��ѭ�������һ��������
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