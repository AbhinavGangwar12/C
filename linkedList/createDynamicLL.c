#include<stdio.h>
#include<stdlib.h>
// PROGRAM TO DYNAMICALLY CREATE A LINKEDLIST
struct list{
    int data;
    struct list *nxt;
}*element;
void createLL(){
    printf("Enter number of elements to store : ");\
    int num;
    scanf("%d",&num);
    element = (struct list *)malloc(num*sizeof(struct list));
    struct list *tmp,*latest;
    printf("Enter elements\n");
    scanf("%d",&element->data);
    element->nxt=NULL;
    latest = element;
    for(int i=1;i<num;i++){
        tmp = (struct list *)malloc(sizeof(struct list));
        scanf("%d",&tmp->data);
        tmp->nxt=NULL;
        latest->nxt = tmp;
        latest = tmp;
    }
}
// DISPLAY FUNTION TO PRINT THE LINKEDLIST ON TERMINAL
void displayLL(struct list *p){
    while(p){
        printf("%d ",p->data);
        p = p->nxt;
    }
}

int main(){
    createLL();
    displayLL(element);
    return 0;
}