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

void removeLL(struct node *ptr){
    struct node *a,*b;
    a = ptr;
    b = ptr->next;
    while(b!=NULL){
        if(a->data!=b->data){
            a = b;
            b = b->next;
        }
        else {
            a->next = b->next;
            free(b);
            b = a->next;
        }
    }
    printf("\nList is amended.\n");
}
void print(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}
int main(){
    int a[]={1,3,3,4,4,4,7};
    create(a,sizeof(a)/sizeof(int));
    removeLL(ele);
    print(ele);
    printf("Program Exit!");
    return 0;
}