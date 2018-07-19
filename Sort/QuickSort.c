#include <stdio.h>

void swap(int *a, int i, int j)
{
	int temp;

	temp = a[i];
	a[i] = a[j];
	a[j] = temp;
}

void dealPrivot(int *a, int i, int j)
{
	int middle = (i + j) / 2;

	if(a[i] > a[middle])
		swap(a, i, middle);
	if(a[middle] > a[j])
		swap(a, middle, j);
	if(a[i] > a[middle])
		swap(a, i, middle);

	swap(a, middle, j-1);
}

void QuickSort(int *a, int low, int high)
{
	if(low >= high)
		return;
	else
	{
		int privot;
		int left;
		int right;

		dealPrivot(a, low, high);
		privot = high - 1;
		left = low;
		right = high - 1;

		while(1)
		{
			while(a[++left] < a[privot]);//找到左边第一个大于枢纽值的元素
			while((a[--right] > a[privot]) && (right > low));//找到右边第一个小于枢纽值的元素

			if(left < right)//如果左<右，那么就交换
				swap(a, left, right);
			else
				break;

		}

		if(left < high-1)//如果left指针小于枢纽值
			swap(a, left, high-1);

		QuickSort(a, low, left-1);
		QuickSort(a, left+1, high);
	}
}

int main(void)
{
	int a[8] = {1,3,5,7,2,4,6,8};
	int i;

	QuickSort(a,0,7);

	for(i = 0; i < 8; i++)
		printf("%d\n",a[i]);

	return 0;
}