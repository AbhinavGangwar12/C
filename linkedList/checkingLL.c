#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
}*ele;

void create(int a[],int size){
    struct node *tmp,*latest;
    ele = (struct node *)malloc(sizeof(struct node));
    ele->data = a[0];
    ele->next = NULL;
    latest = ele;
    for(int i=1;i<size;i++){
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = a[i];
        tmp->next = NULL;
        latest->next = tmp;
        latest = tmp;
    }
    printf("\nList created.\n");
}

void checkSort(struct node *ptr){
    int buffer = INT_MIN;
    while(ptr!=NULL){
        if(buffer>ptr->data){
            printf("\nList is not sorted.\n");
            return;
        }
        buffer = ptr->data;
        ptr = ptr->next;
    }
    printf("\nList is sorted.\n");
}

int main(){
    int a[]={1,12,3,4,5,6,7};
    create(a,sizeof(a)/sizeof(int));
    checkSort(ele);
    printf("Program Exit!");
    return 0;
}