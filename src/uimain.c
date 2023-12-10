#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int main(){
  List *list;

  list = init_history();

  while (1) {
    char input[100];
    printf("To exit the tokenizer type  !q.\nTo view history type !h.\nAnd to view a selected history type !s\n");
    printf("Enter any setence\n");
    printf("$ ");

    fgets(input, 100, stdin);
    if (input [0] == '!' && input[1] == 'q') {
	free_history(list);
	printf("Thank you for using the tokenizer\n");
	return 0;
    }
    else if (input[0] == '!' && input[1] == 'h') {
	print_history(list);
	printf("\n");
      }
    else if(input[0] == '!' && input[1] == 's'){
      int id = atoi(&input[2]);
      if(get_history(list, id) != NULL){
	char *hist = get_history(list,id);
	printf("ID[%d] %s\n",id, hist);
      }
      else{
	printf("That ID doesn't exist.\n");
      }
     }
    else{
      char **tokens;
      add_history(list, input);
      tokens = tokenize(input);
      print_tokens(tokens);
      free_tokens(tokens);
      }
  }
}
