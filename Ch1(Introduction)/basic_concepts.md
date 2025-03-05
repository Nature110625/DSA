# OVERVIEW : System life cycle
* Solid foundation in <br>data abstraction<br>algorithm specification<br>performance analysis and measurement<br>provides necessary meathodology to design and implement large-scale computer systems.
* Good programmers regard large-scale computer programs as system that contain many complex interacting parts
* Programs undergo a development process called system life cycle. This cycle consists of 
    * requirements phase
    * analysis phase
    * design phase
    * coding phase
    * verification phase<br>(these phases are highly interrelated)
## **Requirements**
* set of specifications defining the purpose of the project.
* information given to the programmer (input) and the result they must produce (output).
* initially defined vaguely, programmer must develop rigrous input and output description that includes all cases.
* Rigrous: done very carefully and with great attention to detail.
## **Analysis**
* After careful delineation(describing or drawing something in great detail) of system's requirements, the analysis phase begins in earnest (serious and sincere about what you are going to do).
* We begin to break the problem down into manageable pieces.
* There are two apporoaches to analysis:
    1. bottom-up
    2. top-down
* **bottom-up**
    * bottom-up approach is an older, unstructured strategy that places an early emphasis on the coding fine(acceptable) points. Resulting program has many loosely connected, error-ridden(full of error) segments.
    * bottom-up analysis is akin(similar to something) to constructing a building from generic(not specific) blueprint.
* **top-down**
    * approach begins with the purpose to serve and end product is used to divide the program into manageable segments.
    * This technique generates diagrams that are used to design the system.
    * several alternate solution to the programming problem are developed and compared during this phase.
## **Design**
* This phase continues the work done in the analysis phase.
* The designer apporaches the system from the perspective of both
    * the data objects that the program needs: leads to the creation of abstract data types
    * the operation performed on them: requires the specification of algorithms and a consideration of algorithm design strategies
* Since the abstract data types and the algorithm specifications are language independent, we postpone implementation decision. Although we must specify information required for each data object, ignoring coding details
* By deferring(to leave something until a later time) implementation issues, we not only create a system that could be written in several programming languages, but we also have time to pick the most efficient implementations within out chosen language.
## **Refinement and coding**
* In this phase, programmer choose representations for data objects and write algorithms for each operation on them.
* Data object's representation can determine the efficiency of the algorithms related to it. Hence, algorithms independent of the data objects should be written first.
## **Verification**
* This phase consists of developing correctness proofs for the program, testing the program with a variety of input data, and removing errors.
* *Correctness proofs*
    * Program can be proven correct using same techniques that abound(exist in large number or amount) in mathematics. 
    * These proofs are very time-consuming, and difficult to develop for large projects.
    * selection of algorithms that have been proven correct can reduce the number of errors.
* *Testing*
    * We can construct our correctness proofs before and during the coding phase, since our algorithm need not be written in a specific programming language.
    * Testing requires working code and sets of test data(should includes all possible scenarios).
    * A program's running time is also important.
    * Theoretical estimates of running time exist for many algorithms and we will derive these estimates as we introduce new algorithms.
    * Performance estimates for portion of our code can also be gathered.
* *Error removal*
    * If done properly, the correctness proofs and system tests will indicate erroneous (wrong, incorrect) code. 
    * ease with which we can remove these errors depends on the design and coding decision made earlier.
    * A large undocumented program written in spaghetti code generates new errors while debugging
    * On the other hand, debugging a well documented program that is divided into autonomous(having the freedom to govern itself or control it's own affair) units that interact through parameters is far easier. Best if each unit is tested separately and then integrated into the system.
## Algorithm specification
### Selection_sort
* From those integers that are currently unsorted, find the smallest and place it next in the sorted list.
* Function's code are easier to read than that of the `macro` but the `macro` works with any data type.
* `rand` function, defined in math.h to randomly generate a list of numbers.
* Function `sort(list, n)` correctly sorts a set of n&ge;1 integers. The result remains in `list[0], ..., list[n-1]` such that `list[0]&le;list[1]&le;...&le;list[n-1]`
### Recursive Algorithm
* Function can call themselves (direct recursion) or they may call other functuons that invoke the calling functuon again (indirect recursion).
* Any function that is written using assignment, if-else and while statements can be written recursively.
* When should we express an algorithm recursively
    * When problem itself is defined recursively (like factorials,fibonacci, and binomial coefficient)

