# Machine Learning Model Manager Program

A bank is launching a robust program for understanding performance of their machine learning models.
Models are submitted to the ML Model Manager (MLMM) program as a Book of Work, and a Book of Work is made up of contiguous under-performers whose total sum of performance scores strictly fall below the cutoff.
You will be given a cutoff score and an array of performance scores, where scores[i] is the performance of its i<sup>th</sup> model and i is the models's position. 

Find the possible maximum number of Book of Works (BoW) that can be formed and submitted to the MLMM.

### Constraints:
<code>1 <= scores.length <= 3 * 10<sup>4</sup></code>

<code>1 <= scores[i] <= 1000</code>

<code>0 <= cutoff <= 10<sup>6</sup></code>

### Input Format
Line 1: Integer - cutoff score

Line 2: Length of Array of performance scores

Line 3: Integer Array of performance scores

### Output Format
Integer - the maximum number of BoWs that can be formed and submitted to the MLMM

### Examples
#### Example 1:
```
Input             |   Output 
```
```
16                |              
4                 |
10 5 2 6          |   8
```
Explanation: The 8 possible BoW that have total sum of performace scores less than 16 are:
[10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]

#### Example 2:
```
Input             |   Output 
```
```
0                 |
3                 |
1 2 3             |   0
```
