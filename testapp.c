#include <stdio.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void processInput(char* input) {
    // Your processing logic here
    printf("You entered: %s\n", input);
    

}

int main() {
    char input[MAX_INPUT_LENGTH];

    while (1) {
        // Print a prompt
        printf("Enter command (or 'exit' to quit): ");

        // Read input from the user
        if (fgets(input, sizeof(input), stdin) == NULL) {
            printf("Error reading input.\n");
            break;
        }

        // Remove trailing newline character
        input[strcspn(input, "\n")] = '\0';

        // Check if the user wants to exit
        if (strcmp(input, "exit") == 0) {
            printf("Exiting program.\n");
            break;
        }

        // Process the input
        processInput(input);
    }

    return 0;
}
