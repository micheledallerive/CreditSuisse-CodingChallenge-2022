# Reporting System

There are *n* reporting systems in the investment banking division of Credit Suisse. 
Each of them prepares a unique report which flows to another reporting system for verification and finally
reaches the original reporting system. For any reporting system, when its report flows from one system to another,
we call it a 'hop' for the report of that reporting system. It is also possible that some reporting system sends 
their report to themselves.
 
You will be provided with *n* reporting systems and an array 'flows' where i<sup>th</sup> system sends the report 
to flows[i]-th system in one hop.

For example, you are given `n = 6` and `flows = [4,6,1,3,5,2]`. 

For `i=1` (the first system) the report will flow to flows[1]<sup>th</sup> system (the fourth system). 
This is called the first hop for system-1. Now the fourth system will contain the report of the first system. 
The fourth system will send this report to the third system in the second hop of system-1.

Let us understand how the report for the 1-st system will flow:
- after the 1<sup>st</sup> hop, it will flow to the 4-th system,
- after the 2<sup>nd</sup> hop, it will flow to the 3-rd system,
- after the 3<sup>rd</sup> hop, it will flow to the 1-st system.
So after the third hop, the first system will receive its report and the flow will be 4->3->1. Similarly, every system has its flow.

### Input Format
The first line of each test case contains one integer n (1≤n≤2⋅10^5) — the number of reporting systems.
 The second line of the test case contains 'n' integers where i-th system will send the report to flows[i]-th system.
It is guaranteed that ∑n≤2⋅10^5 (sum of n does not exceed 2⋅10^5).

### Output Format
For each test case, print 'n' integers flows1,flows2,flows3…flowsn  where a<sub>i</sub> represents the total number hop after which the  i<sup>th</sup> system will get back its report.

### Examples
#### Example 1:
```
Input        |   Output 
```
```           
3            |   
2 3 1        |   3 3 3
```
Explanation:

For the first system the report will flow in the following sequence:
`System-2-> System-3-> System-1`
- So the total number of hop is 3.

For the second system the report will flow in the following sequence:
`System-3->System-1->System-2`
- So the total number of hop is 3.

For the third system the report will flow in the following sequence:
`System-1-> System-2-> System-3`
- So the total number of hop is 3.

#### Example 2:
```
Input        |   Output 
```
```           
5            |   
1 2 3 4 5    |   1 1 1 1 1
```
Explanation:

For the first system the report will flow in the following sequence:
`System-1->System-1`
- So the total number of hops is 1.

For the second system the report will flow in the following sequence:
`System-2->System-2`
- So the total number of hops is 1.

For the third system the report will flow in the following sequence:
`System-3->System-3`
- So the total number of hops is 1.

For the fourth system the report will flow in the following sequence:
`System-4->System-4`
- So the total number of hops is 1.

For the fifth system the report will flow in the following sequence:
`System-5->System-5`
- So the total number of hops is 1.
