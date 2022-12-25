# Time Intervals

The global equities division of an Investment Bank plays a crucial role right from the time the Hong Kong Stock Exchange opens at 01:00 hours UTC to the time the New York Stock Exchange closes at 21:00 hours UTC, everyday. 

The employees of a designated team work in shifts (denoted by [start time, end time]) to resolve client queries related to trades. 

For bookkeeping purposes, your goal is to give the auditor a sorted and mutually exhaustive list of non overlapping (mutually exclusive) time intervals of when employees were working on the desk; this list needs to also include the employee's name. For example, if time intervals are [1,3], [1,5] and [2,5], then the output should have intervals [1,2], [2,3], [3,5].

It is guaranteed that there will always be at least one employee at the desk during each interval and all employee names are unique.

#### Constraints
* All times are represented by integers for simplicity (*x* representing x:00 hours)
* Names of employees (strings) denoted by employees[] and their work shifts ([start time, end time]) denoted by shifts[]
* `1 <= employees.length = shifts.length`, `n <= 500`
* `1 <= employees[i].length (string)`, `l <= 100`
* <code>shifts[i] = [x<sub>s</sub>, x<sub>e</sub>]</code>  <code>1 <= x<sub>s</sub> < x<sub>e</sub> <= 21, x<sub>e</sub>-x<sub>s</sub> >= 1</code>
* `1 <= no. of non-overlapping, mutually exhaustive output intervals`,  <code>op <= [max(x<sub>e</sub>) - min(x<sub>s</sub>)]</code>
* Names of employees (strings) at desk in each output interval = names[]
* `1 <= names.length`, `d <= n`

#### Input Format
* First Line - n
* Next Line - <pre>employees[i] {n space-separated strings}</pre>
* Next *<b>n</b>* Lines - <pre>x<sub>s</sub>  x<sub>e</sub>  {2 space-separated integers corresponding to each employee}</pre>

#### Output Format
* First Line - op
* Next *<b>op</b>* Lines - <pre>x<sub>s</sub>  x<sub>e</sub>  d  names[i] {3 space-separated integers followed by d space-separated strings}</pre> 

#### Note: 
<code>Output intervals must be sorted linewise, and for each, the Names must be in alphabetical/lexicographical order. </code>

###  Examples
#### Example 1
Input: 
```
5
Alice Bob Cacey Deepak Emma
10 14
11 12
10 15
12 16
14 16
```
Output:<br>
```
5
10 11 2 Alice Cacey
11 12 3 Alice Bob Cacey
12 14 3 Alice Cacey Deepak
14 15 3 Cacey Deepak Emma
15 16 2 Deepak Emma
```

Explanation:
```
The time intervals in the input range from 10 to 16.
In output, all intervals are non-overlapping, and range from 10-16, i.e. mutually exhaustive.
In each output interval, a running list of employees is maintained based on their shifts.
From 10-11, 2 employees (Alice and Cacey) are at the desk and so on.
```

#### Example 2
Input: 
```
3
Neil Angel Alok
1 10
7 9
7 10
```
Output:<br>
```
3
1 7 1 Neil
7 9 3 Alok Angel Neil
9 10 2 Alok Neil
```
Explanation:
```
The time intervals in the input range from 1 to 10.
In output, all intervals are non-overlapping, and range from 1-10, i.e. mutually exhaustive.
In each output interval, a running list of employees is maintained based on their shifts.
Neil is at desk from 1-7, joined by Alok and Angel for 7-9 and so on. Note - names for each output interval are sorted in lexicographical order.
```
