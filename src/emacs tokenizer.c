#include "tokenizer.h"

/* Return true (non-zero) if c is a whitespace characer
   ('\t' or ' ').  
   Zero terminators are not printable (therefore false) */
int space_char(char c){
  return(c==' ' || c == '\t');
}
/* Return true (non-zero) if c is a non-whitespace 
   character (not tab or space).  
   Zero terminators are not printable (therefore false) */ 
int non_space_char(char c){
  return (c != '\0' && !space_char(c));
}

/* Returns a pointer to the first character of the next 
   space-separated token in zero-terminated str.  Return a zero pointer if 
   str does not contain any tokens. */
char *token_start(char *str){
  if (!str) return NULL;

  while (*str && space_char(*str)) {
    str++;
  }
  return *str ? str : NULL;
}

/* Returns a pointer terminator char following *token */
char *token_terminator(char *token){
  if (!token) return NULL;

  while (*token && non_space_char(*token)) {
    token++;
  }
  return token;
}
/* Counts the number of tokens in the string argument. */
int count_tokens(char *str){
  int count = 0;
  char *token = token_start(str);

  while (token) {
    count++;
    token = token_start(token_terminator(token));
  }
  return count;
}
/* Returns a fresly allocated new zero-terminated string 
   containing <len> chars from <inStr> */
char *copy_str(char *inStr, short len){
  char *newStr = (char*)malloc(len + 1);
  if (!newStr) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }
  strncpy(newStr, inStr, len);
  newStr[len] = '\0';
  return newStr;
}
/* Returns a freshly allocated zero-terminated vector of freshly allocated 
   space-separated tokens from zero-terminated str.

   For example, tokenize("hello world string") would result in:
     tokens[0] = "hello"
     tokens[1] = "world"
     tokens[2] = "string" 
     tokens[3] = 0
*/
char **tokenize(char* str){
  if (!str) return NULL;

  int numTokens = count_tokens(str);
  char **tokens = (char**)malloc((numTokens + 1) * sizeof(char*));
  if (!tokens) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(EXIT_FAILURE);
  }

  int index = 0;
  char *token = token_start(str);

  while (token) {
    char *end = token_terminator(token);
    tokens[index++] = copy_str(token, end - token);
    token = token_start(end);
  }
  tokens[index] = NULL;
  return tokens;
}
/* Prints all tokens. */
void print_tokens(char **tokens){
  if (!tokens) return;

  for (int i = 0; tokens[i]; i++) {
    printf("tokens[%d] = \"%s\"\n", i, tokens[i]);
  }
}
/* Frees all tokens and the vector containing themx. */
void free_tokens(char **tokens){
  if (!tokens) return;

  for (int i = 0; tokens[i]; i++) {
    free(tokens[i]);
  }
  free(tokens);
}
#endif
