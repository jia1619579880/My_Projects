//
//  SeqList.c
//  sqelist_project
//
//  Created by Oliver Dai on 7/2/22.
//

#include "SeqList.h"

//打印函数
void SeqListPrint(SL* ps)
{
    int i;
    if(ps->num==NULL)
    {
        printf("It's empty!\n");
        return;
    }
    for(i=0;i<ps->size;i++)
    {
        printf("%d ",ps->num[i]);
    }
    printf("\n");
}
//数据初始化
void SeqListInit(SL* ps)
{
    ps->num=0;
    ps->size=ps->capacity=0;
}
//数据销毁
void SeqListDestory(SL* ps)
{
    free(ps->num);
    ps->num=NULL;
}
//数据空间检查
void CheckCapacity(SL* ps)
{
    if(ps->size==ps->capacity)
    {
        int newcapacity = ps->capacity==0 ? 4:ps->capacity*2;  //如果空间为0默认初始化为4，否则新的空间为原来的两倍
        SLDataType* tmp=(SLDataType*)realloc(ps->num,newcapacity*sizeof(SLDataType));  //新的空间赋值到tmp上
        if(tmp==NULL)           //如果tmp为空指针则为扩展空间失败
        {
            printf("relloc failed!\n");
            exit(-1);           //-1为意外退出
        }
        ps->num=tmp;            //赋值
        ps->capacity=newcapacity;
    }
}

void SeqListPushBack(SL* ps,SLDataType n)
{
    CheckCapacity(ps);
    ps->num[ps->size]=n;
    ps->size++;
}

void SeqListPopBack(SL* ps){
    //暴力方法
    assert(ps->size>0);
    ps->size--;
}

void SeqListPushFront(SL* ps,SLDataType n)
{
    CheckCapacity(ps);
    int end = ps->size-1;
    while(end>=0)
    {
        ps->num[end+1]=ps->num[end];
        end--;
    }
    end++;
    ps->num[0]=n;
    //增加元素
    ps->size++;
}

void SeqListPopFront(SL* ps)
{
    int begin=0;
    while(begin<=ps->size)
    {
        ps->num[begin]=ps->num[begin+1];
        begin++;
    }
    ps->size--;
}

int SeqListFind(SL* ps,SLDataType n)
{
    for(int i=0;i<ps->size;i++)
    {
        if(ps->num[i]==n)
        {
            return i;
        }
    }
    return -1;
}

void SeqListInsert(SL* ps,int pos,SLDataType n)
{
    CheckCapacity(ps);
    int end=ps->size-1;
    while(end>=pos)
    {
        ps->num[end+1]=ps->num[end];
        end--;
    }
    end++;
    ps->num[pos]=n;
    ps->size++;
}
void SeqListErase(SL* ps,int pos)
{
    while(pos<=ps->size)
    {
        ps->num[pos]=ps->num[pos+1];
        pos++;
    }
    ps->size--;
}

