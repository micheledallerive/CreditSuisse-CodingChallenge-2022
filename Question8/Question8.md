# Risk Mitigation
The Risk Management Team of an Investment Bank needs to identify the potential losses involved in the bank's strategies
to minimize the risk and protect its assets.

Amari from the Risk Management Team is given a list of predicted costs for implementing risk aversion strategies in m months,
in an array costs[]. In order to implement a strategy, they must initiate it in the i<sup>th</sup> month, 
incurring a cost = costs[i] and close the strategy in j<sup>th</sup> month, mitigating a risk = costs[j].

Thus, the net risk mitigated by implementing the strategy = costs[j] - costs[i].

A strategy must only be implemented if the risk mitigated is higher than the cost incurred. 
Additionally, they're given a value ’n’ which denotes an upper limit on the total number of strategies that the company
can afford implementing to avert the losses.

Help Amari in finding the maximum net risk mitigated by implementing at most ’n’ strategies.

Note: Risk Team cannot implement multiple strategies simultaneously, i.e. a strategy must be closed before initiating a new one.

### Input Format:
- The first line contains the N and M, N denoting the maximum number of strategies and M is the number of months with costs that will be provided.
- The second line consists of M space separated integers costs<sub>1</sub>, costs<sub>2</sub>, costs<sub>3</sub> ... costs<sub>M</sub>
representing the risk predicted costs in millions associated with each of the M months.

### Output Format:
- The output should be an integer representing the maximum risk mitigated by implementing at most 'N' strategies.

### Constraints:
- <code>0 <= N <= 100</code>
- <code>0 <= costs.length <= 1000</code>
- <code>0 <= costs[i] <= 1000</code>

### Examples:
#### Example 1
```
Input      | Output
```
```
2 3        |  
2 4 1      |  2
```
Explanation: Initiate in month 1 (cost = 2) and close on month 2 (cost = 4), risk mitigation = 4-2 = 2 million dollars.
#### Example 2
```
Input         | Output
```
```
2 6           |  
3 2 6 5 0 3   |  7
```
Explanation: Initiate in month 2 (cost = 2) and stop in month 3 (cost = 6), risk mitigation = 6-2 = 4 million dollars. Then initiate in month 5 (price = 0) and stop in month 6 (cost = 3), risk mitigation = 3-0 = 3 million dollars. Total risk mitigation = 3 + 4 = 7 million dollars.
