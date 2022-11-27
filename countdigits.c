#include<stdio.h>
int main(){
    int input,i, divisor=10,x;
    printf("Enter a number : ");
    scanf("%d", &input);
    for (i = 1; i < input; i++)
    {
        x = input/divisor;
        input = x*divisor;
        divisor = divisor*10;
        if (x<1)
        {
            break;
        }
    }
    printf("Your number contains %d digits", i);
}