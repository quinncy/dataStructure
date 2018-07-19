#include <stdio.h>
#include <stdlib.h>


/*
合并算法
*/
void merge(int *a, int low, int mid, int high)
{


	int i, j;
	int k = 0;
	int *b = (int *)malloc(sizeof(int) * (high-low+1));


	if(low >= high)
		return;

	i = low;
	j = mid + 1;
	

	while(i <= mid && j <= high)
	{
		if(a[i] <= a[j])
		{
			*(b + k) = a[i];
			i++;
		}
		else
		{
			*(b + k) = a[j];
			j++;
		}
		k++;
	}

	while(i <= mid)
	{
		*(b + k) = a[i];
		i++;
		k++;
	}

	while(j <= high)
	{
		*(b + k) = a[j];
		j++;
		k++;
	}

	for(i = 0; i < k; i++)
	{
		a[low + i] = *(b + i);
	}
	
	free(b);
}

/*
弱归并算法
*/
void divide(int *a, int length)
{
	int GroupSize = 1;

	while(GroupSize < length)
	{
		int i;
		for(i = 0; i < length; i += (GroupSize * 2))
		{
			int low = i;
			int high;
			int middle;

			if((i + GroupSize * 2 - 1) < length)
				high = i + GroupSize * 2 - 1;
			else
				high = length - 1;

			middle = low + GroupSize - 1;
			if(middle > high)
				middle = (low + high) / 2;

			merge(a, low, middle, high);
		}

		GroupSize *= 2;
	}

	//对奇数情况进行处理
	if(GroupSize / 2 < length)
	{
		int low = 0;
		int high = length - 1;
		merge(a, low, GroupSize / 2 - 1, high);
	}
}

/*
强归并算法
*/
void sortCore(int *a, int start, int end)
{
	if(start == end)
		return;
	else
	{
		int middle = (start + end) / 2;
		sortCore(a, start, middle);
		sortCore(a, middle + 1, end);
		merge(a, start, middle, end);
	}
}

int main(void)
{
	int a[10] = {1,3,5,7,9,0,2,4,6,8};
	int i;

	sortCore(a, 0, 9);

	for(i = 0; i < 10; i++)
		printf("%d\n", a[i]);
	
	return 0;
}