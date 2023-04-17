#include<stdio.h>
#include<stdlib.h>
struct Element{
    int i,j,x;
};
struct Sparce{
    int m,n,tn;
    struct Element *element;
};
void sparce(struct Sparce *ptr){
    printf("Enter size of matrix : ");
    scanf("%d %d",&ptr->m,&ptr->n);
    printf("Enter total number of NonZero elements : ");
    scanf("%d",&ptr->tn);
    ptr->element = (struct Element*)malloc(ptr->tn*sizeof(struct Element));
    printf("Enter elements (row,column,element) :  ");
    for(int i=0;i<ptr->tn;i++)scanf("%d%d%d",&ptr->element[i].i,&ptr->element[i].j,&ptr->element[i].x);
}
void printS(struct Sparce s){
    int k=0;
    for(int i=0;i<s.m;i++){
        for(int j=0;j<s.n;j++){
            if(i==s.element[k].i && j==s.element[k].j) printf("%d  ",s.element[k++].x);
            else printf("0  ");
        }
        printf("\n");
    }
}
int main(){
    struct Sparce s;
    sparce(&s);
    printS(s);
    return 0;
}