# Day 100

## Question 1

### Product of Array Except Self

Problem: Given an integer array nums[], return an array answer[] such that answer[i] is equal to the product of all the elements of nums except nums[i]. The solution must run in O(n) time and should not use the division operation.

Input:
- First line: integer n representing the size of the array
- Second line: n space-separated integers representing the array elements

Output:
- Print n space-separated integers representing the product array

Examples:
Input:
4
1 2 3 4

Output:
24 12 8 6

Input:
5
-1 1 0 -3 3

Output:
0 0 9 0 0

Explanation:
For each index i, the value at answer[i] is calculated as the product of all elements to the left of i multiplied by the product of all elements to the right of i. This approach avoids using division and ensures linear time complexity.

## Question 1 – Solution

- **Language:** C
- **Implementation File:** product_of_array_except_self.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Count of Smaller Numbers After Self
- **Difficulty:** Hard
- **Link:** https://leetcode.com/problems/count-of-smaller-numbers-after-self/

### My Solution
_Paste your accepted LeetCode solution here_
