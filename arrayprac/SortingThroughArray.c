#include<stdio.h>
int main(){
    int a[100],n,s;
    printf("Enter the number of inputs you want : \n");
    scanf("%d", &n);
    for(int i = 0;i<n;i++){
        printf("Enter element %d : ",i+1);
        scanf("%d",&a[i]);
    }
    for(int j = 0;j<n;++j){
        for(int x = j+1;x<=n;++x){
            if(a[j]>a[x]){
                s = a[j];
                a[j] = a[x];
                a[x] = s;
            }
        }
    }
    for(int b = 1;b <= n;++b){
        printf("%d\t", a[b]);
    }
}