/*
*递归法实现二分法查找
*/

#include <stdio.h>

/****************************************
*
*
*输入参数：
*
****************************************/
int BinSearch(int *a, int min_cnt, int max_cnt, int value)
{
	int middle = (min_cnt + max_cnt) / 2;

	if(min_cnt > max_cnt)
		return -1;

	if(a[middle] > value)
		return BinSearch(a, min_cnt, middle-1, value);
	else if(a[middle] < value)
		return BinSearch(a, middle+1, max_cnt, value);
	else
		return middle;


}


int main(void)
{
	int a[5] = {1,2,3,4,5};

	int found;
	found = BinSearch(a, 0, 4, 1);

	printf("found is %d\n", found);

	return 0;
}