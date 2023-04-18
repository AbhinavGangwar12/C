#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct element{
    int co,po;
};
struct pol{
    int no;
    struct element *el;
};
void input(struct pol *p){
    printf("Enter number of non zero elements : ");
    scanf("%d",&p->no);
    p->el = (struct element *)malloc(p->no*sizeof(struct element));//this statement is creating an array for structure element to store multiple elements under structure pol
    printf("Enter the elements\n");
    for(int i=0;i<p->no;i++){
        printf("Enter term %d :",i+1);
        scanf("%d %d",&p->el[i].co,&p->el[i].po);//we have to traverse through all the elements so we have used i here
    }
}
void Poleqn(struct pol *p){
    int sum=0,x;
    printf("Enter value of x : ");
    scanf("%d",&x);
    for(int i=0;i<p->no;i++){
        sum += p->el[i].co*pow(x,p->el[i].po);
    }
    printf("%d",sum);
}
int main(){
    struct pol p;
    input(&p);
    printf("Value of polynomial equation --> ");
    Poleqn(&p);
    return 0;
}