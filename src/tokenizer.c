#include "tokenizer.h"
#include <string.h>
#include <ctype.h>

int string_length(const char *str) {
  return strlen(str);

}

int is_valid_character(char c) {
  return !isspace(c);

}

char *find_word_start(char *str) {
  while (*str && !is_valid_character(*str)) str++;
  return str;

}

char *find_word_terminator(char *str) {
  while (*str && is_valid_character(*str)) str++;
  return str;

}

int count_words(const char *str) {
  int count = 0;
  while (*str) {
    str = find_word_start((char *)str);
    if (*str) count++;
    str = find_word_terminator((char *)str);
  }
  return count;
}

char **tokenize(const char *str) {
  int num_words = count_words(str);
  char **tokens = malloc((num_words + 1) * sizeof(char *));
  if (!tokens) return NULL;

  int index = 0;
  while (*str) {
    str = find_word_start((char *)str);
    if (!*str){
      break;
    }
    char *end = find_word_terminator((char *)str);
    int len = end - str;
    tokens[index] = strndup(str,len);
    index++;
    str = end;
  }
  tokens[index] = NULL;
  return tokens;
}

void free_tokens(char **tokens){
  if(!tokens){
    return;
  }
  for (int i = 0; tokens[i]; i++){
    free(tokens[i]);
  }
  free(tokens);

}
