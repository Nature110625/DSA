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
struct node *delval(struct node *start, int val);
struct node *delbeg(struct node *start);
struct node *delend(struct node* start);
struct node* reverse(struct node*start, struct node * prev);

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
    printf("10. Delete from beginning\n");
    printf("11. Delete from ending\n");
    printf("12. delete at position\n");
    printf("13. Delete value\n");
    printf("14. Reverse\n");
    printf("15. Quit\n\n");
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
                start= delbeg(start);
                break;
            case 11: 
                start=delend(start);
                break;   
            case 12:
                printf("Enter the position of element to be deleted: ");
                scanf("%d", &data);
                start=delatpos(start, data);
                break;
            case 13:
                printf("Enter the value you want to delete: ");
                scanf("%d", &data);
                start=delval(start, data);
                break;
            case 14:
                if(start==NULL){
                    printf("The list is empty.");
                    break;
                }
                start=reverse(start, NULL);
                break;
            case 15:
                exit(1);
            default:
                printf("Wrong choice\n");
        }
    }
}