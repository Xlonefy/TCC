CC = picc
FLAGS = --chip=16F883 --outdir=out/

_DEPS = servo.h thermal.h
DEPS = $(patsubst %, src/%, $(_DEPS))

main: $(DEPS)
	$(CC) src/main.c $(FLAGS)

clean:
	rm -rf out/*