#include<stdio.h>
int main(){
    int a[10],x=0,y;
    for (int i = 0; i < 10; i++)
    {
        printf("Element %d :",i);
        scanf("%d", &a[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        for(y = 0;y<=a[i];y++){
            if(y = a[i]){
                x = y;
            }
        }
    }
    printf("The greatest number is %d ", x);   
}