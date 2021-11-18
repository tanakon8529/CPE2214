#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct binary_tree *pbi_tree;
struct binary_tree
{
    int number_of_node;
    int *tree_array;
};

pbi_tree create_binary_tree(int max_number);
int add_child(int data, pbi_tree bt);
int binary_seach(int data, pbi_tree bt);
int find_min(pbi_tree bt);
int find_max(pbi_tree bt);

int main()
{
    int i = 0, min = 0, max = 0;
    int count = 0, index = 0;
    pbi_tree pbt1;
    int num[12] = {15, 10, 20, 12, 8, 30, 17, 11, 18, 27};
    pbt1 = create_binary_tree(100);
    for (i = 0; i < 10;i++)
    {
        add_child(num[i], pbt1);
    }
    i = 0;
    while (count<pbt1->number_of_node)
    {
        if(pbt1->tree_array[i]!=-1)
        {
            count++;
        }
            printf("Array[%d] = %d\n", i, pbt1->tree_array[i]);
            i++;
    }
    index = binary_seach(18, pbt1);
    printf("index = %d\n", index);

    min = find_min(pbt1);
    max = find_max(pbt1);
    printf("Max value is %d \n", max);
    printf("Min value is %d \n", min);
    return 0;
}


pbi_tree create_binary_tree(int max_number)
{
    int i = 0;
    pbi_tree pbi_tree_new;
    pbi_tree_new = (pbi_tree)malloc(sizeof(struct binary_tree));
    pbi_tree_new->number_of_node = 0;
    pbi_tree_new->tree_array = (int*)malloc(sizeof(int)*max_number);

    for (i = 0; i < max_number;i++)
    {
        pbi_tree_new->tree_array[i] = -1;
    }
    return pbi_tree_new;
}

int add_child(int data, pbi_tree bt)
{
    int i = 0, index = 0, count = 0;
    while (count<=bt->number_of_node)
    {
        count++;
        if(data<bt->tree_array[i])
        {
            if(bt->tree_array[2*i]==-1)
            {
                bt->tree_array[2 * i] = data;
                bt->number_of_node++;
                index = 2 * i;
                break;
            }
            i = 2 * i;
        }
        else if(data>bt->tree_array[i])
        {
            if(bt->tree_array[(2*i)+1]==-1)
            {
                bt->tree_array[(2*i)+1] = data;
                bt->number_of_node++;
                index = 2 * i + 1;
                break;
            }
            i = (2 * i) + 1;
        }
        else
        {
            printf("thist data is already in bitree\n");
            break;
        }
    }
    return index;
}

int binary_seach(int data, pbi_tree bt)
{
    int i = 1, index = -1, step = 0;
    while (step<=bt->number_of_node)
    {
        step++;
        if(data<bt->tree_array[i])
        {
            if (bt->tree_array[2 * i] == -1)
                {
                    break;
                }
                i = 2 * i;
        }
        else if (data > bt->tree_array[i])
        {
            if (bt->tree_array[(2 * i) + 1] == -1)
            {
                break;
            }
            i = (2 * i) + 1;
        }
        else
        {
            index = i;
            printf("found %d at index %d in %d step\n", data, index, step);
            break;
        }
    }
    return index;
}


int find_min(pbi_tree bt)
{
    int i = 1, index = -1, step = 0;
    int res = 0;
    while (step <= bt->number_of_node)
    {
        step++;
        res = bt->tree_array[i];

        if (res == -1)
        {
            break;
        }
        i = 2 * i;
    }
    return res = bt->tree_array[i/2];
}

int find_max(pbi_tree bt)
{
    int i = 1, index = -1, step = 0;
    int res = 0;
    while (step <= bt->number_of_node)
    {
        step++;
        res = bt->tree_array[i];

        if (res == -1)
        {
            break;
        }
        i = (2*i) + 1;
    }
    return res = bt->tree_array[i/2];
}