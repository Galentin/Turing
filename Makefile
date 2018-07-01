Turing.exe : main.o input.o output.o help_function.o step.o

	gcc -o Turing main.o input.o output.o help_function.o step.o

main.o : main.c

	gcc -std=c11 -pedantic -Wall -Wextra -c -o main.o main.c

input.o : input.c

	gcc -std=c11 -pedantic -Wall -Wextra -c -o input.o input.c

output.o : output.c

	gcc -std=c11 -pedantic -Wall -Wextra -c -o output.o output.c
help_function.o : help_function.c

	gcc -std=c11 -pedantic -Wall -Wextra -c -o help_function.o help_function.c

step.o : step.c

	gcc -std=c11 -pedantic -Wall -Wextra -c -o step.o step.c