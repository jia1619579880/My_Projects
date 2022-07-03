
#include "Contact.h"
//findbyname
int Findbyname(struct contact* ps,char name[MAX_NAME])
{
    int i;
    for(i=0;i<ps->size;i++)
    {
        if(strcmp(ps->data[i].name,name)==0)
        {
            return i;
        }
    }
    return -1;//Not Find
}
//init everything is 0
void InitContact(struct contact* ps)
{
    memset(ps->data,0,sizeof(ps->data));
    ps->size=0;
}
//add contact
void AddContact(struct contact* ps)
{
    if(ps->size==MAX)
    {
        printf("Your contact is full!\n");
    }
    else
    {
        printf("input your name:");
        scanf("%s",ps->data[ps->size].name);
        printf("input your gender:");
        scanf("%s",ps->data[ps->size].gender);
        printf("input your age:");
        scanf("%d",&(ps->data[ps->size].age));
        printf("input your telephone number:");
        scanf("%s",ps->data[ps->size].tele);
        printf("input your address:");
        scanf("%s",ps->data[ps->size].addr);
        
        ps->size++;
        printf("Added success!\n\n");
        printf("you have added %d contact\n",ps->size);
    }
}

void ShowContact(const struct contact* ps)
{

    if(ps->size==0)
    {
        printf("Your contact is empty!\n");
    }
    else
    {
        int i;
        printf("%-10s\t%-10s\t%-4s\t%-20s\t%-20s\n","Name","Gender","Age","Telephone","Address");
        for(i=0;i<ps->size;i++)
        {
            printf("%-10s\t%-10s\t%-4d\t%-20s\t%-20s",
            ps->data[i].name,
            ps->data[i].gender,
            ps->data[i].age,
            ps->data[i].tele,
            ps->data[i].addr
            );
            printf("\n");
        }
    }
}

void DelContact(struct contact* ps)
{
    char name[MAX_NAME];
    printf("input the name you want to delete:>");
    scanf("%s",name);
    int pos=Findbyname(ps,name);
    if(pos==-1)
    {
        printf("The contact not found!\n");
    }
    else
    {
        for(int i=pos;i<ps->size-1;i++)
        {
            ps->data[i]=ps->data[i+1];
        }
        ps->size--;
        printf("Delete Success!\n");
    }
}

void SearchContact(struct contact* ps)
{
    char name[MAX_NAME];
    printf("input the name you want to search:>");
    scanf("%s",name);
    int pos=Findbyname(ps,name);
    if(pos==-1)
    {
        printf("Name not Found \n");
    }
    else
    {
        //print user's name and info
        printf("%-10s\t%-10s\t%-4d\t%-20s\t%-20s\n",
            ps->data[pos].name,
            ps->data[pos].gender,
            ps->data[pos].age,
            ps->data[pos].tele,
            ps->data[pos].addr
            );
            printf("\n");
            printf("Search Success!\n");
    }
}

void ModifyContact(struct contact* ps)
{
    char name[MAX_NAME];
    printf("input the name you want to modify:>");
    scanf("%s",name);
    int pos=Findbyname(ps,name);
    if(pos==-1)
    {
        printf("Name not Found \n");
    }
    else
    {
        printf("input your name:");
        scanf("%s",ps->data[pos].name);
        printf("input your gender:");
        scanf("%s",ps->data[pos].gender);
        printf("input your age:");
        scanf("%d",&(ps->data[pos].age));
        printf("input your telephone number:");
        scanf("%s",ps->data[pos].tele);
        printf("input your address:");
        scanf("%s",ps->data[pos].addr);
        printf("Modify success!\n");
    }
}
//this is the qsort function.
//void qsort(void *base, size_t nitems, size_t size, int (*compar)(const void *, const void*))

int cmpbyname(const void *a,const void *b)
{
    return strcmp(((struct PeoInfo*)a)->name,((struct PeoInfo*)b)->name);
}

void SortContact(struct contact* ps)
{
    qsort(ps->data,ps->size,sizeof(ps->data[0]),cmpbyname);
    int i=0;
    printf("%-10s\t%-10s\t%-4s\t%-20s\t%-20s\n","Name","Gender","Age","Telephone","Address");
    for(i=0;i<ps->size;i++)
    {
        printf("%-10s\t%-10s\t%-4d\t%-20s\t%-20s",
        ps->data[i].name,
        ps->data[i].gender,
        ps->data[i].age,
        ps->data[i].tele,
        ps->data[i].addr
        );
        printf("\n");
    }
}
