#include "input.h"

void step(int head, char *tape, struct State *arrayTable, int arraySize, int realTapeSize, int maxTapeSize, int numberSteps,FILE *output,int flag){
    long int lastState = 1;
    while(lastState != 0 && numberSteps != 0){
        int i = searchState(arrayTable, arraySize, lastState, tape, head);
        tape[head] = arrayTable[i].outCh;
        lastState = arrayTable[i].outQ;
        if(arrayTable[i].act == 'L'){
            head --;
        }else if(arrayTable[i].act == 'R'){
            head++;
        }
        if(head < 0){
            printf("Head index out of bounds\n");
            exit(22);
        }
        if(head == realTapeSize){
            tape[head] = '.';
            realTapeSize++;
            if(head == maxTapeSize){
            maxTapeSize++;
            tape = (char*)realloc(tape,maxTapeSize * sizeof(char));
            }
        }
        numberSteps--;
        printCommand(arrayTable[i], output);
        printTape(tape, head, realTapeSize, output);

        if (flag == 1) {
            char comand[2]; //сюда будет записана команда
            while (1) {
                scanf(" %2s", comand);
                fflush(stdin); //очистка буфера
                if (!strcmp(comand, "b")) {
                    printf("Program break\n");
                    fclose(output);
                    exit(0);
                }
                if (!strcmp(comand, "s")) {
                    break;
                }
                if (!strcmp(comand, "g")) {
                    flag = 0;
                    break;
                } else printf("No such instruction. Enter other\n");
            }
        }
    }
}
