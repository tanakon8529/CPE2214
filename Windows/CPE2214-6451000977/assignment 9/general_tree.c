#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max_node 10000

typedef struct list_node *plistnode;
typedef struct tree_node tree_array;
struct list_node
{
    int data;
    plistnode pnext;
};

struct tree_node{
    char label[200];
    plistnode pchildlist;
    int parent_index;
};

void initial_tree(int max_size, tree_array treeA[]);
void travel_list(plistnode plist);
plistnode add_list(int data, plistnode plist);
plistnode create_node(void);
plistnode delete_list(plistnode plist);

int main()
{
    int i =0,  j=0, k=0;
    tree_array treeA[12];
    initial_tree(12, treeA);

    // q0-10 
    for (i = 0; i < 11; i++)
    {
        add_list(i, treeA[j].pchildlist);
        j++;
    }

    // q0
    for (i = 0; i < 6; i++)
    {
        j = 0;
        add_list(i, treeA[j].pchildlist);
    }

    // q5
    for (i = 0; i < 6; i++)
    {
        j = 5;
        add_list(i, treeA[j].pchildlist);
    }

    delete_list(treeA[5].pchildlist);

    for (i = 0; i < 12; i++)
    {
        printf("q%d -> ", i);
        travel_list(treeA[i].pchildlist);
        printf("\n");
    }
}

void initial_tree(int max_size, tree_array treeA[])
{
    int i = 0;
    for (i = 0; i < max_size;i++)
    {
        treeA[i].pchildlist = create_node();
        treeA[i].parent_index = -1;
    }
}

void travel_list(plistnode plist)
{
    plistnode ptravel;
    ptravel = plist->pnext;
    while(ptravel!=NULL)
    {
        printf("|%6.4d|", ptravel->data);
        ptravel = ptravel->pnext;
    }
}

plistnode create_node(void)
{
    plistnode pnew;
    pnew = (plistnode)malloc(sizeof(struct list_node));
    pnew->data = -99999;
    pnew->pnext = NULL;
    return pnew;
}

plistnode add_list(int data, plistnode plist)
{
    plistnode pnew;
    pnew = create_node();
    if (pnew != NULL)
    {
        pnew->data = data;
        pnew->pnext = plist->pnext;
        plist->pnext = pnew;
    }
    return pnew;
}

plistnode delete_list(plistnode plist)
{
    plistnode pnew;

    plist->pnext = pnew;

    return pnew;
}
