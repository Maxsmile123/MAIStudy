#ifndef structure_h
#define structure_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

typedef struct 
{
	char surname[50];
	int numberOfProcessors;
	char typeOfProcessors[4]; // 1 - x32, 2 - x64
	int memoryCapacity;
	char typeOfVideoController[9]; // 1 - built-in, 2 - external, 3 - AGP, 4 - PCI
	int videoMemoryCapacity;
	char videoMemoryType[9]; // SCSI/IDE(1) or ATA/SATA(2)
	int numberOfHardDrives;
	int capacityOfHardDrives; 
	int peripherals;
	char OC[8]; // 1 - windows, 2 - linux, 3 - macOS
} PC;

void create(); 
void add();
void print(); 
void removes(); 
void typicalConfigurations();
int checker(int *a, int n);
int equals(PC p, PC c);


#endif
