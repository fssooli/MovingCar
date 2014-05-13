CC=g++
CFLAGS=-O3
macosx:
	$(CC) SphereWorld.cpp -o MovingCar $(CFLAGS) -DMACOSX -framework GLUT -framework OpenGL