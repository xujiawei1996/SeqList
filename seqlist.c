#define _CRT_SECURE_NO_WARNINGS 1

#include "seqlist.h"

void PrintSeqList(PSeqList pSeqList)					//打印顺序表
{
	int i = 0;
	for (i = 0;i<pSeqList->size;i++)
	{
		printf("%d ",pSeqList->array[i]);
	}
	printf("\n");
}

int Empty(PSeqList pSeqList)							//判断是否为空
{
	assert(pSeqList);
	if (pSeqList->size <= 0)
	{
		printf("顺序表为空");
		return 1;
	}
	return 0;
}

void InitSeqList(PSeqList pSeqList)				//初始化顺序表
{
	memset(pSeqList,0,MAXSIZE*sizeof(DATATYPE));
	pSeqList->size = 0;
}

void PushBack(PSeqList pSeqList, DATATYPE data)		//尾插
{
	assert(pSeqList);
	if (pSeqList->size > MAXSIZE)
	{
		return;
	}
	pSeqList->array[pSeqList->size] = data;
	pSeqList->size++;
}

void PopBack(PSeqList pSeqList)						//尾删
{
	assert(pSeqList);
	if (Empty(pSeqList))
	{
		return;
	}
	pSeqList->size--;
}

void PushFront(PSeqList pSeqList, DATATYPE data)		//头插
{
	int idx = 0;;
	assert(pSeqList);
	if (pSeqList->size > MAXSIZE)
	{
		return;
	}
	for (idx = pSeqList->size;idx>=0;idx--)
	{
		pSeqList->array[idx+1] = pSeqList->array[idx];
	}
	pSeqList->array[0] = data;
	pSeqList->size++;
}

void PopFront(PSeqList pSeqList)						//头删
{
	int idx = 0;
	assert(pSeqList);
	if (Empty(pSeqList))
	{
		return;
	}
	for (idx;idx<=pSeqList->size;idx++)
	{
		pSeqList->array[idx] = pSeqList->array[idx+1];
	}
	pSeqList->size--;
}

void Insert(PSeqList pSeqList, int pos, DATATYPE data)	//插入
{
	int idx = 0;
	assert(pSeqList && pos>=0 && pos<=pSeqList->size);
	if (pSeqList->size > MAXSIZE)
	{
		return;
	}
	for(idx = pSeqList->size; idx >= pos; idx--)
	{
		pSeqList->array[idx+1] = pSeqList->array[idx];
	}
	pSeqList->array[pos] = data;
	pSeqList->size++;
}

void Erase(PSeqList pSeqList, int pos)					//删除某一个数
{
	int idx = 0;
	assert(pSeqList && pos>=0 && pos<=pSeqList->size);
	if (Empty(pSeqList))
	{
		return;
	}
	for(idx = pos; idx <= pSeqList->size; idx++)
	{
		pSeqList->array[idx] = pSeqList->array[idx+1];
	}
	pSeqList->size--;
}

int Find(PSeqList pSeqList, DATATYPE data)				//查找
{
	int idx = 0;
	assert(pSeqList);
	for (idx ; idx <= pSeqList->size ; idx++)
	{
		if (pSeqList->array[idx] == data)
		{
			return idx;
		}
	}
	return -1;
}

void Remove(PSeqList pSeqList, DATATYPE data)			//删除
{
	int i = 0;
	assert(pSeqList);
	if (Empty(pSeqList))
	{
		return;
	}
	if ((i=Find(pSeqList,data)) != -1)
	{
		Erase(pSeqList,i);
	}
	else
		printf("没有此数\n");
}

void RemoveAll(PSeqList pSeqList, DATATYPE data)		//删除选择的数
{
	/*int pos = -1;
	assert(pSeqList);
	if (Empty(pSeqList))
	{
		return;
	}
	while (-1 != (pos = Find(pSeqList,data)))
	{
		Erase(pSeqList,pos);
	}*/
	int icount = 0;
	int idx = 0;
	assert(pSeqList);
	if (Empty(pSeqList))
	{
		return;
	}
	for (idx;idx < pSeqList->size;idx++)
	{
		if (pSeqList->array[idx] == data)
		{
			icount++;
		}
		else
			pSeqList->array[idx-icount] = pSeqList->array[idx];
	}
	pSeqList->size -= icount;
}

void BubbleSort(PSeqList pSeqList)						//冒泡排序
{
	int i = 0;
	int j = 0;
	int flag = 1;
	assert(pSeqList);
	for (j = 0;j<pSeqList->size-1;j++)
	{
		flag = 1;
		for (i = 0;i<pSeqList->size-1-j;i++)
		{
			if (pSeqList->array[i] > pSeqList->array[i+1])
			{
				DATATYPE temp = pSeqList->array[i];
				pSeqList->array[i] = pSeqList->array[i+1];
				pSeqList->array[i+1] = temp;
				flag = 0;
			}
		}
		if (flag)
		{
			return;
		}
	}
}

void SelectSort(PSeqList pSeqList)						//选择排序
{
	int i = 0;
	int j = 0;
	int min = 0;
	assert(pSeqList);
	for (i = 0;i<pSeqList->size-1;i++)
	{
		min = i;
		for (j = i+1;j<pSeqList->size;j++)
		{
			if (pSeqList->array[min] > pSeqList->array[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			DATATYPE temp = pSeqList->array[min];
			pSeqList->array[min] = pSeqList->array[i];
			pSeqList->array[i] = temp;
		}
	}
}

int BinarySearch(PSeqList pSeqList, DATATYPE data)	//二分查找
{
	int i = 0;
	int start = 0;
	int end = pSeqList->size;
	int mid = (start+end)/2;
	SelectSort(pSeqList);
	printf("排序后如下：\n");
	PrintSeqList(pSeqList);
	for (i = 0;i<sqrt(pSeqList->size);i++)
	{
		if (pSeqList->array[mid] < data)
		{
			start = mid;
			mid = (start+end)/2;
		}
		else if (pSeqList->array[mid] > data)
		{
			end = mid;
			mid = (start+end)/2;
		}
		else
			return mid;	
	}
	return -1;
}