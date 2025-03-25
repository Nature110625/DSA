#include <stdio.h>
int main(){
    printf("Ahan Tamatar Bade Mazedar, O Tamatar Bade Mazedar");
    printf("\n Aada Pada Kon Pada? Ramji Ka Ghoda Pada");
    printf("\n Do you liked it?(y/n): ");
    char ans;
    scanf ("%c",&ans);
    if (ans=='y'||ans=='Y'){
        printf("\n Thank you for your feedback, we will make you smile everytime");

    }
    else 
        printf ("\n We are sorry, we will try our best next time" );
}