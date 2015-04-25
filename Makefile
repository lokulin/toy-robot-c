all:
	gcc -Wall -Werror -ansi -g -c src/point.c src/table.c src/robot.c src/util.c
	gcc -Wall -Werror -ansi -g toyrobot.c point.o table.o robot.o util.o -o toyrobot -lm -pthread -lgmp -lreadline

clean:
	rm *.o toyrobot
