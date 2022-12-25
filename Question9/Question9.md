# Minimum Cost to Decrypt Matrix

Data encryption is a very important aspect for transferring data over the internet. There various encryption techniques like AES, RSA and Triple DES. 

We have a unique encryption technique where we share a L x L matrix which contains a dollar pattern, to decrypt the message we have to remove all the dollar signs in the matrix, the minimum cost to remove the dollar signs is the original message.

We are allowed to the following actions on the matrix one or more times to remove all the dollar signs.
* Choose a I x I square submatrix, where the length and width of the matrix is between 1 to L inclusive.
* Consume the cost I units to clear all the dollar signs are  within the submatrix.

Help the person decrypt the message from the matrix which is the minimum cost.

The input will be L number of strings,P,with L characters. The $ sign indicates a dollar whereas a - indicates clear block.

### Constraints
* L is an integer. 
* 1 ≤ **L** ≤ 50
* **P**<sub>i</sub> consists of $ and -.
* |**P**<sub>i</sub>| = L

### Input
**L**<br>
**P**<sub>1</sub><br>
**P**<sub>2</sub><br>
.<br>
.<br>
.<br>
**P**<sub>L</sub><br>

### Output
Print the answer as an integer. The answer is the minimum amount which is required to remove all the dollars, which is the decrypted message.

###  Examples
#### Example 1
Command line input: 
```
5
$$---
-$$--
$-$--
-----
----$

```
Output:<br>
```
4
```
Explanation:
* Choose the value of I as 3, select the 1st row from the left and 1st row from the top as the top left square of the submatrix. 
* Choose the value of I as 1, select the 5th row from the left and 5th row from the top as the top left square of the submatrix.

#### Example 2
Command line input: 
```
3
---
---
---

```
Output:<br>
```
0
```

#### Example 3
Command line input: 
```
21
---------------------
---------------------
---$-$---------------
----$-------------$--
---$-$-----------$-$-
------------------$--
---------------------
---------------------
---------------------
----------$-----$----
------$--$$$---------
--------$$$$$--$-----
-------$$$$$$$-------
-----$--$$$$$--------
-------$$$$$$$-------
------$$$$$$$$$------
-------$$$$$$$--$----
------$$$$$$$$$------
--$--$$$$$$$$$$$-----
---------$$$---------
---------$$$---------
```
Output:<br>
```
19
```
