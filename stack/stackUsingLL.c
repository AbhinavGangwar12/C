#include<stdio.h>
#include<stdlib.h>
struct node{
    int val;
    struct node* ptr;
}*top;

void push(struct node *top){
    struct node *tmp;
    if(tmp==NULL)printf("Stack Overflow!");
    else {
        tmp = (struct node*)malloc(sizeof(struct node));
        scanf("%d",tmp->val);
        tmp->ptr = top;
        top = tmp;
    }
}
int pop(struct node *top){
    int x = -1;
    if(top->ptr==NULL)printf("Stack Underflow!"); 
    else {
        struct node* p=top;
        int x = p->val;
        top = top->ptr;
        free(p);
    }
    return x;
}
int peek(int pos){
    if(top==NULL){
        printf("Stack Underflow!");
        return -1;
    }
    else{
        struct node* tmp = top;
        for(int i = 0;i < pos-1 && tmp!=NULL;i++)tmp = tmp->ptr;
        if(tmp!=NULL)return tmp->val;
        else return -1;
    }
}
int stackTop(){
    if(top)return top->val;
    else return -1;
}
int main(){
    top = (struct node*)malloc(sizeof(struct node));
    top->ptr = NULL;
    return 0;
}