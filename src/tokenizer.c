#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c == '\t')
    return 1;
  return 0;
}

int non_space_char(char c){
  if(space_char(c))
    return 0;
  return 1;
}

char *token_start(char *str){
  for(; *str != '\0'; str++)
    if(non_space_char(*str))
      return str;
  return NULL;
}

char *token_terminator(char *token){
  for(; *token != '\0'; token++)
    if(space_char(*token))
      return token;
  return token;
}

int count_tokens(char *str){
  int count = 0;
  if(token_start(str) != NULL)
    count++;
  while(str = token_terminator(str)){
    if(str = token_start(str))
      count++;
    else
      break;
  }
  return  count++;
}

char *copy_str(char *inStr, short len){
  char *str;
  int i = 0;
  str = (char *) malloc(len +1);
  while(i < len){
    str[i] = inStr[i];
    i++;
  }
  str[i] = '\0';
  return str;
}

char **tokenize(char *str){
  char *word;
  int count = count_tokens(str);
  int i = 0;
  char **tokens = (char **) malloc((count +1) * sizeof(char *));
  for(; i < count; i++){
    word = token_terminator(str = token_start(str));
    tokens[i] = copy_str(str, word - str);
    str = word;
  }
  tokens[i] = NULL;
  return tokens;
}
void print_tokens(char **tokens){
  for(;*tokens != NULL; *tokens++)
    printf("%s\n", *tokens);
}

void free_tokens(char **tokens){
  char **temp;
  for (temp = tokens; *temp; free(*temp++));
  free(tokens);
}
