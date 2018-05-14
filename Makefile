all: main.c lib_lst lib_gs 
	gcc main.c -fPIC -lm -L. libGoldenSectionSearch.so -L. libLists.so -o main 

lib_lst: lists.c lists.h
		gcc -shared -fPIC lists.c -o libLists.so

lib_gs: golden_section_search.h golden_section_search.c
		gcc golden_section_search.c -shared -fPIC -lm -L. libLists.so -o libGoldenSectionSearch.so