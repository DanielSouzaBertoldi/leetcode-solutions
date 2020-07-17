/******************************************************************************

Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.

In Pascal's triangle, each number is the sum of the two numbers directly above it.

          1
        1   1
      1   2   1
    1   3   3   1
  1   4   6   4   1
1   5   10  10  5   1

Example:

Input: 3
Output: [1,3,3,1]
Follow up:

Could you optimize your algorithm to use only O(k) extra space?

- Results (as of 2020-07-17):

Runtime: 4 ms (beats 27.14% of C submissions)
Memory Usage: 5.4 MB (beats 70.00% of C submissions)

*******************************************************************************/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getRow(int rowIndex, int* returnSize){
  int pos = 0;
  *returnSize = rowIndex+1;
  int* rowValues = (int *) malloc(sizeof(int) * (*returnSize));
  ++rowIndex;
  for (int line = 1; line <= rowIndex; line++) { 
    long C = 1; 
    for (int i = 1; i <= line; i++)  { 
      if(line = rowIndex) {
        rowValues[pos] = C;
        pos++;
      }

      C = C * (line - i) / i;  
    }
  }
  
  return rowValues;
}
