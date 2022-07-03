
#include "Contact.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
make a contact system;
1. Add    2. del
3. search 4. modify
5. show   6.sort
0.exit
*/
void menu(void)
{
    printf("*******1. Add              2. del   *******\n");
    printf("*******3. search           4. modify*******\n");
    printf("*******5. show             6. sort  *******\n");
    printf("******************0. exit******************\n");
}
int main() {
    struct contact con;
    //init contact:
    InitContact(&con);
    int input=0;
    do
    {

        menu();
        printf("enter your choice:>");
        scanf("%d",&input);
        switch(input)
        {
            case ADD:AddContact(&con);break;
            case DELETE:DelContact(&con);break;
            case SEARCH:SearchContact(&con);break;
            case MODIFY:ModifyContact(&con);break;
            case SHOW:ShowContact(&con);break;
            case SORT:SortContact(&con);break;
            case EXIT:printf("exit success!\n");break;
            default:printf("enter error!please try again!\n");break;
        }
    }while(input);
    return 0;
}
