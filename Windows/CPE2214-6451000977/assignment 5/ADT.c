#include <stdio.h>
#include <stdlib.h>

typedef struct data vector;
struct data
{
    int size;
    int max;
    float *p_array;
};

vector create_vector(int max_size);
int add_list(vector *v, float data);
float last_element(vector *v, int size);
int delete (vector *v, int rm_pos, int size);
int is_emyty(vector *v, int size);

int main()
{
    vector v1;

    int max = 0, size_data = 0, count = 0, emyty = 0, last = 0, rm_pos = 0;
    float data = 0.00;

    // create file .txt and open f'write
    FILE *fpoutput;
    fpoutput = fopen("number data.txt", "w");

    // input size of array
    printf("Please type maximum size of array : \n");
    scanf("%d", &max);

    // input size of data
    printf("How many data : \n");
    scanf("%d", &size_data);

    // input data maximun size of data
    v1 = create_vector(size_data);
    printf("You want to add %d data \n", size_data);
    for (count = 0; count < size_data; count++)
    {
        printf("Please type data number %d and press Enter \n", count + 1);
        scanf("%f", &data);
        add_list(&v1, data);
    }

    // output data
    printf("You add data complete");
    printf("Size of array = %d\n", v1.size);
    printf("Maximum of array = %d\n", v1.max);
    printf("You add : ");
    for (count = 0; count < v1.size; count++)
    {
        printf("%.2f ", v1.p_array[count]);
        fprintf(fpoutput, "%.2f\n", v1.p_array[count]);
    }

    // check emyty
    is_emyty(&v1, size_data);

    // delete data
    rm_pos = size_data;
    printf("\nDelete last element : %.2f", v1.p_array[size_data-1]);
    delete (&v1,  rm_pos, size_data);

    // last element
    last_element(&v1 ,size_data-2);

    return 0;
}

vector create_vector(int max_size)
{
    vector v;
    v.max = max_size;
    v.size = 0;
    v.p_array = (float *)malloc(sizeof(int) * max_size);
    return v;
}

int add_list(vector *v, float data)
{
    int add_index = 0, can_add = -1;
    if (v->max > v->size)
    {
        add_index = v->size;
        v->p_array[add_index] = data;
        v->size++;
        can_add = add_index;
    }
    return can_add;
}

int is_emyty(vector *v, int size)
{
    int turn = 0;

    if (size <= 0)
    {
        return printf("\nis_emyty : %d", turn+1);
    }
    else
    {
        return printf("\nis_emyty : %d", turn);
    }

}

int delete(vector *v, int rm_pos, int size)
{
    int i;

    if (rm_pos < 0 || rm_pos > size)
    {
        printf("\nInvalid position! Please enter position between 1 to %d", size);
        return 0;
    }
    else
    {
        for (i = rm_pos - 1; i < size - 1; i++)
        {
            v->p_array[i] = v->p_array[i + 1];
        }

        size--;

        printf("\nElements of array after delete are : ");
        for (i = 0; i < size; i++)
        {
            printf("%.2f ", v->p_array[i]);
        }
        return 1;
    }
}

float last_element(vector *v, int size)
{
    if(size < 0)
    {
        int element = -99999;
        return printf("\nlast_element %d", element);
    }
   else
    {
        printf("\nlast_element %.2f", v->p_array[size]);
    }

}
