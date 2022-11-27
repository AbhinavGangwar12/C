#include<stdio.h>
int findHCF(int,int);
int main(){
    int num1,num2,container;
    printf("Enter two numbers : ");
    scanf("%d\t", &num1);
    scanf("%d", &num2);
    container = findHCF(num1,num2);
    printf("The HCF of given numbers is %d", container);
    return 0;  
}
int findHCF(int num1,int num2){
    while(num1 != num2)
    {
        if (num1 > num2)
        {
            return findHCF((num1 - num2), num2);
        }
        else
            return findHCF(num1,(num2-num1)); 
    }
    return num2;
}