/*****************************
Notes - More String Functions
  Searching a String - strchr(), strstr()
    strchr()
    first arg is str to be searched
    second arg is char looking for
    search string starting at the beg and resturn a pointer (type char*) to the first position in the str where the character is found
    can store return value in a pointer
    if char not found returns NULL, NULL is equivalent of 0 for a pointer and represents a pointer that does not point to anything
    
    strstr()
    searches one string for the first occurence of a substring
    returns a pointer to the position in the first string where the substring is found
    if no match, returns NULL
    first arg is str to be searched
    second arg is the substring to be found
    
  Tokenizing a string - strtok() - a sequence of characters within a string that is bounded by a delimiter
    breaking a sentence into words is an example
    
    strtok()
    first arg is string to be tokenized
    second arg is a string containing all possible deliminter characters

  Analyzing Strings - islower(), isupper(), isalpha(), isdigit() etc.



*******************************/

int main() {
  //strchr()
  char str[] = "The quick brown fox";
  char ch = 'q';
  char *pFoundChar = NULL;
  pFoundChar = strchr(str, ch);
    
  if(pFoundChar) {
    printf("Found the character at %p\n", pFoundChar);
    printf("Which is the %lu index of the string\n", pFoundChar - str);
  }
  
  //substring - strstr()
  char text[] = "Every dog has his day";
  char word[] = "dog";
  char *pFoundWord = NULL;
  pFoundWord = strstr(text, word);
  
  if(pFoundWord) {
    printf("Found the word at %p\n", pFoundWord);
    printf("Which starts at the %lu index of the string\n", pFoundWord - text);
  }
  
  //tokenize, strtok()
  char str2[80] = "Hello how are you - my name is - jake";
  const char s[2] = "-";
  char *tokenized = NULL;
    
  //find first token
  tokenized = strtok(str2, s);
  //find the remaining tokens
  while(tokenized != NULL) {
    printf("%s\n", tokenized);
    
    tokenized = strtok(NULL, s);
  }
  
  return 0;
}
