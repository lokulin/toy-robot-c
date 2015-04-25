all:
	gcc -Wall -Werror -ansi -g -c src/point.c src/table.c src/robot.c src/util.c src/robotrunner.c
	gcc -Wall -Werror -ansi -g toyrobot.c point.o table.o robot.o util.o robotrunner.o -o toyrobot -lm

clean:
	rm *.o toyrobot
