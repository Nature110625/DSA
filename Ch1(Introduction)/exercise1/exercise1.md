### Q1
Consider the two statements, Both fail to satisfy one of the five criteria of an algorithm. Which criterion do they violate.
* Is n=2 the largest value of n for which there exist positive integers x, y and z such that x<sup>n</sup>+y<sup>n</sup>=z<sup>n</sup> has a solution?
    ```
    To prove this statement we need to verify this equation with all integers, but integers are infinite and algorithm need to terminate. This statement violate finiteness.
    ```
* Store 5 divided by zero into x and go to statement 10.
    ```
    This statement is ambiguous. Hence this statement violates definiteness.
    ```
### Q2
Horner's rule is a strategy for evaluating a polynomial $A(x)=a_nx^n+a_{n-1}x^{n-1}+...+ a_1x+a_0$
<br>at point $x_0$ using a minimum number of multiplication. This rule is:
<br>$A(x_0)=(...((a_nx_0+a_{n-1})x_0+...+a_1)x_0+a_0)$
```c
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
```
### Q3
Given n Boolean variables $x_1, ..., x_n$, we wish to print all possible combinations of truth values they can assume. For instance, if n=2, there are four possibilities: ```<true, true>, <false, true>, <true, false>, and <false, false>```. Write a C program to do this.
```c
#include <stdio.h>

void comb_of_tv(int *, int, int);
int main(){
    int n;
    printf("Enter number of variables: ");
    scanf("%d", &n);
    int tv[n];
    for(int i=0; i<n; i++)
        tv[i]=0;

    comb_of_tv(tv, n, 0);
}
void comb_of_tv(int *list, int n, int i){
    char temp;
    if(i==n){
        for (int j=0; j<n; j++)
            list[j]==1?printf("T "): printf("F ");
        printf("\n");
    } 
    else
        for(int m=0; m<2; m++){
            temp=list[i];
            list[i]=m;
            comb_of_tv(list, n, i+1); //i counts the level
            list[i]=temp;
        }
}
```
### Q4
Write a C program that prints out the integer values of x, y, z in ascending order.
```c
#include <stdio.h>
void prnt(int, int, int);
int main(){
    int a, b, c;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    prnt(a, b, c);
}
void prnt(int a, int b, int c){
    b>a?(b<c?printf("%d %d %d", a, b, c):prnt(a,c,b)):prnt(b,a,c);  //kind of binary sort
}
```
### Q5
The pigeon hole principle states that if a function f has n distinct inputs but less than n distinct outputs then there are two inputs a and b such that a is not equalto b and f(a)=f(b). Write a C program to find the value a and b for which range values are equal.