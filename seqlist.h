#define _CRT_SECURE_NO_WARNINGS 1

#include<windows.h>
#include <assert.h>
#include <stdio.h>
#include <math.h>

#define MAXSIZE 10
typedef int DATATYPE;

typedef struct SeqList
{
	DATATYPE array[MAXSIZE];
	DATATYPE size;
}SeqList,*PSeqList;

void InitSeqList(PSeqList pSeqList);					//初始化顺序表
void PushBack(PSeqList pSeqList, DATATYPE data);		//尾插
void PopBack(PSeqList pSeqList);						//尾删
void PushFront(PSeqList pSeqList, DATATYPE data);		//头插
void PopFront(PSeqList pSeqList);						//头删
void Insert(PSeqList pSeqList, int pos, DATATYPE data);	//插入
void Erase(PSeqList pSeqList, int pos);					//删除某一个数
int Find(PSeqList pSeqList, DATATYPE data);				//查找
void Remove(PSeqList pSeqList, DATATYPE data);			//删除一个数
void RemoveAll(PSeqList pSeqList, DATATYPE data);		//删除选择的数
void BubbleSort(PSeqList pSeqList);						//冒泡排序
void SelectSort(PSeqList pSeqList);						//选择排序
int BinarySearch(PSeqList pSeqList, DATATYPE data);	//二分查找
int Empty(PSeqList pSeqList);							//判断是否为空
void PrintSeqList(PSeqList pSeqList);					//打印顺序表


