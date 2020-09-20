cc = gcc
prom=test
obj=add.o test.o
$(prom): $(obj)
	$(cc) -o $(prom)  $(obj)
%.o :%.c %.h
	$(cc) -c $< -o $@
clean:
	rm -f *.o