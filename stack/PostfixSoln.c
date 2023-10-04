#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int size,top,*array;
    char* arry;
};
void push(struct stack* st,char a){
    if(st->top == st->size){
        printf("Stack Overflow!");
        return;
    }
    else{
        st->top++;
        st->array[st->top] = a;
    }
}
char pop(struct stack* st){
    if(st->top <= -1){
        printf("Stack Underflow");
        return '0';
    }
    else{
        st->top--;
        return st->array[st->top+1];
    }
}
int isEmpty(struct stack* st){
    if(st->top == -1)return 1;
    else return 0;
}
char stackTop(struct stack* st){
    if(st->top==-1)return 'x';
    else st->array[st->top];
}
int isOperand(char x){
    if(x == '+' || x == '-' || x == '/' || x == '*')return 0;
    else return 1;
}
int precendence(char x){
    if(x == '+' || x == '-')return 1;
    else if(x == '*' || x == '/') return 2;
    else return 0;
}
char* postFix(char* prefix){
    struct stack st;
    st.size = strlen(prefix);
    st.top = -1;
    st.array = (int*)malloc(st.size*sizeof(char));
    int len = strlen(prefix);
    char* postfix = (char*)malloc((len+1)*sizeof(char));
    int i = 0,j=0;
    while(prefix[i]!='\0'){
        if(isOperand(prefix[i]))postfix[j++] = prefix[i++];
        else{
            if(precendence(prefix[i])>precendence(stackTop(&st)))push(&st,prefix[i++]);
            else postfix[j++] = pop(&st);
        }
    }
    while(!isEmpty(&st))postfix[j++] = pop(&st);
    postfix[j] = '\0';
    return postfix;
}
int solution(char *postf){
    struct stack ss;
    ss.size = strlen(postf);
    ss.top = -1;
    ss.array = (int*)malloc(ss.size*sizeof(char));
    int x1,x2,result;//TOOK VARIABLE FOR PERFORMING OPERATIONS
    for(int i = 0;postf[i]!='\0';i++){
        if(isOperand(postf[i]))push(&ss,postf[i]-'0');//PUSHED THE OPERAND INTO THE STACK AND SUBTRACTED THE VALUE OF ZERO BECAUSE IT IS A CHARACTER STRING AND IF WE DONT PERFORM THIS THEN ITS ASCII VALUE WILL BE PUSHED
        else {
            x2 = pop(&ss);
            x1 = pop(&ss);
            switch(postf[i]){
                case '+':
                    result = x1+x2;
                    push(&ss,result);
                    break;
                case '-':
                    result = x1-x2;
                    push(&ss,result);
                    break;
                case '*':
                    result = x1*x2;
                    push(&ss,result);
                    break;
                case '/':
                    result = x1/x2;
                    push(&ss,result);
                    break;
            }
        }
    }
    return pop(&ss);
}
int main(){
    char array[] = "35*62/+4",*ptr;
    ptr = array;
    printf("Infix form : %s\nPostfix form : %s\nSolution : %d",array, postFix(ptr),solution(postFix(ptr)));

    return 0;
}