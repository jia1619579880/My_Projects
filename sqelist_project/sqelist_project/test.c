//
//  main.c
//  sqelist_project
//
//  Created by Oliver Dai on 7/2/22.
//
/*
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
 */
#include <stdio.h>
#include "SeqList.h"
void SeqListTest1(void)
{
    SL sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl, 0);
    SeqListPushBack(&sl, 1);
    SeqListPushBack(&sl, 2);
    SeqListPushBack(&sl, 3);
    SeqListPushBack(&sl, 4);
    SeqListInsert(&sl,1,0);
    SeqListErase(&sl,0);
    SeqListPrint(&sl);
}

void menu(void)
{
    printf("***1. PUSHBACK    2. POPBACK  *******\n");
    printf("***3. PUSHFRONT   4. POPFRONT *******\n");
    printf("***5. PRINT       6. DESTORY  *******\n");
    printf("***7. FIND        8. INSERT   *******\n");
    printf("***9. ERASE       0. EXIT     *******\n");
}

int main(int argc, const char * argv[])
{
    SL sl;
    SeqListInit(&sl);
    int input,num,pos;
    do
    {
        menu();
        printf("Input your choise:>");
        scanf("%d",&input);
        switch(input)
        {
            case PUSHBACK:
                printf("input number:>");
                scanf("%d",&num);
                SeqListPushBack(&sl, num);
                break;
            case POPBACK:
                SeqListPopBack(&sl);
                break;
            case PUSHFRONT:
                printf("input number:>");
                scanf("%d",&num);
                SeqListPushFront(&sl, num);
                break;
            case POPFRONT:
                SeqListPopFront(&sl);
                break;
            case PRINT:
                SeqListPrint(&sl);
                break;
            case DESTORY:
                SeqListDestory(&sl);
                break;
            case FIND:
                printf("Input number:>");
                scanf("%d",&num);
                pos = SeqListFind(&sl, num);
                printf("%d\n",pos);
                break;
            case INTSERT:
                printf("Input position:>");
                scanf("%d",&pos);
                printf("Input number:>");
                scanf("%d",&num);
                SeqListInsert(&sl, pos, num);
                break;
            case ERASE:
                printf("Input position:>");
                scanf("%d",&pos);
                SeqListErase(&sl, pos);
                break;
        }
    }while(input);
    
    return 0;
}
