#include<stdio.h>
#include<string.h>


int main(){
    char *str1 = "ru engineering";
    int i = 0, count = 0;
    char ch = 'e';

    while (str1[i] != '\0')
    {
        if(str1[i] == ch)
        {
            count++;
        }
        i++;
    }
    printf("Found %c = %d \n", ch, count);
    return 0;
    
}