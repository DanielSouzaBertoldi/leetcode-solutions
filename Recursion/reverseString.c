void reverseString(char* s, int sSize){
  char letter = ' ';

  for(int i = sSize-1, j = 0; i > j; i--, j++) {
    letter = s[j];
    s[j] = s[i];
    s[i] = letter;
  }
  
  s = s;
}
