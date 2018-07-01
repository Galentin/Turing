#include "input.h"

void printTape(char *tape, int head, int tapeSize, FILE *output){
    printf("Tape:\n");
    fprintf(output, "Tape:\n");
    int i = 0;
    while(i < tapeSize){
        if(i == head){
            printf("v");
            fprintf(output, "v");
        }else{
            printf("_");
            fprintf(output, "_");
        }
        i++;
    }
    printf("\n");
    fprintf(output,"\n");
    i = 0;
    while(i < tapeSize){
        printf("%c", tape[i]);
        fprintf(output, "%c", tape[i]);
        i++;
    }
    printf("\n");
    fprintf(output,"\n");
}

void printCommand(struct State state, FILE *output){
    printf("Command: ");
    fprintf(output, "Command: ");
    printf("%cq%li-%cq%li|%c", state.inpCh, state.inpQ, state.outCh, state.outQ, state.act);
    fprintf(output, "%cq%li-%cq%li|%c", state.inpCh, state.inpQ, state.outCh, state.outQ, state.act);
    printf("\n");
    fprintf(output,"\n");
}
