#include<stdio.h>
#define VERTICE 7
#define KNOWN 0
#define Dv 1
#define Pv 2

int WDgraph1[VERTICE][VERTICE] = {{0, 2, 10, 5, 0, 0, 0},
                                  {2, 0, 0, 2, 8, 0, 0},
                                  {10, 0, 0, 3, 0, 2, 0},
                                  {5, 2, 3, 0, 2, 1, 4},
                                  {0, 8, 0, 2, 0, 0, 2},
                                  {0, 0, 2, 1, 0, 0, 4},
                                  {0, 0, 0, 4, 2, 4, 0}};

int shortest_table_w[VERTICE][3] = {{0, 0, -1},
                                    {0, 10000, 0},
                                    {0, 10000, 0},
                                    {0, 10000, 0},
                                    {0, 10000, 0},
                                    {0, 10000, 0},
                                    {0, 10000, 0}};


void dijkstra(void)
{
    int i, j, minindex, mindv;
    while (1)
    {
        minindex = -1;
        mindv = 10000;
        for (i = 0; i < VERTICE; i++)
        {
            if ((shortest_table_w[i][KNOWN] == 0) && (shortest_table_w[i][Dv] < mindv))
            {
                mindv = shortest_table_w[i][Dv];
                minindex = i;
            }
        }
        if (minindex == -1)
        {
            break;
        }
        shortest_table_w[minindex][KNOWN] = 1;
        for (j = 0; j < VERTICE; j++)
        {
            if (WDgraph1[minindex][j] != 0)
            {
                if (shortest_table_w[j][KNOWN] != 1)
                {
                    if (shortest_table_w[minindex][Dv] + WDgraph1[minindex][j] < shortest_table_w[j][Dv])
                    {
                        shortest_table_w[j][Dv] = shortest_table_w[minindex][Dv] + WDgraph1[minindex][j];
                        shortest_table_w[j][Pv] = minindex;
                    }
                }
            }
        }
    }
}

int main(void)
{
    dijkstra();
    for (int i = 0; i < VERTICE;i++)
    {
        printf("V%d %d %d V%d\n", i+1, shortest_table_w[i][0], shortest_table_w[i][1], shortest_table_w[i][2]+1);
    }
    return 0;
}
