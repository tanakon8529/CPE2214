#include<stdio.h>

// --------------------------------------------------------------------------------
// Example 3.3 + Exercise 3.1
#define STUDENT_NUM 100

int main()
{
    int count = 0, i = 0;
    float score[STUDENT_NUM][5];
    FILE *fpinput;
    fpinput = fopen("Example3.3CPE2214.csv", "r");

    while (count != EOF)
    {
        count = fscanf(fpinput, "%f , %f , %f, %f\n", &score[i][0], &score[i][1], &score[i][2], &score[i][3]);
        score[i][3] = score[i][0] + score[i][1] + score[i][2];
        if(count == EOF)
            break;

        printf("%f %f %f %f\n", score[i][0], score[i][1], score[i][2], score[i][3]);
        i++;
    }
    return 0;
}

// // --------------------------------------------------------------------------------
// // Example 3.2
// char *str = "Ramkhamhaeng engineering";
// int amount_e = 0, amount_str = 0;

// int main()
// {

//     for (int count = 0; str[count] != '\0'; count++)
//     {
//         if(str[count] == 'e')
//         {
//             amount_e++;
//         }
//         amount_str++;
//     }

//     printf("amount character is : %d\n amount 'e' is : %d\n", amount_str, amount_e);
//     return 0;

// }

// // --------------------------------------------------------------------------------
// // Example 3.1
// int num[10] = {5, 3, 9, 2, 7, 10, 6, 8, 4, 1};

// int size = 10, location = 0, max;

// int main()
// {

//     // Exemple 3.1
//     for (int count = 1; count < size; count++)
//     {
//         if (num[count] > num[location])
//         {
//             location = count;
//         }
//     }

//     printf("Maximum location : %d\n Its value is : %d\n", location+1, num[location]);
//     return 0;
// }
