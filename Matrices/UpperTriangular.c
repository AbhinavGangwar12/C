#include<stdio.h>
#include<stdlib.h>
struct matrix{
    int length,*arry;
};
void set(struct matrix *m,int,int,int);
void printmatrix(struct matrix *m,int,int);
int get(struct matrix *m,int,int);
int main(){
    struct matrix m;
    int v;
    printf("Enter dimentions of matrix : ");
    scanf("%d",&m.length);
    m.arry = (int*)malloc(m.length*(m.length-1)/2*sizeof(int));
    for(int i = 1;i <= m.length;i++){
        for(int j=1;j <=m.length;j++){
            scanf("%d",&v);
            set(&m,i,j,v);
        }
    }
    for(int i = 1;i<=m.length;i++){
        for(int j=1;j<=m.length;j++){
            printmatrix(&m,i,j);
        }
        printf("\n");
    }
    return 0;
}
void set(struct matrix *m,int i,int j,int v){
        if(i>=j)m->arry[i*(i-1)/2+j-1]=v;
}
void printmatrix(struct matrix *m,int i,int j){
    if(i>=j)printf("%d ",m->arry[i*(i-1)/2+j-1]);
    else printf("0 ");
}
int get(struct matrix *m,int i,int j){
    if(i>=j)return m->arry[i*(i-1)/2+j-1];
    else return 0;
}