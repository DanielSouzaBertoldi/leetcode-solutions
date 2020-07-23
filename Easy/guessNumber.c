/******************************************************************************

We are playing the Guess Game. The game is as follows:

I pick a number from 1 to n. You have to guess which number I picked.

Every time you guess wrong, I'll tell you whether the number is higher or lower.

You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):

-1 : My number is lower
 1 : My number is higher
 0 : Congrats! You got it!

Example :
Input: n = 10, pick = 6
Output: 6

--Results (as of 2020-07-23)
Runtime: 0 ms, faster than 100.00% of C online submissions for Guess Number Higher or Lower.
Memory Usage: 5 MB, less than 100.00% of C online submissions for Guess Number Higher or Lower.

*******************************************************************************/
/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			          1 if num is higher than the guess number
 *                otherwise return 0
 * int guess(int num);
 */

int guessNumber(int n){
	int left = 1, right = n, mid = 0, guessed = 0;
  
  while(left <= right) {
    mid = left + (right - left) / 2;
    guessed = guess(mid);
    
    if(guessed == 0)
      return mid;
    else if(guessed == -1)
      right = mid - 1;
    else
      left = mid + 1;
  }
  return -1;
}
