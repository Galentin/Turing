#include "input.h"

int checkInteger(char step[]){
    if(strtol(step, NULL, 10) != 0){
        int j = strlen(step);
        int i = 0;
        while (i < j){
            if(atoi(&step[i]) == 0){
                return 0;
            }
            i++;
        }
        if(strtol(step, NULL, 10) < 0){
            return 0;
        }
        return 1;
    }else{
        return 0;
    }
}

void errorCommand(char *arg, int line, char symbolError, char symbol){
    printf("Incorrect command in %s line %d - \"%c\" instead of the expected \"%c\"", arg, line + 1, symbolError, symbol);
    exit(13);
}

int searchState(struct State *arrayTable, int arraySize, long int lastState, char *tape, int head){
    int i = 0;
    while(arrayTable[i].inpQ != lastState || arrayTable[i].inpCh != tape[head]){
        i++;
        if(i == arraySize){
        printf("No transition of the symbol %c from state %li", tape[head], lastState);
        exit(21);
        }
    }
    return i;
}

