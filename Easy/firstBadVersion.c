/******************************************************************************

You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

Example:

Given n = 5, and version = 4 is the first bad version.

call isBadVersion(3) -> false
call isBadVersion(5) -> true
call isBadVersion(4) -> true

Then 4 is the first bad version. 

--Results (as of 2020-07-23)
Runtime: 0 ms, faster than 100.00% of C online submissions for First Bad Version.
Memory Usage: 5.2 MB, less than 48.98% of C online submissions for First Bad Version.

*******************************************************************************/
// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
  int left = 0, right = n;
  
  while(left < right) {
    int mid = left + (right - left) / 2;
    
    if(isBadVersion(mid))
      right = mid;
    else
      left = mid + 1;
  }
    
  return left;
}
