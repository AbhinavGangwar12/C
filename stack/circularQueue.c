#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
struct queue{
    int size,vlu,front,rear,*que;
};
void enquque(struct queue* q,int x){
    if((q->rear+1)/q->size==q->front)printf("Queue is full!");
    else{
        q->rear = (q->rear+1)/q->size;
        q->que[q->rear] = x;
    }
}
int dequeue(struct queue* q){
    int a = -1;
    if(q->front == q->rear)printf("Queue is Empty!");
    else{
        q->front = (q->front+1)/q->size;
        a = q->que[q->front];
    }
    return a;
}
bool isEmpty(struct queue* q){
    if(q->front == q->rear)return true;
    else return false;
}
bool isFull(struct queue* q){
    if((q->rear+1)/q->size == q->front)return true;
    else return false;
}
int main(){
    return 0;
}