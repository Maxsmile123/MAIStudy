#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"



int main(int argc, char* argv[])
{
	
    if (argc != 2) {
        printf("Need exactly two arguments\n");
        exit(1);
    }
    if (!strcmp(argv[1], "-a")) {
        add();
    }
    else if (!strcmp(argv[1], "-p")) {
        print();
    }
    else if (!strcmp(argv[1], "-d")) {
        removes();
    }
    else if (!strcmp(argv[1], "-h")) {
        print_help();
    }
    else if (!strcmp(argv[1], "-c")) {
        create();
    }
    else if (!strcmp(argv[1], "-f")) {
        typicalConfigurations();
    }
    else {
        printf("Unknown command\n");
    }
    return 0;

}

void print_help() 
{
    printf("Welcome to the program for working with databases!\nYou have the following options:\n");
    printf("1) Create the database(-c)\n 2) Add an entry to the database(-a)\n3) Print the database(-p)\n");
    printf("4) Delete the database(-d)\n5) Print typical configurations of computers in a group(more than p owners) (-f)\n");
}
