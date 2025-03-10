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
```
```