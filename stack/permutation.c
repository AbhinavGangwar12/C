#include<stdio.h>

void perm(char str[],int a){
    static int flag[10] = {0};
    static char rst[10];
    if(str[a]=='\0'){
        rst[a] = '\0';
        printf("%s ",rst); 
    }
    else {
        for(int i=0;str[i]!='\0';i++){
            if(flag[i]==0){
                rst[a] = str[i];
                flag[i] = 1;
                perm(str,a+1);
                flag[i] = 0;
            }
        }
    }
}
void swap(char a,char b){
    char temp = a;
    a = b;
    b = temp;   
}
void perm1(char str[],int l,int h){
    if(l==h)printf("%s ",str);
    else {
        for(int i=l;i<=h;i++){
            swap(str[i],str[l]);
            perm1(str,l++,h);
            swap(str[l],str[i]);
        }
    }
}

int main(){
    perm("ABC",0);
    return 0;
}