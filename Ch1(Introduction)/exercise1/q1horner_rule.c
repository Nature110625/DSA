/*Q2*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int poly(int *, int, int);
int main(){
    int deg, var;
    printf("Enter the degree of polynomial: ");
    scanf("%d", &deg);
    int coeff[deg+1];
    for(int i=0; i<=deg; i++)
        coeff[i]=rand()%1000;
    printf("The polynomial is: \nf(x)=");
    for(int i=0; i<=deg; i++){
        printf("%dx^%d", coeff[i], i);
        if(i!=deg)
            printf(" + ");
    }
    printf("\nEnter the value of variable: ");
    scanf("%d", &var);
    printf("The value polynomial f(x)= %d", poly(coeff, deg, var));
}
int poly(int *coeff, int deg, int var){
    if(deg==1){
        return (coeff[0]+coeff[1]*var);
    }
    return (coeff[0]+poly(++coeff, --deg, var)*4);
}