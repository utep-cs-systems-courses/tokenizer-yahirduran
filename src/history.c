#include <stdio.h>
#include <stdlib.h>
#include "history.h"

Item *node(int id, char *str){
  char *copy;
  copy = malloc(sizeof(char) * 100); 
  int count = 0;
  Item *node = (Item *)malloc(sizeof(Item));
  node->id = id;
  for(int i = 0; i < 100; i++)
    copy[i] = str[i];
  node->str = copy;
  node->next = NULL;
  return node;
}
List* init_history(){
  List *list = (List *)malloc(sizeof(List));
  list->root = NULL;
  return list;
}

void add_history(List *list, char *str){
  int id = 0;
  if(list->root != NULL){
    Item *curr = list->root;
    id++;
    while(curr->next != NULL){
      curr = curr->next;
      id++;
    }
    curr->next = node(id, str);
  }
  else{
    list->root = node(id, str);
  }
}
char *get_history(List *list, int id){
   if(list->root != NULL){
    Item *curr = list->root;
    while(curr != NULL){
      if(curr->id == id)
	return curr->str;
      curr = curr->next;
    }
  }
  return NULL;
}

void print_history(List *list){
  if(list->root != NULL){
    Item *curr = list->root;
    while(curr != NULL){
      printf("ID[%d]: %s\n", curr->id, curr->str);
      curr = curr->next;
    }
  }
}

void free_history(List *list){
  if(list->root != NULL){
    Item *curr, *temp;
    curr = list->root;
    while(curr != NULL){
      temp = curr;
      curr = curr->next;
      free(temp->str);
      free(temp);
    }
  }
}
