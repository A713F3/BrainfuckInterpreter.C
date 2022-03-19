#include <stdio.h>

void printMemoryD(int * ptr, int * endptr){
    int i;
    for (i = 0; ptr + i != endptr; i++) 
        printf("%d", ptr[i]);
}

void applyCommand(char * command, int * ptr, int * endptr){
    int i;
    char c;
    for (i = 0; command[i] != '\0' && ptr != NULL; i++){
        c = command[i];

        if (c == '>') {
            ptr++;
            endptr++;
        }
        if (c == '<') ptr--;
        if (c == '+') (*ptr)++;
        if (c == '-') (*ptr)--;
    }
}

int main(){ 
    int memory[1000] = {0}, *ptr = &memory[0], *endptr = &memory[0];
    char command[100];
    

    

    return 0;
}