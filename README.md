# Turing simulator
Command line format: Turing.exe inputTable.txt inputTape.txt output.txt -a [p]/-o

-a run in standard mode

-o run debug

p number of steps

Format commands in inputTable.txt: aqn-bqk|D

a and b - the symbols on the tape

n and k - the states (the first state is always 1, the last state is always 0)

D - the direction of move (L - left, R - right, H - no move).

Format inputTape.txt: 

`____v_____`

`.2..39.91.`

If you run debug:

s - one step

b - break

g - go the program in standard mode.
