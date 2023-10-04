#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *nxt;
}*ele;
void appendLL(){
    int x;
    scanf("%d",&x);
    struct node *tmp,*latest;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->data=x;
    tmp->nxt=NULL;
    if(ele==NULL){
        ele = tmp;
        latest = tmp;
    }
    else {
        latest->nxt = tmp;
        latest = tmp;
    }
}
void displayLL(struct node *p){
    while(p){
        printf("%d ",p->data);
        p=p->nxt;
    }
}
int main(){
    printf("Enter number of elements to insert : ");
    int num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)appendLL();
    displayLL(ele);
    printf("\nExiting program!");
    return 0;
}