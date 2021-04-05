all:
	-g++ -c -w ./*/*.h ./*/*.cpp -O2 -std=c++17
	-mkdir .compiled
	-mv ./*/*.gch ./.compiled/ 
	-mv *.o .compiled/
	-g++ -w main.cpp -o main -O2 -std=c++17

.PHONY: clean

clean:
	-rm -f -r .compiled
	-rm -f main

