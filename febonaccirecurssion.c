#include<stdio.h>
int fabonacci(int,int);
int term,i;
int main(){
    int prvnm = 0, nm = 1;
    printf("Enter any number for febonacci series : ");
    scanf("%d", &term);
    printf("0\t1\t");
    fabonacci(prvnm,nm);
    return 0;
}
int fabonacci(int prvnm, int nm){
    int  nxtnm;
    if (i == term)
    {
        return 0;
    }
    else{
        nxtnm = prvnm + nm;
        prvnm = nm;
        nm = nxtnm;
        printf("%d\t", nxtnm);
        i++;
        fabonacci(prvnm,nm);
    }
    // return 0 ;
    
}