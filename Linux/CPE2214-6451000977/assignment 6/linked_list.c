#include<stdio.h>
#include<stdlib.h>

typedef struct listnode * plistnode;
struct listnode
{
    float data;
    plistnode pnext;
};

plistnode create_node(void);
plistnode add_list(float data, plistnode plist);
void travel_list(plistnode plist);

int main() 
{
    plistnode plist1;
    int count;
    plist1 = create_node();

    for(count = 0; count < 20; count++)
    {
        add_list(count, plist1);
    }

    travel_list(plist1);
    return 0;
}

plistnode create_node(void)
{
    plistnode pnew;
    pnew = (plistnode)malloc(sizeof(struct listnode));
    pnew->data = -99999;
    pnew->pnext = NULL;
    return pnew;
}

plistnode add_list(float data, plistnode plist)
{
    plistnode pnew;
    pnew = create_node();
    if(pnew != NULL)
    {
        pnew->data = data;
        pnew->pnext = plist->pnext;
        plist->pnext = pnew;
    }
    return pnew;
}

void travel_list(plistnode plist)
{
    plistnode ptravel;
    ptravel = plist;
    while (ptravel != NULL)
    {
        printf("|%15p|%15.4f|%15p|\n", ptravel, ptravel->data, ptravel->pnext);
        ptravel = ptravel ->pnext;
    }
}