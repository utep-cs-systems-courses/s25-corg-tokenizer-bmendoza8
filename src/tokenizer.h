#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <stdlib.h>

int string_length(const char *str);
int is_valid_character(char c);
char *find_word_start(char *str);
char *find_word_terminator(char *str);
int count_words(const char *str);
char **tokenize(const char *str);
void free_tokens(char **tokens);


#endif

