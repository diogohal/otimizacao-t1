all: producao.o
	gcc producao.o -o producao 

producao.o: producao.c
	gcc -c producao.c

run: all
	./producao < entrada_teste.lp && cat modelagem.lp 

clean:
	rm -f *.o *.temp

purge: clean
	rm -f producao
