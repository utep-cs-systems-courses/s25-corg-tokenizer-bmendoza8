#include <stdio.h>
#include <string.h>
#define MAX_INPUT_SIZE 256

int main() {

  char input[MAX_INPUT_SIZE];

  while (1) {
    printf("> ");
    if (!fgets(input, MAX_INPUT_SIZE, stdin)) {
      break;
    }

    input[strcspn(input, "\n")] = 0;

    if (strcmp(input, "exit") == 0) {
      printf("Goodbye!\n");
      break;
    }
    printf("You entered: %s\n", input);
  }
  return 0;
}

