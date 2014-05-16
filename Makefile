CC=g++
CFLAGS=-O3
SRC=libbmpread/bmpread.c
macosx:
	$(CC) SphereWorld.cpp $(SRC) -o MovingCar $(CFLAGS) -DMACOSX -framework GLUT -framework OpenGL