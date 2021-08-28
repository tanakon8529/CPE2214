#include <stdio.h>

// Exercise 3.3
int main(){
    int *pnum;
    int count, n, number;

    printf("Your size : ");
    scanf("%d", &n);

    pnum = (int)malloc(sizeof(int) * n);

    for (count = 0; count < n; count++){
        printf("Your number : ");
        scanf("%d", &pnum[count]);
    }

    for (count = 0; count < n; count++){
        printf("pnumi[%d] : %d \n", count, pnum[count]);
    }
}

// // Example 3.4 -39
// int main(){
//     int i = 0;
//     char *str = "Ramkhamhaeng Engineering";
//     char *dest;
//     dest = (char *)malloc(5);

//     for (i = 0; str[i] != '\0'; i++){
//         strncpy(dest, str + i, 3);
//         dest[3] = '\0';
//         printf("substring %d = %s\n", i, dest);
//     }
//     return 0;
// }

// // // Example 3.4 -41
// int main(){
//     int i = 0, n;
//     char *str = "Ramkhamhaeng Engineering";

//     printf("your size : ");
//     scanf("%d", &n);
//     char *dest;
//     dest = (char *)malloc(n);

//     for (i = 0; str[i] != '\0'; i++){
//         strncpy(dest, str+i, n);
//         dest[n] = '\0';
//         printf("substring %d = %s\n", i, dest);
//     }
//     return 0;
// }