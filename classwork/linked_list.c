#include <stdio.h>
#include <stdlib.h>
struct node{
    int info;
    struct node *link;
};

struct node *create_list(struct node* start);
void display(struct node *start);
int count(struct node *start);
int search(struct node *start, int data);
struct node *addatbeg(struct node *start, int data);
struct node *addatend(struct node *start, int data);
struct node *addatpos(struct node *start, int data, int pos);
struct node *addbefore(struct node *start, int data, int val);
struct node *addafter(struct node *start, int data, int val);
struct node *delatpos(struct node *start, int pos);

int main(){
    struct node *start=NULL;
    int choice, data, item, pos, temp;
    printf("This is a menu driven program: \n");
    printf("1. create a list\n");
    printf("2. Display\n");
    printf("3. Count\n");
    printf("4. search\n");
    printf("5. Add at beginning\n");
    printf("6. Add at end\n");
    printf("7. Add at given position\n");
    printf("8. Add before node\n");
    printf("9. Add after node\n");
    printf("10. delete at position\n");
    printf("10. Delete\n");
    printf("11. Reverse\n");
    printf("12. Quit\n\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                start=create_list(start);
                break;
            case 2:
                display(start);
                break;
            case 3:
                printf("Number of nodes present in linked list: %d", count(start));
                break;
            case 4: 
                printf("Enter the element to be searched: ");
                scanf("%d", &data);
                temp=search(start, data);
                temp==0?printf("Entered element is not present in list."):printf("Entered element is at position %d", temp);
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
            case 8:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element before which to insert: ");
                scanf("%d", &item);
                start=addbefore(start, data, item);
                break;
            case 9:
                printf("Enter the element to be inserted: ");
                scanf("%d", &data);
                printf("Enter the element after which to insert: ");
                scanf("%d", &item);
                start=addafter(start, data, item);
                break;   
            case 10:
                printf("Enter the position of element to be deleted: ");
                scanf("%d", &data);
                start=delatpos(start, data);
                break;
            // case 11:
            //     start=reverse(start);
            //     break;
            case 12:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}

struct node *create_list(struct node* start){
    if(start!=NULL){
        printf("List had already been created.\n");
        return start;
    }
    int val;
    printf("Enter the element to be inserted: ");
    scanf("%d", &val);
    start=(struct node *)malloc(sizeof(struct node));
    start->info=val;
    start->link=NULL;
    return start;
}
void display(struct node *start){
    if(start==NULL){
        printf("The list is empty.");
        return;
    }
    struct node *p=start;
    while(p!=NULL){
        printf("%d ", p->info);
        p=p->link;
    }
}
int count(struct node *start){
    int count=0;
    while(start!=NULL){
        count++;
        start=start->link;
    }
    return count;
}
int search(struct node *start, int data){
    int pos=1;
    while(1){
        if(start==NULL)
            return 0;
        if(start->info==data)
            break;
        pos++;
        start=start->link; 
    }
    return pos;
}
struct node *addatbeg(struct node *start, int data){
    struct node *temp;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=start;
    start=temp;
    return start;
}
struct node *addatend(struct node *start, int data){
    struct node *temp, *ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(start==NULL)
        start=temp;
    else{
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=temp;
    }
    return start;
}
struct node *addatpos(struct node *start, int data, int pos){
    struct node *temp, *ptr=start;
    temp=(struct node *)malloc(sizeof(struct node));
    temp->info=data;
    temp->link=NULL;
    if(pos<=1||start==NULL){//To add at position 1 even if list is empty
        temp->link=start;
        start=temp;
        return start;
    }
    //ptr should point at position one less than the position were new element is to be added
    for(int i=1; i<=pos; i++){   
        if(ptr==NULL){
            printf("The required position does not exist in current list.");
            return start;
        }
        if(i>2)     //since we dont need to update ptr upto 2nd position.
            ptr=ptr->link;
    }
    temp->link=ptr->link;
    ptr->link=temp;
    return start;
}

struct node *addbefore(struct node *start, int data, int val){
    int pos=search(start, val);
    if(pos==0)
        printf("value is not present in the list");
    else
        start=addatpos(start, data, pos);
    return start;
}
struct node *addafter(struct node *start, int data, int val){
    int pos=search(start, val)+1;
    if(pos==1)
        printf("Value is not present in the list");
    else
        start=addatpos(start, data, pos);
    return start;
}
struct node *delatpos(struct node *start, int pos){
    struct node *ptr=start;
    if(start==NULL){
        printf("List is empty.");
        return start;
    }
    if(pos<2)
        return start->link; 
    for(int i=1; i<=pos; i++){
        if(ptr==NULL){
            printf("The required position does not exist in current list.");
            return start;
        }
        if(i>2)
            ptr=ptr->link;
    }
    ptr->link=ptr->link->link;
    return start;
}