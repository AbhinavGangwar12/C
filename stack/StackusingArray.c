#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size,top,*arr;
};
void createStack(struct stack *arry){
    printf("Enter the size of stack : ");
    scanf("%d", &arry->size);
    arry->top = -1;
    arry->arr = (int)malloc(arry->size*sizeof(int));
    printf("Stack is created");
}
void push(struct stack *arry,int vlu){
    if(arry->top == arry->size-1)printf("Stack Overflow!");
    else{
        arry->top++;
        arry->arr[arry->top] = vlu;
        printf("Element inserted");
    }
}
int pop(struct stack *arry){
    int x=-1;
    if(arry->top == -1)printf("Stack Underflow!");
    else{
        x = arry->arr[arry->top];
        arry->arr[arry->top] = 0;
        arry->top--;
        printf("Element poped!");
    }
    return x;
}
int peek(struct stack *arry,int pos){
    int x = -1;
    if(pos < 0 || pos > arry->size)printf("Invalid Position!");
    else x = arry->arr[arry->top - pos + 1];
    return x;
}

int main(){
    struct stack s;

    return 0;
}