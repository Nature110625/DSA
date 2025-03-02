#include <stdio.h>
#include <stdlib.h>
int *stack, size, top=-1;
void push();
int pop();
void display();
int main(){
    int ans;
    printf("Enter the size of stack: ");
    scanf("%d", &size);
    stack=(int*)malloc(size*sizeof(int));
    printf("1. to push value into stack\n2. to pop value from stack\n3. to display stack\n4. to terminate program\n");
    do{
        printf("\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1: 
                if(top==size-1){
                    printf("Stack is full.\n");
                    break;
                }
                push();
                break;
            case 2: 
                if(top==-1){
                    printf("Stack is empty.\n");
                    break;
                }
                printf("Successfully deleted %d\n", pop());
                break;
            case 3:
                if(top==-1){
                    printf("Stack is empty.\n");
                    break;
                }
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid Entry\n");
        }
    }while(1);
}
void push(){
    int val;
    printf("Enter the number to push into stack: ");
    scanf("%d", &val);
    stack[++top]=val;
}
int pop(){
    int val=stack[top];
    top--;
    return val;
}
void display(){
    printf("Stack: \n");
    for(int i=0; i<=top; i++)
        printf("%d\n", stack[i]);
}
