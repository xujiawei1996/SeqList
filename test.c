#define _CRT_SECURE_NO_WARNINGS 1

#include<windows.h>
#include "seqlist.h"

void test1()
{
	SeqList seqlist;
	InitSeqList(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PrintSeqList(&seqlist);
	/*PopBack(&seqlist);
	PopBack(&seqlist);
	PopBack(&seqlist);*/
	PushFront(&seqlist,0);
	PrintSeqList(&seqlist);
	PopFront(&seqlist);
	PrintSeqList(&seqlist);
}

void test2()
{
	SeqList seqlist;
	InitSeqList(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PushBack(&seqlist,2);
	PushBack(&seqlist,2);
	PushBack(&seqlist,5);
	PushBack(&seqlist,2);
	PrintSeqList(&seqlist);
	/*Insert(&seqlist,1,2);
	PrintSeqList(&seqlist);
	Erase(&seqlist,1);
	PrintSeqList(&seqlist);*/
	//printf("%d\n",(Find(&seqlist,3)));
	//Remove(&seqlist,3);
	RemoveAll(&seqlist,2);
	PrintSeqList(&seqlist);
}

void test3()
{
	SeqList seqlist;
	InitSeqList(&seqlist);
	PushBack(&seqlist,1);
	PushBack(&seqlist,2);
	PushBack(&seqlist,3);
	PushBack(&seqlist,4);
	PushBack(&seqlist,2);
	PushBack(&seqlist,2);
	PushBack(&seqlist,5);
	PrintSeqList(&seqlist);
	//BubbleSort(&seqlist);
	//SelectSort(&seqlist);
	printf("%d\n",BinarySearch(&seqlist,0));
	//PrintSeqList(&seqlist);


}

int main()
{
	//test1();
	//test2();
	test3();
	system("pause");
	return 0;
}
