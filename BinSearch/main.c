#include <stdio.h>




/**********************************
*��������
*�������ܣ�ѭ����ʵ�ֶ��ַ����ң�Ĭ�������������
*���������a -- ����֤��������	
			min_cnt -- ������С�±�
			max_cnt -- ��������±�
			value -- ��������
*����ֵ��1 -- ��	0 -- ��
**********************************/
int BinSearch(int *a, int min_cnt, int max_cnt, int value)
{
	int middle;
	int min_temp = min_cnt;
	int max_temp = max_cnt;
	while(min_temp <= max_temp)
	{
		middle = (min_temp + max_temp) / 2;
		if(a[middle] > value)//����м�ֵ����value����ôvalueһ����min_temp - middle֮��
		{
			max_temp = middle - 1;
		}
		else if(a[middle] < value)//����м�ֵС��value����ôvalueһ����middle - max_temp֮��
		{
			min_temp = middle + 1;
		}
		else//middleֱ�ӵ���value
		{
			return middle;
		}
	}

	//���һֱû�ҵ�
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

