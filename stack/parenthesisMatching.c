#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
struct stack{
    int size,top;
    char* arry;
};
void push(struct stack *st,char a){
    if(st->top==st->size)printf("Stack Overflow!\n");
    else {
        st->top++;
        st->arry[st->top] = a;
    }
}
char pop(struct stack *st){
    char a = 'F';
    if(st->top <= -1){
        printf("Stack Underflow!\n");
        return a;
    }
    else {
        a = st->arry[st->top];
        st->top--;
        return a;
    }
}
bool isEmpty(struct stack *st){
    if(st->top==-1)return true;
    else return false;
}
bool isBalanced(char* eqn){
    struct stack s;
    s.size = strlen(eqn);
    s.top = -1;
    s.arry = (char*)malloc(s.size*sizeof(char));
    for(int i = 0;eqn[i]!='\0';i++){
        if(eqn[i]=='(')push(&s,eqn[i]);
        else if(eqn[i]==')'){
            if(isEmpty(&s))return false;
            pop(&s);
        }
    }
    return isEmpty(&s)?true:false;
}
int top(struct stack *st){
    return st->top;
}
char stackTop(struct stack* st){
    if(st->top!=-1)return st->arry[st->top];
    else return -1;
}
bool isbalance1(char* eqn){
    struct stack s1;
    s1.size = strlen(eqn);
    s1.top = -1;
    s1.arry = (char*)malloc(s1.size*sizeof(char));
    for(int i = 0;eqn[i]!='\0';i++){
        if(eqn[i]=='('||eqn[i]=='{'||eqn[i]=='[')push(&s1,eqn[i]);
        char x = stackTop(&s1);
        if(eqn[i]==')'&& x=='('||eqn[i]=='}'&&x=='{'||eqn[i]==']'&&x=='[')pop(&s1);
        else {
            printf("%c is Imbalanced!",x);
            return false;
        }
    }
    if(isEmpty(&s1)){
        printf("Parenthesis balanced!");
        return true;
    }
    else return false;
}
int main(){
    char array[] = "(sjdnc{[]}{)",*ptr;
    ptr = array;
    isbalance1(ptr);
    return 0;
}