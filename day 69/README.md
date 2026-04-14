# Day 69

## Question 1

### Implement a Hash Table Using Chaining (Linked List Collision Handling)

Problem Statement
Implement a hash table of size m using separate chaining, where collisions are resolved by storing elements in a linked list.

You must support the following operations:
● INSERT x → Insert key x
● SEARCH x → Print “FOUND” or “NOT FOUND”
● DELETE x → Delete key x

Hash function:
h(x) = x % m.

Input Format
m
n
operation1 value
operation2 value
...
operation n value

Output Format
Print the result for SEARCH operations only.

Sample Input
5
6
INSERT 12
INSERT 7
INSERT 17
SEARCH 7
DELETE 7
SEARCH 7

Sample Output
FOUND
NOT FOUND

Explanation
● 12 → bucket 2, 7 → bucket 2, 17 → bucket 2
● After deletion of 7, it no longer exists.

## Question 1 – Solution

- **Language:** C
- **Implementation File:** implement_a_hash_table_using_chaining_linked_list_collision_handling.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Network Delay Time
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/network-delay-time/

### My Solution
_Paste your accepted LeetCode solution here_
