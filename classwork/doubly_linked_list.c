#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *llink, *rlink;
};

struct node *create_list(struct node* start);
void display(struct node *start);
int count(struct node *start);
int search(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addatpos(struct node *start, int data, int pos);
// struct node *delatpos(struct node *start, int pos);
// struct node *delbeg(struct node *start);
// struct node *delend(struct node* start);
// struct node* reverse(struct node*start, struct node * prev);

int main(){
    struct node *start=NULL;
    int choice, data, item, pos;
    printf("This is a menu driven program: \n");
    printf("1. create a list\n");
    printf("2. Display\n");
    printf("3. Count\n");
    printf("4. search\n");
    printf("5. Add at beginning\n");
    printf("6. Add at end\n");
    printf("7. Add at given position\n");
    printf("8. Delete from beginning\n");
    printf("9. Delete from ending\n");
    printf("10. delete at position\n");
    printf("11. Reverse\n");
    printf("12. Quit\n\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                if(start!=NULL){
                    printf("list is already created\n");
                    break;
                }
                start=create_list(start);
                break;
            case 2:
                if(start==NULL){
                    printf("list is empty.\n");
                    break;
                }
                display(start);
                break;
            case 3:
                if(start==NULL){
                    printf("list is empty.\n");
                }
                printf("Number of nodes present in doubly linked list: %d\n", count(start));
                break;
            case 4:
                if(start==NULL){
                    printf("list is empty.\n");
                }
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                data=search(start, data);
                data==0?printf("Entered element is not present in list.\n"):printf("Entered element is at position %d\n", data);
                break;
            case 5:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start= addatbeg(start, data);
                break;
            case 6: 
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                start=addatend(start, data);
                break;
            case 7: 
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the position at which to insert: ");
                scanf("%d", &pos);
                start=addatpos(start, data, pos);
                break;
            // case 8:
            //     if(start==NULL){
            //         printf("list is empty.\n");
            //     }
            //     start= delbeg(start);
            //     break;
            // case 9: 
            //     if(start==NULL){
            //         printf("list is empty.\n");
            //     }
            //     start=delend(start);
            //     break;   
            // case 10:
            //     if(start==NULL){
            //         printf("list is empty.\n");
            //     }
            //     printf("Enter the position of element to be deleted: ");
            //     scanf("%d", &data);
            //     start=delatpos(start, data);
            //     break;
            // case 11:
            //     if(start==NULL){
            //         printf("The list is empty.");
            //         break;
            //     }
            //     start=reverse(start, NULL);
            //     break;
            case 12:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
    return 0;
}

struct node *create_list(struct node* start){
    start=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value: ");
    scanf("%d", &start->info);
    start->llink=NULL;
    start->rlink=NULL;
    return start;
}
void display(struct node *start){
    struct node *ptr=start;
    printf("The list is: \n");
    while(ptr!=NULL){
        printf("%d\n", ptr->info);
        ptr=ptr->rlink;
    }
}
int count(struct node *start){
    int count=0;
    struct node *ptr=start;
    while(ptr!=NULL){
        count++;
        ptr=ptr->rlink;
    }
    return count;
}
int search(struct node *start, int data){
    struct node* ptr=start;
    int count=0;
    while(ptr!=NULL){
        count++;
        if(ptr->info==data)
            return count;
        ptr=ptr->rlink;
    }
    return 0;
}
struct node *addatbeg(struct node *start, int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->llink=NULL;
    temp->rlink=start;
    return temp;
}
struct node *addatend(struct node *start, int data){
    struct node *ptr=start;
    while(ptr->rlink!=NULL)
        ptr=ptr->rlink;
    ptr->rlink=(struct node *)malloc(sizeof(struct node));
    ptr->rlink->info=data;
    ptr->rlink->llink=ptr;
    ptr->rlink->rlink=NULL;
    return start;
}
struct node *addatpos(struct node *start, int data, int pos){
    struct node *ptr=start, *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    if(pos<2){
        temp->rlink=start;
        temp->llink=NULL;
        temp->info=data;
        return temp;
    }
    for(int i=2; i<pos; i++){
        ptr=ptr->rlink;
        if(ptr==NULL){
            printf("Entered position does not exist.\n");
            return start;
        }
    }
    temp->rlink=ptr->rlink;
    temp->llink=ptr;
    temp->info=data;
    ptr->rlink=temp;
    if(temp->rlink!=NULL)
        temp->rlink->llink=temp;
    return start;
}