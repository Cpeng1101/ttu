agent-server: agent-server.o agent-manage.o
	gcc -o $@ $^ -lpthread

%.o : %.c
	gcc -c -o $@ $<

clean :
	rm *.o
