# Day 86

## Question 1

### Square Root using Binary Search

Problem: Find the integer square root of a given non-negative integer using Binary Search. The integer square root of a number is defined as the greatest integer whose square is less than or equal to the given number.

Input:
- First line: an integer n

Output:
- Print the integer square root of n

Examples:
Input:
64

Output:
8

Input:
20

Output:
4

Input:
1

Output:
1

Explanation:
Binary Search is applied on the range 0 to n. At each step, the middle value is squared and compared with n. If mid * mid equals n, mid is the square root. If mid * mid is less than n, search continues in the right half; otherwise, in the left half. The final answer is the largest integer whose square does not exceed n.

## Question 1 – Solution

- **Language:** C
- **Implementation File:** square_root_using_binary_search.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Sqrt(x)
- **Difficulty:** Easy
- **Link:** https://leetcode.com/problems/sqrtx/

### My Solution
_Paste your accepted LeetCode solution here_
