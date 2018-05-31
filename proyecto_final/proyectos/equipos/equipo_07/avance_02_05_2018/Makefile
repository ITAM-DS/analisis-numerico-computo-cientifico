# https://www.gnu.org/software/make/manual/make.html
CFLAGS      := -Wall

all: clean build

clean:
	rm -f ./third_party/csvparser/libcsvparser.so pca

build: 
	$(CC) $(CFLAGS) -c -o ./third_party/csvparser/libcsvparser.so ./third_party/csvparser/csvparser.c
	$(CC) $(CFLAGS) -o pca pca.c -lm -lcsvparser -I./third_party/csvparser -L./third_party/csvparser
