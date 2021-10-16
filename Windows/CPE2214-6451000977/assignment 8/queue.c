#include<stdio.h>
#include<stdlib.h>

typedef struct queue_node *pquene;
struct queue_node
{
    int size;
    int capacity;
    int front;
    int rear;
    float *p_array;
};

pquene create_queue(int max);
int enqueue(pquene pq, float data);
int dequeue(pquene pq);

int main()
{
    pquene pq1;
    int i, j, count;
    pq1 = create_queue(10);

    for (count = 1; count < 11; count++)
    {
        enqueue(pq1, count);
    }

    for (j = 0; j < 4; j++)
    {
        dequeue(pq1);
    }

    for (count = 20; count < 22; count++)
    {
        enqueue(pq1, count);
    }

    for (i = 0; i < 10; i++)
    {
        printf("pq[%d] = %f\n", i, pq1->p_array[i]);
    }

    return 0;
}

pquene create_queue(int max)
{
    pquene pq1;
    pq1 = (pquene)malloc(sizeof(struct queue_node));
    pq1->size = 0;
    pq1->capacity = max;
    pq1->front = 0;
    pq1->rear = -1;
    pq1->p_array = (float*)malloc(sizeof(float)*max);
    return pq1;
}

int enqueue(pquene pq, float data)
{
    int new_rear = 0, can_enqueue = -1;
    if(pq->size < pq->capacity)
    {
        new_rear = (pq->rear+1)%pq->capacity;
        pq->rear = new_rear;
        pq->size++;
        pq->p_array[new_rear] = data;
        can_enqueue = new_rear;
    }
    return can_enqueue;
}

int dequeue(pquene pq)
{
    int can_dequeue = -1;
    int new_front = 0;
    if(pq->size>0)
    {
        new_front = (pq->front+1)%pq->capacity;
        pq->front = new_front;
        pq->size--;
        can_dequeue = new_front;
    }
    return can_dequeue;
}