#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
#define MAX_NAME 10
#define MAX_GENDER 6
#define MAX_TELE 11
#define MAX_ADDR 20
/*Add              2. del   *******\n");
    printf("*******3. search           4. modify*******\n");
    printf("*******5. show             6. sort*/
enum Option
{
    EXIT,
    ADD,
    DELETE,
    SEARCH,
    MODIFY,
    SHOW,
    SORT,
};

struct PeoInfo{
    char name[MAX_NAME];
    char gender[MAX_GENDER];
    int age;
    char tele[MAX_TELE];
    char addr[MAX_ADDR];
};

struct contact{
    struct PeoInfo data[MAX];
    int size;
}con;
//init the struct type
void InitContact(struct contact* ps);
//add a contact
void AddContact(struct contact* ps);
//show the contact
void ShowContact(const struct contact* ps);
//delete the user choose contact
void DelContact(struct contact* ps);
//search and print user's input name
void SearchContact(struct contact* ps);
//modify user's info
void ModifyContact(struct contact* ps);
//do a sort of the contact
void SortContact(struct contact* ps);
