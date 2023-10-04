// IN LINK LIST SEARCHING WE DONT PERFORM TRANSPOSITION BECAUSE WE SHOULD NOT MOVE DATA OF NODES SO WE MUST SHIFT THE ENTIRE NODE FOR BETTER SEARCHING EXPERIENCE NEXT TIME
#include<stdio.h>
#include<stdlib.h>
struct element{
    int data;
    struct element *nxt;
}*ele;
//SEARCH FUNCTION BY TRANSPOSITION
void search(struct element *ptr,int key){
    struct element *fptr=NULL;
    while(ptr){
        if(ptr->data==key){
            fptr->nxt = ptr->nxt;
            ptr->nxt = ele;
            ele = ptr;
            return;
        }
        fptr = ptr;
        ptr = ptr->nxt;
    }
    printf("Element not found !");
}
// CREATING A LINKLIST STATICALLY
void creatLL(int arry[],int length){
    ele = (struct element*)malloc(length*sizeof(struct element));
    struct element *tmp,*latest;
    ele->data = arry[0];
    ele->nxt = NULL;
    latest = ele;
    for(int i=1;i<length;i++){
        tmp = (struct element*)malloc(sizeof(struct element));
        tmp->data=arry[i];
        tmp->nxt=NULL;
        latest->nxt=tmp;
        latest = tmp;
    }
    printf("\tLinkListCreated!");
}

int main(){
    int arr[]={12,4,2,123,53,234,231,87565,2345,322,56,22,11};
    creatLL(arr,sizeof(arr)/sizeof(int));
    search(ele,4);
    return 0;
}