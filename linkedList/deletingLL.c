#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *nxt;
}*ele;
void create(int a[],int size){
    ele = (struct node *)malloc(sizeof(struct node));
    struct node *tmp,*latest;
    ele->data = a[0];
    ele->nxt = NULL;
    latest = ele;
    for(int i=1;i<size;i++){
        tmp = (struct node *)malloc(sizeof(struct node));
        tmp->data = a[i];
        tmp->nxt = NULL;
        latest->nxt = tmp;
        latest = tmp;
    }
    printf("\nList Created.");
}
void deletenode(int index){
    int store;
    if(index==0){//this case is when we want to remove the head node so we dont need two pointers
        struct node *p;
        p = ele;
        ele = ele->nxt;
        store = p->data;
        free(p);//deallocating the memory
    }
    else if(index>0){
        struct node *p,*tp;//p is the traversal pointer and tp is the tail pointer of pointer 'p'
        p = ele;//p is at first node
        tp = NULL;//initially tail pointer is not pointing on any node
        for(int i=0;i<index-1;i++){//loop to take the pointer to that location
            tp = p;//giving location of traversing pointer to the tail pointer
            p = p->nxt;//moving traversing pointer forward to the desired location
        }
        tp->nxt = p->nxt;//assigning the address of tail pointer to the next node to traversing pointer
        store = p->data;
        free(p);//deallocating the memory 
    }
    else printf("Enter a valid index.");//if user enter values in -ve
}
int main(){
    int arry[]={2,4,1,6,3,6,854,3};
    create(arry,sizeof(arry)/sizeof(int));
    delete(3);
    return 0;
}