#include<stdio.h>
int sum(int);
int main(){
    int input;
    printf("Enter a number : ");
    scanf("%d", &input);
    printf("The sum of the digits in this number is %d", sum(input));
    return 0;
}
int sum(int input){
    if (input%10 == 0)
    {
        return 0;
    }
    return ((input%10) + (sum(input/10)));
    
}
