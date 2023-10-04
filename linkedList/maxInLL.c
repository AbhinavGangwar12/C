#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*first;
int maximum(struct node *list){
    int maximum = INT_MIN;
    while(list){
        if(maximum<list->data)maximum=list->data;
        list=list->next;//TAKING THE POINTER TO TE NEXT NODE
    }
    return maximum;
}
void createLL(int a[],int size){
    first = (struct node*)malloc(size*sizeof(struct node));
    struct node *tmp,*latest;
    first->data = a[0];
    first->next = NULL;
    latest = first;
    for(int i=1;i<size;i++){
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = a[i];
        tmp->next = NULL;
        latest->next = tmp;
        latest = tmp;
    }
}
int main(){
    int arry[]={1,2,52,1,4,2,34,54,2,5,243},s=sizeof(arry)/sizeof(int);
    printf("\nprogram executed!");
    createLL(arry,s);
    printf("\n%d",maximum(first));
}