#include <stdio.h>




/**********************************
*函数名：
*函数功能：循环法实现二分法查找（默认数组递增排序）
*输入参数：a -- 待查证排序数组	
			min_cnt -- 数组最小下标
			max_cnt -- 数组最大下标
			value -- 待查找数
*返回值：1 -- 有	0 -- 无
**********************************/
int BinSearch(int *a, int min_cnt, int max_cnt, int value)
{
	int middle;
	int min_temp = min_cnt;
	int max_temp = max_cnt;
	while(min_temp <= max_temp)
	{
		middle = (min_temp + max_temp) / 2;
		if(a[middle] > value)//如果中间值大于value，那么value一定在min_temp - middle之间
		{
			max_temp = middle - 1;
		}
		else if(a[middle] < value)//如果中间值小于value，那么value一定在middle - max_temp之间
		{
			min_temp = middle + 1;
		}
		else//middle直接等于value
		{
			return middle;
		}
	}

	//如果一直没找到
	return -1;
}





int main(void)
{
	int a[5] = {1,2,3,4,5};

	int found;
	found = BinSearch(a, 0, 4, 1);

	printf("found is %d\n", found);

	return 0;
}

