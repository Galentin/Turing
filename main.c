#include "input.h"

void inf(){
    printf("Turing simulator\nCommand line format:\nTuring.exe inputTable.txt inputTape.txt output.txt -a [p]/-o"
                   "\n-a run in standard mode\n-o run debug\n p number of steps"
                   "\nFormat commands in inputTable.txt: aqn-bqk|D\na and b - the symbols on the tape\n"
                   "n and k - the states (the first state is always 1, the last state is always 0),\n"
                   "D - the direction of move (L - left, R - right, H - no move)."
                   "\nFormat inputTape.txt:\n_____v____\n.2..39.91.\n"
                   "If you run debug\ns - one step,\nb - break,\ng - go the program in standard mode.\n");
}

int main (int argc, char* argv[]){

    FILE *inputTable;
    FILE *inputTape;
    FILE *output;

    if(argc == 1){
        inf(); //информация о входных данных
        exit(0);
    }

    if(((argc == 5) && (strcmp(argv[4], "-a") == 0 || strcmp(argv[4], "-o") == 0)) ||
        ((argc == 6) && (strcmp(argv[4], "-a") == 0) && (checkInteger(argv[5]) == 1))){

        inputTable = fopen(argv[1], "r");
        if(inputTable == NULL){
            printf("Can't find file %s", argv[1]);
            exit(10);
        }

        inputTape = fopen(argv[2], "r");
        if(inputTape == NULL){
            printf("Can't find file %s", argv[2]);
            exit(10);
        }

        output = fopen(argv[3], "w");
    }else{
        printf("Wrong number of arguments");
        exit(11);
    }

    input(inputTable, inputTape, output, argc, argv);

    return 0;
}
