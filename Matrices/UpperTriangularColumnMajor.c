#include<stdio.h>
#include<stdlib.h>
struct matrix{
    int *a,len;
};
void set(struct matrix *,int,int,int);
int get(struct matrix *,int,int);
void printm(struct matrix *,int,int);
int main(){
    struct matrix m;
    int v,x,n;
    printf("Enter size of matrix : ");
    scanf("%d",&m.len);
    m.a = (int*)malloc(m.len*(m.len-1)/2*sizeof(int));
    printf("Enter values\n");
    for(int i=1;i<=m.len;i++){
        for(int j=1;j<=m.len;j++){
            scanf("%d",&v);
            set(&m,i,j,v);
        }
    }
    for(int i=1;i<=m.len;i++){
        for(int j=1;j<=m.len;j++){
            printm(&m,i,j);
        }
        printf("\n");
    }
    printf("Enter the index which you want : ");
    scanf("%d %d",&x,&n);
    printf("%d",get(&m,x,n));
    return 0;
}
void set(struct matrix *m,int i,int j,int v){
    if(i>=j)m->a[m->len*(j-1)-(j-1)*(j-2)/2+(i-j)] = v;
}
int get(struct matrix *m,int i,int j){
    if(i>=j)return m->a[m->len*(j-1)-(j-1)*(j-2)/2+(i-j)];
    else return 0;
}
void printm(struct matrix *m,int i,int j){
    if(i>=j)printf("%d ",m->a[m->len*(j-1)-(j-1)*(j-2)/2+(i-j)]);
    else printf("0 ");
}