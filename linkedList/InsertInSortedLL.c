#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *nxt;
}*head;
void createLL(){
    printf("Enter number of elements you want to enter : ");
    int num;
    scanf("%d",&num);
    printf("Enter sorted elements : \n");
    struct node *latest,*tmp;
    head = (struct node*)malloc(sizeof(struct node));
    scanf("%d",&head->data);
    head->nxt=NULL;
    latest = head;
    for(int i=1;i<num;i++){
        tmp = (struct node*)malloc(sizeof(struct node));
        scanf("%d",&tmp->data);
        tmp->nxt = NULL;
        latest->nxt=tmp;
        latest = tmp;
    }
    printf("\nList created.\n");
}
void insert(){
    printf("Enter element to insert : ");
    int key;
    scanf("%d",&key);
    if(head->data > key){
        struct node *tmp;
        tmp = (struct node*)malloc(sizeof(struct node));
        tmp->data = key;
        tmp->nxt = head;
        head = tmp;
    }
    else{
        struct node *ptr,*tptr;
        ptr = head;
        tptr = NULL;
        while(ptr && ptr->data < key){
            tptr = ptr;
            ptr = ptr->nxt;
        }
        struct node *tmp;
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = key;
        tmp->nxt = tptr->nxt;
        tptr->nxt = tmp;
    }
    printf("Element Inserted.\n");
}
void display(struct node *ptr){
    while(ptr){
        printf("%d ",ptr->data);
        ptr = ptr->nxt;
    }
}
int main(){
    createLL();
    insert();
    display(head);
    printf("\n\tExiting program.");
    return 0;
}