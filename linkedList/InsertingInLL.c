#include<stdio.h>
#include<stdlib.h>
struct list{
    int data;
    struct list *nxt;
}*ele;

void createLL(int a[],int size){
    ele=(struct list *)malloc(size*sizeof(struct list));
    struct list *tmp,*latest;
    ele->data=a[0];
    ele->nxt=NULL;
    latest=ele;
    for(int i=1;i<size;i++){
        tmp = (struct list *)malloc(sizeof(struct list));
        tmp->data=a[i];
        tmp->nxt=NULL;
        latest->nxt=tmp;
        latest=tmp;
    }
    printf("\nLL created.");
}
void insert(struct list *p){
    printf("\nEnter position and value to insert\n");
    int po,v;
    scanf("%d %d",&po,&v);//GETTING THE VALUE AND INDEX
    if(po==1){
        struct list *tmp;//CREATED A TEMPORARY STRUCTURE ARRAY TO STORE THE VALUE
        tmp = (struct list*)malloc(sizeof(struct list));
        tmp->data=v;
        tmp->nxt = p;//WHEN WE WANT TO INSERT AT FIRST PLACE THEN IT POINT ON THE PREVIOUS FIRST NODE i.e. THE WHOLE LIST
        p = tmp;//NOW THIS TEMPORARY NODE WILL BECOME THE FIRST NODE
    }
    else if(po>1){
        struct list *flow;//HAVE CREATED A FLOW TO TAKE THE POINTER TO THE DESIRED INDEX
        flow = ele;//POINTS ON THE FIRST NODE CURRENTLY SO IT CAN GET THE ACCESS OF FULL LIST
        for(int i=1;i<po-1 && flow;i++)flow = flow->nxt;//IT WILL TAKE THE FLOW TO THE DESIRED LOCATION
        if(flow){//TO CHECK WHETHER THE GIVEN INDEX IS VAILD OR NOT 
            struct list *tmp;//MAKING THE TEMPORARY NODE TO INSERT IT
            tmp = (struct list *)malloc(sizeof(struct list));
            tmp->data = v;//STORING THE VALUE
            tmp->nxt = flow->nxt;//POINTING IT TO THE NEXT NODE OF FLOW
            flow->nxt = tmp;//POINTING FLOW TO THIS TEMPORARY NODE
        }
    }
    printf("\nElement inserted.");//THIS TEMPORARY NODE IS INSERTED TO THE MAIN LIST
}
void displayLL(struct list*p){
    printf("\nDisplaying List\n");
    while(p){
        printf("%d ",p->data);
        p = p->nxt;
    }
}
int main(){
    int a[]={2,4,2,576,43,7};
    createLL(a,sizeof(a)/sizeof(int));
    insert(ele);
    displayLL(ele);
    return 0;
}