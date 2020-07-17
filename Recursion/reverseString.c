/******************************************************************************

Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.

Example 1:

Input: ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:

Input: ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

--Results (as of 2020-07-17):

Runtime: 68 ms (beats 18.43% of C submissions)
Memory Usage: 11.9 MB (beats 92.55% of C submissions)
*******************************************************************************/

void reverseString(char* s, int sSize){
  char letter = ' ';

  for(int i = sSize-1, j = 0; i > j; i--, j++) {
    letter = s[j];
    s[j] = s[i];
    s[i] = letter;
  }
  
  s = s;
}
