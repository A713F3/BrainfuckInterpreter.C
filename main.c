#include <stdio.h>

void printMemoryD(int * startptr, int * ptr, int * endptr){
    int i;
    for (i = 0; startptr + i != endptr; i++){
        if (startptr + i == ptr) printf("P:");
        else printf("  ");
        printf("M%d: %d\n", i, startptr[i]);
    }
        
}

//TODO restrict pointer movement if ptr is at the start or end
void applyCommand(char * command, int ** ptr, int ** endptr){
    int i;
    char c;
    for (i = 0; command[i] != '\0'; i++){
        c = command[i];

        if (c == '>') {
            (*ptr)++;
            if (*endptr == *ptr) (*endptr)++;
        }
        if (c == '<') (*ptr)--;
        if (c == '+') (**ptr)++;
        if (c == '-') (**ptr)--;
    }
}

int cmpr(char * a, char * b){
    int i;
    for (i = 0; a[i] != '\0' && b[i] != '\0'; i++)
        if (a[i] != b[i]) return 0;
    return 1;
}

int main(){ 
    int memory[1000] = {0}, *ptr = &memory[0], *startptr = ptr, *endptr = ptr + 1;
    char command[100];

    while(1){
        printf("->: ");
        scanf("%s", command);

        if      (cmpr(command, "print")) printMemoryD(startptr, ptr, endptr);
        else if (cmpr(command, "stop"))  break;
        else applyCommand(command, &ptr, &endptr);
    }
    

    

    return 0;
}