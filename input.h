#ifndef INPUT_H_INCLUDED
#define INPUT_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

struct State{
        char inpCh;
        long int inpQ;
        char outCh;
        long int outQ;
        char act;
};

int input(FILE *inputTable, FILE *inputTape, FILE *output, int argc, char *argv[]);

int checkInteger(char step[]);

int searchState(struct State *arrayTable, int arraySize, long int lastState, char *tape, int head);

void printTape(char *tape, int head, int tapeSize, FILE *output);

void errorCommand(char *arg, int line, char symbolError, char symbol);

void printCommand(struct State state, FILE *output);

void step(int head, char *tape, struct State *arrayTable, int arraySize, int realTapeSize, int maxTapeSize, int numberSteps,FILE *output,int flag);

#endif // INPUT_H_INCLUDED
