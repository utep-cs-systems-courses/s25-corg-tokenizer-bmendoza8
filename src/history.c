#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "history.h"


History* init_history() {

  History* history = malloc(sizeof(History));
  if (!history){
    return NULL;
  }
  
  history->root = NULL;
  return history;

}

void add_history(History* history, const char* command) {
  if (!history){
    return;
  }

  HistoryNode* new_node = malloc(sizeof(HistoryNode));
  if (!new_node){
    return;
  }
  
  new_node->command = strdup(command);
  new_node->next = history->root;
  history->root = new_node;

}

const char* get_history(History* history, int index) {
  if (!history) return NULL;

  HistoryNode* current = history->root;
  int i = 1;
  while (current) {
    if (i == index) return current->command;
    current = current->next;
    i++;
  }
  return NULL;

}

void free_history(History* history) {
  if (!history) return;

  HistoryNode* current = history->root;
  while (current) {
    HistoryNode* temp = current;
    current = current->next;
    free(temp->command);
    free(temp);
  }
  free(history);
}
