#include<stdio.h>
#include<stdlib.h>
struct element{
    int data;
    struct element *nxt;
}*list;
void createLL(int a[],int size){
    list = (struct element*)malloc(size*sizeof(struct element));
    struct element *tmp,*latest;
    list->data = a[0];
    list->nxt = NULL;
    latest = list;
    for(int i=1;i<size;i++){
        tmp = (struct element*)malloc(sizeof(struct element));
        tmp->data = a[i];
        tmp->nxt = NULL;
        latest->nxt = tmp;
        latest = tmp;
    }
}
void searchLL(struct element *p,int value){
    int index=0;
    while(p){
        if(p->data==value){
            printf("%d is at position %d",p->data,index+1);
            break;
        }
        p=p->nxt;
        index++;
    }
}
int main(){
    int arry[]={1,32,32,4,24,32,32,32,2,23,4,2,3},s=sizeof(arry)/sizeof(int);
    createLL(arry,s);
    searchLL(list,4);
    printf("\n\tPROGRAM EXECUTED!");
    return 0;
}
