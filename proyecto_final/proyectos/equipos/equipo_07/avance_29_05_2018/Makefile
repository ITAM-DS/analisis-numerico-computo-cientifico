# https://www.gnu.org/software/make/manual/make.html
CFLAGS      := -Wall
UNAME       := $(shell uname)
ifeq ($(UNAME),Darwin)
	CFLAGS += -framework Accelerate
endif

all: clean build

clean:
	rm -f ./third_party/csvparser/libcsvparser.so pca libmatrix.so

build: 
	$(CC) $(CFLAGS) -c -o ./third_party/csvparser/libcsvparser.so ./third_party/csvparser/csvparser.c
	$(CC) $(CFLAGS) -c -o ./libmatrix.so ./matrix.c
	$(CC) $(CFLAGS) -o pca pca.c -lm -lblas -llapack -lcsvparser -lmatrix -I./third_party/csvparser -L./third_party/csvparser -I. -L.
	