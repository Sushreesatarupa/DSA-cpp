#include<stdio.h>
#include<stdlib.h> 
/* Function to print reverse of the passed string */
char *reverse(char *str)
{
static int i = 0;
    static char rev[100];
    if(*str)
    {
        reverse(str+1);
        rev[i++] = *str;
    }
    return rev;     
}
 
/* Driver program to test above function */
int main()
{
    char a[100];
    printf("Input string \n");
    gets(a);
    char *r=reverse(a);
    puts(r);
    return 0;
}
