/******************************************************************************

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.

Example 1:

Input: "()"
Output: true

Example 2:
Input: "()[]{}"
Output: true

Example 3:
Input: "(]"
Output: false

Example 4:
Input: "([)]"
Output: false

Example 5:
Input: "{[]}"
Output: true

--Results (as of 2020-07-23)
Runtime: 0 ms, faster than 100.00% of C online submissions for Valid Parentheses.
Memory Usage: 5.2 MB, less than 92.55% of C online submissions for Valid Parentheses.

*******************************************************************************/

/*
  I just want to say that I have no ideia how this code runs so well despite being spaghetti code. There's definitely room for improvement here, but this was my first attempt.
*/

bool isValid(char * s){
  if(!s || sizeof(s) == 0)
    return true;
  
  char *parentheses = (char *) malloc(sizeof(char) * strlen(s));
  char *c = s;
  bool valid = true;
  int j = 0;

  for( ; *c != '\0'; c++) {
    if(*c == ')' || *c == ']' || *c == '}') {
      if(j == 0)
        return false;
      
      --j;
    }
    
    if(*c == '(' || *c == '{' || *c == '[') {
      parentheses[j] = *c;
      j++;
    }
    else if(*c == ')')
      valid = (parentheses[j] == '(') ? true : false;
    else if(*c == ']')
      valid = (parentheses[j] == '[') ? true : false;
    else if(*c == '}')
      valid = (parentheses[j] == '{') ? true : false;
    
    if(!valid)
      break;
  }
  
  if(j != 0)
    return false;
    
  return valid;
}
