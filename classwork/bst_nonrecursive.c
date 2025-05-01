#include <stdio.h>
#include <stdlib.h>

struct node{
    int info;
    struct node *rchild;
    struct node *lchild;
};
struct node * stack[100];
int top=0;

struct node *insert(struct node * start, int val);
void inorder(struct node * start);
void preorder(struct node * start);
void postorder(struct node * start);
struct node * pop();
void push( struct node * ptr);

int main(){
    struct node *start=NULL;
    int ans;
    printf("This is a menu driven program of Binary search tree.\n");
    printf("1. to display inorder.\n");
    printf("2. to display preorder.\n");
    printf("3. To display postorder.\n");
    printf("4. To insert.\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &ans);
        switch(ans){
            case 1: 
                if(start==NULL){
                    printf("BST is empty.\n");
                    break;
                }
                inorder(start);
                break;
            case 2:
                if(start==NULL){
                    printf("BST is empty.\n");
                    break;
                }
                preorder(start);
                break;
            case 3:
                if(start==NULL){
                    printf("BST is empty.\n");
                    break;
                }
                postorder(start);
                break;
            case 4:
                printf("Enter the value: ");
                scanf("%d", &ans);
                start=insert(start, ans);
                break;
            case 5:
                break;
            default:
                printf("Invalid Entry.\n");
        }
    }
}
struct node *insert(struct node *start, int val){
    struct node *temp, *prev, *next=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=val;
    temp->rchild=NULL;
    temp->lchild=NULL;
    if(start==NULL)
        return temp;
    while(next!=NULL){
        prev=next;
        if(val<next->info)
            next=next->lchild;
        else{
            if(val>next->info)
                next=next->rchild;
            else{
                printf("Number already exists.\n");
                return start;
            }
        }
    }
    if(val<prev->info)
        prev->lchild=temp;
    else
        prev->rchild=temp;
    return start;
}
void inorder(struct node * start){
    struct node *ptr=start;
    while(top!=0||ptr!=NULL){
        while(ptr!=NULL){
            push(ptr);
            ptr=ptr->lchild;
        }
        ptr=pop();
        printf("%d\n", ptr->info);
        ptr=ptr->rchild;
    }
}
void preorder(struct node * start){
    struct node *ptr=start;
    while(top!=0||ptr!=NULL){
        while(ptr!=NULL){
            printf("%d\n", ptr->info);
            push(ptr->rchild);
            ptr=ptr->lchild;
        }
        ptr=pop();
    }
    
}
void postorder(struct node * start){
    struct node *ptr=start;
    while(top!=0||ptr!=NULL){
        while(ptr!=NULL){
            push(ptr);
            ptr=ptr->lchild;
            if(ptr==NULL)
                ptr=ptr->rchild;
        }
        ptr=pop();
        while(ptr->rchild==NULL){
            if(ptr->rchild!=NULL){
                ptr=ptr->rchild;
                break;
            }
            printf("%d \n", ptr->info);
            ptr=pop();  
        }
        
        
    }
}
struct node * pop(){
    return stack[top--];
}
void push( struct node * ptr){
    stack[++top]=ptr;
}