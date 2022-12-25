# Fraudulent Transactions
Monica has been assigned the task of escalating potential ineligble asset transfers that Credit Suisse may execute. In order to do so, the bank has a criteria set as follows:

Each transaction is a sequence of transfers where transfers[i] = [A, B] indicates that the assets are being transferred from client A to client B. 
The order of the sender and receiver clients in the transfers is important.  

The transaction is considered ineligible if at any point, a client X sending forward the assets receives them back at a later point in the transaction, from a client Y who indirectly received them from X. 
However, if a client transfers assets to themselves, then it is safe to assume that they're being transferred to another account held by the same client, and hence **not** considered **ineligible**. Your task is to help Monica identify if a transaction is eligible or not.
It is assured that all pairs of clients involved in the transfers are unique. Besides, all clients may not participate in the transaction.

#### Constraints:
* `1 <= no. of Clients, n <= 2000`
* `1 <= transfers.length`, `l <= 5000`
* `transfers[i].length = 2` , `0 <= i < l`
* <code> transfers[i] = [a<sub>i</sub>, b<sub>i</sub>]</code> <code>0 <= a<sub>i</sub>, b<sub>i</sub> < n</code>

#### Input Format
<pre>First Line: n l {space-separated}
Next <b>l</b> Lines: transfers[i] {2 space-separated integers}</pre>
#### Output Format
<pre>Eligible or Ineligible {string, case-sensitive}</pre>
###  Examples
#### Example 1
Input: 
```
4 5
0 1
1 2
1 3
2 0 
3 2
```
Output:<br>
```
Ineligible
```
Explanation:
```
There are 4 clients involved in 5 transfers.
Client 0 has forwarded the assets to Client 1 in the first transfer, but receives them back in the 4th transfer from Client 2. 
Hence this transaction is ineligible.
```

#### Example 2
Input: 
```
3 2
0 1
1 1
```
Output:<br>
```
Eligible
```
Explanation:
```
There are 3 clients, but only 2 are involved in 2 transfers.
Client 0 forwards the assets to Client 1 in the first transfer, and Client 1 sends the assets to another account held by itself in the second transfer. 
Hence this transaction is eligible.
```
