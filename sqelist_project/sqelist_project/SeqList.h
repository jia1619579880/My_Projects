//
//  seqList.h
//  sqelist_project
//
//  Created by Oliver Dai on 7/2/22.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
typedef int SLDataType;

typedef struct sl{
    SLDataType *num;
    int size;
    int capacity;
}SL;

enum OPTIONS{
    EXIT,
    PUSHBACK,
    POPBACK,
    PUSHFRONT,
    POPFRONT,
    PRINT,
    DESTORY,
    FIND,
    INTSERT,
    ERASE
};
void SeqListPrint(SL* ps);
void SeqListInit(SL* ps);
void SeqListDestory(SL* ps);

void CheckCapacity(SL* ps);
void SeqListPushBack(SL* ps,SLDataType n);
void SeqListPopBack(SL* ps);
void SeqListPushFront(SL* ps,SLDataType n);
void SeqListPopFront(SL* ps);

//找到了返回x对下标，没找到返回-1
int SeqListFind(SL* ps,SLDataType n);
//指定下标位置插入
void SeqListInsert(SL* ps,int pos,SLDataType n);
//指定下标位置删除
void SeqListErase(SL* ps,int pos);


