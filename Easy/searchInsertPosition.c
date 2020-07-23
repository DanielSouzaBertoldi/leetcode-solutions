/******************************************************************************

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Example 1:
Input: [1,3,5,6], 5
Output: 2

Example 2:
Input: [1,3,5,6], 2
Output: 1

Example 3:
Input: [1,3,5,6], 7
Output: 4

Example 4:
Input: [1,3,5,6], 0
Output: 0

--Results (as of 2020-07-23)
Runtime: 4 ms, faster than 90.74% of C online submissions for Search Insert Position.
Memory Usage: 5.7 MB, less than 69.47% of C online submissions for Search Insert Position.

*******************************************************************************/

int searchInsert(int* nums, int numsSize, int target){
  int i = 0;
  for( ; i < numsSize; i++) {
    if(nums[i] == target || nums[i] > target)
      return i;
  }
  return i;
}
