#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size,top;
    char* array;
};
void push(struct stack* st,char a){
    if(st->top == st->size)return;
    else{
        st->top++;
        st->array[st->top] = a;
    }
}
char pop(struct stack* st){
    if(st->top == -1)return '0';
    else {
        st->top--;
        return st->array[st->top+1];
    }
}
char stackTop(struct stack* st){
    if(st->top==-1)return '0';
    else return st->array[st->top];
}
int isOperand(char a){
    if(a=='+'||a=='-'||a=='*'||a=='/'||a=='^'||a=='('||a==')')return 0;
    else return 1;
}
int precedenceOut(char a){
    if(a=='+'||a=='-')return 1;
    else if(a=='*'||a=='/') return 3;
    else if(a=='^')return 6;
    else if(a=='(')return 7;
    else if(a==')')return 0;
}
int precedenceIn(char a){
    if(a=='+'||a=='-')return 2;
    else if(a=='*'||a=='/') return 4;
    else if(a=='^')return 5;
    else if(a=='(')return 0;
}
int isEmpty(struct stack* st){
    if(st->top == -1)return 1;
    else return 0;
}
char* post(char* eqn){
    struct stack s;
    s.size = strlen(eqn);
    s.top = -1;
    s.array = (char*)malloc(s.size*sizeof(char));
    int len = strlen(eqn)+1;
    char* postfix = (char*)malloc(len*sizeof(char));
    int i=0,j=0;
    while(eqn[i]!='\0'){
        if(isOperand(eqn[i]))postfix[j++] = eqn[i++];
        else {
            if(precedenceOut(eqn[i])>=precedenceIn(stackTop(&s))){
                if(eqn[i]==')')continue;
                else push(&s,eqn[i++]);
            }
            else postfix[j++] = pop(&s);
        }
    }
    while(!isEmpty(&s))postfix[j++] = pop(&s);
    postfix[j] = '\0';
    printf("%s",postfix);
    return postfix;
}
int main(){
    char array[]="(a+b)*c-d^e^f",*ptr;
    ptr = array;
    printf("%s\n",post(ptr));
    return 0;
}