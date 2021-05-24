#makefile

.SUFFIXES: .o

vpath %.h include
vpath %.c src
vpath %.so lib
vpath %.a lib

%.o: %.c
	gcc -c $<

area.o: area.c
cuboid_area.o: cuboid_area.c
capacity.o: capacity.c
	gcc -fPIC -c $<
area.a: area.o cuboid_area.o
	ar -rs $@ $^
capacity.so: capacity.o
	gcc -shared -o $@ $^

install: Code2.c capacity.so area.a
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:./:./include:./lib/
	gcc -o Code2 $^ -I ./include -L ./lib/

uninstall:
	rm -f Code2 *.o ./lib/*.a ./lib/*.so
