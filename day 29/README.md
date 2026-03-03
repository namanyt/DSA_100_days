# Day 29

## Question 1

### Rotate Linked List Right by k Places

Problem: Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer k

Output:
- Print the linked list elements after rotation, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
40 50 10 20 30

Explanation:
Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

## Question 1 – Solution

- **Language:** C
- **Implementation File:** rotate_linked_list_right_by_k_places.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Add Two Numbers
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/add-two-numbers/description/

### My Solution
_Paste your accepted LeetCode solution here_
