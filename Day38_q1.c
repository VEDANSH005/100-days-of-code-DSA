#include <stdio.h>
#define MAX 100

typedef struct {
    int arr[MAX];
    int front;
    int rear;
} Deque;

/* Initialize deque */
void initDeque(Deque *dq){
    dq->front = -1;
    dq->rear = -1;
}

/* Check empty */
int empty(Deque *dq){
    return dq->front == -1;
}

/* Size */
int size(Deque *dq){
    if(dq->front == -1)
        return 0;
    return dq->rear - dq->front + 1;
}

/* Push front */
void push_front(Deque *dq, int val){

    if(dq->front == 0){
        printf("Deque Overflow\n");
        return;
    }

    if(dq->front == -1){
        dq->front = dq->rear = 0;
    }
    else{
        dq->front--;
    }

    dq->arr[dq->front] = val;
}

/* Push back */
void push_back(Deque *dq, int val){

    if(dq->rear == MAX-1){
        printf("Deque Overflow\n");
        return;
    }

    if(dq->rear == -1){
        dq->front = dq->rear = 0;
    }
    else{
        dq->rear++;
    }

    dq->arr[dq->rear] = val;
}

/* Pop front */
void pop_front(Deque *dq){

    if(empty(dq)){
        printf("Deque Underflow\n");
        return;
    }

    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }
    else{
        dq->front++;
    }
}

/* Pop back */
void pop_back(Deque *dq){

    if(empty(dq)){
        printf("Deque Underflow\n");
        return;
    }

    if(dq->front == dq->rear){
        dq->front = dq->rear = -1;
    }
    else{
        dq->rear--;
    }
}

/* Front element */
int front(Deque *dq){

    if(empty(dq))
        return -1;

    return dq->arr[dq->front];
}

/* Back element */
int back(Deque *dq){

    if(empty(dq))
        return -1;

    return dq->arr[dq->rear];
}

/* Clear deque */
void clear(Deque *dq){
    dq->front = dq->rear = -1;
}

/* Reverse deque */
void reverse(Deque *dq){

    int i = dq->front;
    int j = dq->rear;

    while(i < j){
        int temp = dq->arr[i];
        dq->arr[i] = dq->arr[j];
        dq->arr[j] = temp;
        i++;
        j--;
    }
}

/* Sort deque */
void sort(Deque *dq){

    for(int i=dq->front;i<=dq->rear;i++){
        for(int j=i+1;j<=dq->rear;j++){

            if(dq->arr[i] > dq->arr[j]){
                int temp = dq->arr[i];
                dq->arr[i] = dq->arr[j];
                dq->arr[j] = temp;
            }

        }
    }
}

/* Display deque */
void display(Deque *dq){

    if(empty(dq)){
        printf("Deque Empty\n");
        return;
    }

    printf("Deque elements: ");

    for(int i=dq->front;i<=dq->rear;i++){
        printf("%d ", dq->arr[i]);
    }

    printf("\n");
}

/* Main program */
int main(){

    Deque dq;
    initDeque(&dq);

    push_back(&dq,10);
    push_back(&dq,20);
    push_front(&dq,5);
    push_back(&dq,30);

    display(&dq);

    pop_front(&dq);
    pop_back(&dq);

    display(&dq);

    printf("Front: %d\n", front(&dq));
    printf("Back: %d\n", back(&dq));
    printf("Size: %d\n", size(&dq));

    reverse(&dq);
    printf("After Reverse:\n");
    display(&dq);

    sort(&dq);
    printf("After Sort:\n");
    display(&dq);

    clear(&dq);
    printf("After Clear:\n");
    display(&dq);

    return 0;
}