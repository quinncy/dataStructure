#include <stdio.h>

void SelectSort(int *a, int number)
{
	int i,j;
	int min_value;
	int temp_cnt;
	int temp;
	for(i = 0; i < number - 1; i++)
	{
		min_value = a[i];
		temp_cnt = i;
		for(j = i; j < number - 1; j++)
		{
			if(a[j] < min_value)
			{
				min_value = a[j];
				temp_cnt = j;
			}
		}
		temp = a[i];
		a[i] = a[temp_cnt];
		a[temp_cnt] = temp;
	}
}

int main(void)
{
	int a[8] = {1,3,5,7,2,4,6,8};

	int i;

	SelectSort(a, 8);
	for(i = 0; i < 8; i++)
		printf("%d\n", a[i]);

	

	return 0;

}