all:
	gcc -c src/point.c src/table.c src/robot.c
	gcc toyrobot.c point.o table.o robot.o -o toyrobot -lm -pthread -lgmp -lreadline

clean:
	rm *.o toyrobot
