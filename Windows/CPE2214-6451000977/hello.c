#include<stdio.h>
#include<string.h>


int main(){
    char *str1 = "ru engineering"; // 14 character
    int i = 0, count = 0;
    char ch = 'e';

                                    // loop in 14 character = 1*14 ut
    while (str1[i] != '\0')         // loop in str1 is not null
    {                               // operator '==' = 1 ut
        if(str1[i] == ch)           // if str1[i] == 'e'
        {                           // '++' = 1 ut (e = 3) 
            count++;                // found 'e' add count
        }
                                    // operator '++' = 1 ut
        i++;                        // every found add i
    }
    printf("Found %c = %d \n", ch, count);
    return 0;
    
}