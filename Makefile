test:	int-O0.exe int-O3.exe \
		long-O0.exe long-O3.exe \
		long-long-O0.exe long-long-O3.exe
		./int-O0.exe
		./int-O3.exe
		./long-O0.exe
		./long-O3.exe
		./long-long-O0.exe
		./long-long-O3.exe

clean:
		@- rm *.exe

int-O0.exe:	int.c
		$(CC) -o int-O0.exe -O0 int.c

int-O3.exe:	int.c
		$(CC) -o int-O3.exe -O3 int.c


long-O0.exe:	long.c
		$(CC) -o long-O0.exe -O0 long.c

long-O3.exe:	long.c
		$(CC) -o long-O3.exe -O3 long.c


long-long-O0.exe:	long-long.c
		$(CC) -o long-long-O0.exe -O0 long-long.c

long-long-O3.exe:	long-long.c
		$(CC) -o long-long-O3.exe -O3 long-long.c

