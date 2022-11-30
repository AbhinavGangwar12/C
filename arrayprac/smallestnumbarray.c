#include<stdio.h>
int main(){
    int a[10];
    for (int i = 0; i < 10; i++)
    {
        printf("Enter element %d : ",i+1);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        if (a[0]>a[i])
        {
            a[0] = a[i];
        }
    }
    printf("The smallest number is %d", a[0]);
}