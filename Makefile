all:
	gcc libstr.h -o libstr
test:
	make all
	gcc examples/basic_fc.c -o test
	./test
clean:
	rm libstr
	rm test
