# Introduction
## OVERVIEW
* Computer Science can be viewed as the study of algorithms. This study encompasses four distinct areas:
    1. Machines for executing algorithms - Includes study of various forms of machine fabrication and organization so that algorithms can be effectively carried out.
    2. Language for describing algorithms - These languages can be placed on a continuum (continuous sequence in which adjacent elements are not perceptibly(in a way that can be seen heard or noticed) different from each other but the extremes are quite distinct).
        * At one end are the languages which are closest to the physical machine and calls for language design (methods for specifying the syntax and semantics of a language).
        * At the other end are languages designed for sophisticated problem solving and requires translation (a means for translation into a more basic set of commands).
    3. Foundations of algorithms - here we ask and try to answer questions like ((abstract models of computers are devised to study following properties))
        * Is a particular task is accomplishable by a computing device?
        * What is the minimum number of operations necessary for any algorithm which performs a certain function?
    4. Analysis of algorithms - Questions about algorithm's behaviour and its worst and average time and how often it occur.
        * In 1830 Charles Babbage (father of computers) realized that an algorithm's behaviour pattern or *performance profile* is measured in terms of the computing time and space consumed while the algorithm is processing.
* An **algorithm** is a finite set of instructions which, if followed accomplish a particular task. Every algorithm must satisfy the following criteria
    1. **Input**: Zero or more quantities can be externally supplied.
    2. **Output**: At least one quantity is produced.
    3. **Definiteness**: Each instruction must be clear and unambiguous.
    4. **Finiteness**: For all cases the algorithm should terminate after finite number of steps.
    5. **Effectiveness**: every instruction must be sufficiently basic and can be carried out by a person using only pencil and paper.
    6. Each operation must be **feasible**(can be done easily and conviniently)
* A **program** not necessarily be finite. For example Operating System, which never terminates (except for system crashes) and continues in a wait loop until more jobs are entered.
* An algorithm can be devised for many common activities and can be described in many ways
    * A natural language can be used but we must be careful resulting instructions are definite.
    * Flow charts improvement over natural language by coupling it with graphical form of notation. This form places each processing step in a box and use arrows to indicate the next step.
        * different shapes stand for different kind of operations.
        * There is a difference between flow chart and algorithm
* If **Computer** is merely a means to an end (i.e a way to reach end), then the means is an algorithm but the end is the transformation of data.
    * Hence, It is referred to as a data processing machine (input raw data are transformed into refined data by algorithm).
* Thus we might say **Computer Science** is the *study of data*, its representation and transformation by a digital computer. This study encompasses four distinct areas:
    1. Machine that hold data
    2. Languages for describing data manipulation
    3. Foundations which describe what kinds of refined data can be produced from raw data
    4. Structures for representing data
* There is an intimate connection between the structuring of data, and the synthesis (The combination of component or elements to form a connected whole) of algorithms.

## Data Types
* In programming language, data type is a set of data with values having predefined characteristics
* At the top level there are two types of data types
    1. System defined data types (primitive data types): int, float, char, double, bool, etc.
    2. User defined data types: structure in C and class in Java
# Data Structure
* Data structure is a specialized format for organizing and storing data.
* Depending on the organization of the elements, datastructure are classified into two types:
    1. Linear data structure: Elements are accessed sequential order. (linked list, stacks, queues)
    2. Non-linear data structure: Elements are stored and accessed in a non linear order. (Trees and graphs)
# Abstract Data Types(ADTs)
* Data structure along with their operations are called Abstract Data Types(ADTs)
* ADT consists of two parts:
    1. Declaration of data
    2. Declaration of operation
* Examples: Linked list, Stacks, Queues, Priority Queues, Binary trees, Dictionaries, Disjoint sets, Hash Tables, Graphs, and many other.
# Algorithm
* An algorithm is the step-by-step instructions to solve a given problem
* **Running time analysis**: is the process of determining how processing time increases as the size of the problem (input size) increases.
* **Rate of growth**: is the rate at which the running time increases as a function of input.
* Types of Analysis:
    1. Worst case: Defines input for which the algorithm takes huge time.
    2. Best case: Defines the input for which the algorithm takes lowest time.
    3. Average case: Provides a prediction about running time of the algorithm; assumes that the input is random.
        * lower Bound &lt;=Average Time &lt;= Upper Bond
* Asymptotic notation(mathematical notation to describe the running time of an algorithm) of algorithm be f(n), where n is input size.
# Big-O-Notation
* This notation gives tight upper bond of the given function i.e., at larger values of n, the upper bond of f(n) is g(n) OR f(n)=O(g(n)).
* O-notation is defined as O(g(n))={f(n): there exist positive constants c and n<sub>0</sub> such that 0&lt;=f(n)&lt;=cg(n) for all n&gt;=n<sub>0</sub>}. The goal is to give smallest rate of growth g(n) greater than or equal to given algorithms rate of growth f(n).(in general rate of growth at lower value of n is not important)
* O(g(n)) is the set of functions with smaller or same order of growth as g(n)
# Omega-Notation
* This notation gives the tighter lower bound of the given algorithm (at larger value of n) and we represent it as f(n)=Omega(g(n)).
* omega(g(n))={f(n): there exist positive constant c and n<sub>0</sub>, such that 0&lt;=cg(n)&lt;=f(n) for all n &gt;=n<sub>0</sub>}. The goal is to give largest rate of growth g(n) which is less than or equal to given algorithms rate of growth f(n)
