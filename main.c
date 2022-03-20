#include <stdio.h>

#define MEMORY_SIZE 1000
#define MAX_COMMAND 200


void clearMemory(char * memory){
    int i;
    for (i = 0; i < MEMORY_SIZE; i++){
        memory[i] = 0;
    }
}

void printMemoryD(char * startptr, char * ptr, char * endptr){
    int i;
    for (i = 0; startptr + i != endptr; i++){
        if (startptr + i == ptr) printf("P-");
        else printf("  ");
        printf("M%d: %d\n", i, startptr[i]);
    }
        
}

void applyCommand(char * command, char * startptr, char ** ptr, char ** endptr){
    int i, output_flag = 0;
    char output[MAX_COMMAND], counter = 0;
    char c;

    for (i = 0; command[i] != '\0'; i++){
        c = command[i];

        // Pointer movement commands
        if (c == '>' && (*ptr) != startptr + MEMORY_SIZE) {
            (*ptr)++;
            if (*endptr == *ptr) (*endptr)++;
        }
        if (c == '<' && (*ptr) != startptr) (*ptr)--;

        // Memory cell incremet and decrement 
        if (c == '+') (**ptr)++;
        if (c == '-') (**ptr)--;

        // Output and input
        if (c == '.') {
            output_flag = 1;
            output[counter] = **ptr;
            counter++;
        }

        //TODO fix loops for nested structures
        // Loop
        if (c == '[') {
            if (**ptr == 0) {
                while (command[i] != ']' && command[i] != '\0'){
                    i++;
                }
            }
                
        }
        if (c == ']'){
            if (**ptr != 0) {
                while (command[i] != '[' && command[i] != '\0'){
                    i--;
                }
            }
        }
    }

    if (output_flag) printf("Output: %s\n", output);
}

int cmprCommand(char * command, const char * c){
    int i;
    for (i = 0; command[i] != '\0' && c[i] != '\0'; i++)
        if (command[i] != c[i]) return 0;
    return 1;
}

int main(){ 
    char memory[MEMORY_SIZE] = {0};
    char *ptr = &memory[0], *startptr = ptr, *endptr = ptr + 1;
    char command[MAX_COMMAND];

    printf("8r41NFUCK 1N73rPr373r [Version 1.0]\n");
    while(1){
        printf("->: ");
        scanf("%s", command);

        if      (cmprCommand(command, "print")) printMemoryD(startptr, ptr, endptr);
        else if (cmprCommand(command, "stop"))  break;
        else if (cmprCommand(command, "clear")) clearMemory(memory);
        else applyCommand(command, startptr, &ptr, &endptr);
    }
    
    return 0;
}