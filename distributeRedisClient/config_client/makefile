
obj = main.o Config_client.o

run : $(obj)
	g++ -o run $(obj)

main.o : Config_client.h
Config_client.o : Redis_node.h

.PHONY : clean
clean:
	rm run $(obj)
