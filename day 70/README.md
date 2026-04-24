# Day 70

## Question 1

### Hash Table Using Linear Probing

Problem Statement
Implement a hash table using open addressing with linear probing.

Support INSERT and SEARCH operations. If the table becomes full, display “HASH TABLE FULL”.

Input Format
m
n
operation value
...

Output Format
Print results of SEARCH operations.

Sample Input
7
5
INSERT 10
INSERT 24
INSERT 17
SEARCH 24
SEARCH 5

Sample Output
FOUND
NOT FOUND

Explanation
● 24 inserted at index (24 % 7) = 3
● 5 never inserted → NOT FOUND

## Question 1 – Solution

- **Language:** C
- **Implementation File:** hash_table_using_linear_probing.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Cheapest Flights Within K Stops
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/cheapest-flights-within-k-stops/

### My Solution
_Paste your accepted LeetCode solution here_
