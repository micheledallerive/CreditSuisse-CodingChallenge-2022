# Sorting Share Prices

Temeka is a trader they have the share price of N different companies. They want to sort them in the increasing order of the share price but decides to do it in a unqiue way. They decide to map the prices to an array
and tries to sort the array of prices by reversing some shareprices of consecutive companies. 

They add one more rule. They are able to reverse the shareprice of consecutive companies only if the sum of the share prices in of all these companies does not exceed the value M.

Temeka has to find whether the given array of share price of N companies can be sorted in increasing order following this way.

Note: you can assume that share prices are integers.

### Input Format:
- The first line contains the N and M, denoting the number of companies and M is the maximum sum of share prices a subarray of companies that can be sorted.
- The second line consists of N space separated integers P<sub>1</sub>, P<sub>2</sub>, P<sub>3</sub> ... P<sub>N</sub> representing the share prices associated with each of the N companies.

### Output Format:
- The output should be 1 if Temeka can sort array of share prices with a finite number of operations else the output should be 0.

### Constraints:
-	<code>1 ≤ N ≤ 10<sup>5<sup></code>
-	<code>1 ≤ P<sub>i</sub> ≤ 2*10<sup>9<sup></code> 
-	<code>1 ≤ M ≤ 2*10<sup>9</sup></code>

### Examples:
#### Example 1
```
Input      | Output
```
```
4 1        |  
2 1 3 4    |  0
```
Explanation: There is no consecutive companies with sum of prices less than or equal to 1, so we cannot sort this array of prices. Thus the output is 0.

#### Example 2
```
Input      | Output
```
```
4 1        |
1 2 3 4    | 1
```
Explanation: The array of prices is already sorted thus output is 1.

#### Example 3
```
Input      | Output
```
```
5 7        |
3 2 2 3 3  | 1
```
Explanation: We can reverse the companies in  P[1,3] whose sum is 3+2+2=7. After reversing the new set of share price is [2,2,3] and the resulting array is [2,2,3,3,3] which is sorted.
