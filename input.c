#include "input.h"

int input(FILE *inputTable, FILE *inputTape, FILE *output, int argc, char *argv[]){
    // чтение таблицы состояний из файла

    char lastChar; // символ на ленте
    char lastState;
    long int lastStateNum; // состояние в котором находится лента
    char dash;
    char newChar; // символ, который нужно записать
    char newState;
    long int newStateNum; // состояние, в которе должна перейти лента
    char pipeline;
    char move; // сдвиг указателя
    int maxArraySize = 10, realArraySize = 0; //размер табилицы состояний

    struct State *arrayTable;
    arrayTable = (struct State*)malloc(maxArraySize*sizeof(struct State));
    if(arrayTable == NULL){
        printf("Memory allocation error");
        exit(20);
    }

    int j = 0;
    while((j = fscanf(inputTable, " %c %c %li %c %c %c %li %c %c", &lastChar, &lastState, &lastStateNum, &dash, &newChar, &newState, &newStateNum, &pipeline, &move)) != EOF){
        if(j != 9){
            printf("Wrong number of input chars");
            exit(12);
        }
        if(lastState != 'q'){
            errorCommand(argv[1], realArraySize, lastState, 'q');
        }
        if(newState != 'q'){
            errorCommand(argv[1], realArraySize, newState, 'q');
        }
        if(dash != '-'){
            errorCommand(argv[1], realArraySize, dash, '-');
        }
        if(pipeline != '|'){
           errorCommand(argv[1], realArraySize, pipeline, '|');
        }
        if(move != 'L' && move != 'R' && move != 'H') {
            printf("Wrong move command \"%c\"", move);
            exit(14);
        }
        if(lastStateNum < 0 || newStateNum < 0){
            printf("The state can not be negative");
            exit(15);
        }
        if(realArraySize == maxArraySize){
            maxArraySize = maxArraySize + 10;
            arrayTable = (struct State*)realloc(arrayTable,maxArraySize * sizeof(struct State));
            if(arrayTable == NULL){
               printf("Memory allocation error");
               exit(20);
            }
        }
        arrayTable[realArraySize].inpCh = lastChar;
        arrayTable[realArraySize].inpQ = lastStateNum;
        arrayTable[realArraySize].outCh = newChar;
        arrayTable[realArraySize].outQ = newStateNum;
        arrayTable[realArraySize].act = move;
        realArraySize++;
    }
    if(realArraySize == 0){
        printf("No input data in %s\n", argv[1]);
        exit(16);
    }
    fclose(inputTable);

    //определение расположения указателя на ленте
    int headSize = 0, numberHeads = 0, head;
    char symbol;

    while(((symbol = fgetc(inputTape)) != '\n')){
        if(symbol == EOF){
            printf("No input data in %s\n", argv[2]);
            exit(16);
        }
        if(symbol != '_' && symbol != 'v'){
            printf("Invalid character \"%c\" in %s line 1\n", symbol, argv[2]);
            exit(17);
        }
        if(symbol == 'v'){
            numberHeads++;
            head = headSize;
        }
        headSize++;
    }
    if(numberHeads != 1){
        if(numberHeads == 0){
            printf("Can not find the head in %s\n", argv[2]);
        }else{
            printf("Several head in %s\n", argv[2]);
        }
        exit(18);
    }

    //чтение ленты из файла
    int maxTapeSize = 10, realTapeSize = 0; //длина ленты
    char *tape;
    tape = (char*)malloc(maxTapeSize*sizeof(char));
    if(tape == NULL){
        printf("Memory allocation error");
        exit(20);
    }
    while((tape[realTapeSize] = fgetc(inputTape)) != EOF){
        if(realTapeSize == maxTapeSize - 1){
            maxTapeSize++;
            tape = (char*)realloc(tape,maxTapeSize * sizeof(char));
            if(tape == NULL){
                printf("Memory allocation error");
                exit(20);
            }
        }
        realTapeSize++;
    }
    if(headSize != realTapeSize){
        printf("Lines length mismatch in the file %s\n", argv[2]);
        exit(19);
    }
    fclose(inputTape);

    printTape(tape, head, realTapeSize, output);

    int numberSteps;
    if(argc == 6){
        numberSteps = strtol(argv[5], NULL, 10);
    }else{
        numberSteps = 1000;
    }
    int flag = 0;
    if(strcmp(argv[4], "-o") == 0){
        flag = 1;
    }

    step(head, tape, arrayTable, realArraySize, realTapeSize, maxTapeSize, numberSteps, output, flag);

    fclose(output);
    free(arrayTable);
    free(tape);
}
