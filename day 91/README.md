# Day 91

## Question 1

### Arithmetic Number

Problem: You are given three integers a, b, and c, where 'a' is the first term of an arithmetic sequence, 'c' is the common difference, and 'b' is a number to be checked. Determine whether the number b exists in the arithmetic sequence. Return 1 if b is present in the sequence; otherwise, return 0.

Input:
- First line: integer a (first term of the arithmetic sequence)
- Second line: integer b (number to be checked)
- Third line: integer c (common difference of the arithmetic sequence)

Output:
- Print 1 if b exists in the arithmetic sequence, otherwise print 0

Examples:
Input:
1
3
2

Output:
1

Input:
1
2
3

Output:
0

Input:
1
2
4

Output:
0

Explanation:
An arithmetic sequence is of the form a, a+c, a+2c, a+3c, ... . To check whether b belongs to the sequence, verify that (b - a) is divisible by c and that b is reachable by repeatedly adding the common difference starting from a.

## Question 1 – Solution

- **Language:** C
- **Implementation File:** arithmetic_number.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Sort Colors
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/sort-colors/

### My Solution
_Paste your accepted LeetCode solution here_
