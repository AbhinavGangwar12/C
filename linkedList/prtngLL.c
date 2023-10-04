#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *nxt;
}*first;
void create(int a[],int n){
    int i;
    struct node *tmp,*latest;
    first=(struct node *)malloc(sizeof(struct node));
    first->data = a[0];
    first->nxt = NULL;
    latest=first;
    for(i=1;i<n;i++){
        tmp=(struct node *)malloc(sizeof(struct node));
        tmp->data=a[i];
        tmp->nxt=NULL;
        latest->nxt=tmp;
        latest=tmp;
    }
}
void display(struct node *ptr){
    while(ptr!=NULL){
        printf("%d ",ptr->data);
        ptr = ptr->nxt;
    }
}
// DISPLAYING LINKED LIST USING RECURSSION
void displayr(struct node *ptr){
    if(ptr!=NULL){
        printf("%d ",ptr->data);
        displayr(ptr->nxt);
    }
}

//THIS WILL PRINT BACKWARDS
void displaybr(struct node *ptr){
    if(ptr!=NULL){
        displaybr(ptr->nxt);
        printf("%d ",ptr->data);
    }
}

// COUNTING NUMBER OF NODES IN A LINKED LIST
int counting(struct node *ptr){
    int count = 0;
    while(ptr!=NULL)count++;
    return count;
    // SPACE TAKEN WILL BE CONSTANT AND TIME TAKEN IS ORDER OF 'N'
}
// COUNTING USING RECURSION
int countr(struct node *ptr){
    if(ptr==NULL) return 0;
    else return countr(ptr->nxt)+1;//WE CANNOT USE ++ OPERATOR HERE BECAUSE ONE VALUE IS REQUIRED TO INCREAMENT
    // TIME TAKEN BY IT IS ORDER OF 'N' AND THE SPACE IS ORDER OF 'N'
}
int main(){
    int a[]={1,2,3,4,5,54,3};
    create(a,7);
    display(first);
    printf("\n");
    displaybr(first);
    printf("\n%d",countr(first));
    return 0;
}