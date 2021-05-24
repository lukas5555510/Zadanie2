#makefile

vpath %.h include

Code2: Code2.c capacity.so area.a
	gcc -o $@ $^ -I ./include

area.o: area.c
	gcc -c $<
cuboid_area.o: cuboid_area.c
	gcc -c $<
capacity.o: capacity.c
	gcc -fPIC -c $<
area.a: area.o cuboid_area.o
	ar -rs $@ $^
capacity.so: capacity.o
	gcc -shared -o $@ $^

clean:
	rm -f Code2 *.o *.a *.so
