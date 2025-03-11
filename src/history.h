
#ifndef _HISTORY_H
#define _HISTORY_H

typedef struct HistoryNode {
  char *command;
  struct HistoryNode *next;
} HistoryNode;

typedef struct History {
  HistoryNode *root;
} History;

History *init_history();
void add_history(History* history, const char* command);
const char* get_history(History* history, int index);
void free_history(History* history);

#endif
