# Day 93

## Question 1

### Roti Prata (Minimum Time to Cook)

Problem Statement
IEEE is organizing an event and needs to prepare P pratas using L cooks. Each cook has a rank R which determines how fast they can cook pratas. A cook with rank R cooks:
- 1st prata in R minutes
- 2nd prata in 2R minutes
- 3rd prata in 3R minutes, and so on.
A cook can only prepare a complete prata and cannot partially cook one. The task is to determine the minimum time required to cook at least P pratas using all available cooks.

Input Format
The first line contains an integer t representing the number of test cases.
For each test case:
- The first line contains an integer P, the number of pratas required.
- The second line starts with an integer L, followed by L space-separated integers representing the ranks of the cooks.

Output Format
For each test case, print a single integer representing the minimum number of minutes required to cook P pratas.

Sample Input
3
10
4 1 2 3 4
8
1 1
8
8 1 1 1 1 1 1 1 1

Sample Output
12
36
1

Explanation
In the first test case, by efficiently distributing the cooking among cooks with ranks 1, 2, 3, and 4, a total of 10 pratas can be prepared in 12 minutes, which is the minimum possible time.

## Question 1 – Solution

- **Language:** C
- **Implementation File:** roti_prata_minimum_time_to_cook.c

The solution has been implemented as a standalone C program.
Refer to the source file for a fully commented explanation.

## Question 2 – LeetCode

- **Problem:** Insertion Sort List
- **Difficulty:** Medium
- **Link:** https://leetcode.com/problems/insertion-sort-list/

### My Solution
_Paste your accepted LeetCode solution here_
