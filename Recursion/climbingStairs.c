/******************************************************************************
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps
Example 2:

Input: 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step
 

Constraints:

1 <= n <= 45

- Results (as of 2020-07-21)
Runtime: 4 ms (beats 13.98% of C submissions)
Memory Usage: 5.1 MB (beats 80.53% of C submissions)
*******************************************************************************/

int climbStairs(int n){
  int curr = 1, prev = 1, total = 1;
  
  for(int i = 1; i < n; i++) { // Fibonacci hell yeah
    total = curr + prev;
    prev = curr;
    curr = total;
  }

  return total;
}
