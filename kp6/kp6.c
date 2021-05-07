#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "structure.h"

void create() 
{
    char fileName[40];
    FILE* file;
    printf("Enter the name of the file you want to create:\n");
    scanf("%s", fileName);
    file = fopen(fileName, "rb");
    if (file != NULL) {
        printf("Such file already exists\n");
    } else {
        file = fopen(fileName, "ab");
    }
    printf("Creation was successful!\n");
    fclose(file);
}

void add()
{
    int records;
    char fileName[40];
    FILE* file;
    PC add;
    printf("Enter the name of the file you want to add the records:\n");
    scanf("%s", fileName);
    file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Such file not exists!\n");
    }
    else {
        file = fopen(fileName, "ab");
        printf("Enter how many records do you want to add:\n");
        scanf("%d", &records);
        for (int i = 0; i < records; i++) {
            printf("Enter student's surname:\n");
            scanf("%s", add.surname);
            printf("Enter student's PC number of processors:\n");
            scanf("%d", &add.numberOfProcessors);
            printf("Enter student's PC type of processors:\n");
            printf("1. x32\n2. x64\n");
            scanf("%s", add.typeOfProcessors);
            printf("Enter student's PC cache memory capacity(GB):\n");
            scanf("%d", &add.memoryCapacity);
            printf("Enter student's PC type of video controller:\n");
            printf("1. built-in\n2. external\n3. AGP\n4. PCI\n");
            scanf("%s", add.typeOfVideoController);
            printf("Enter student's PC video memory capacity(GB):\n");
            scanf("%d", &add.videoMemoryCapacity);
            printf("Enter student's PC video memory type(GB):\n");
            printf("1. SCSI/IDE\n2. ATA/SATA\n");
            scanf("%s", add.videoMemoryType);
            printf("Enter student's PC number of hard drives:\n");
            scanf("%d", &add.numberOfHardDrives);
            printf("Enter student's PC capacity of hard drives(GB):\n");
            scanf("%d", &add.capacityOfHardDrives);
            printf("Enter student's PC number of peripherals:\n");
            scanf("%d", &add.peripherals);
            printf("Enter student's PC OC:\n");
            printf("1) Windows\n2) Linux\n3) MacOS\n");
            scanf("%s", add.OC); 
            fwrite(&add, sizeof(PC), 1, file);
	}
            printf("Records added successfully!\n");
            fclose(file);
        }
}

void print() 
{
    char fileName[40];
    printf("Enter the name of the file you want to print:\n");
    scanf("%s", fileName);
    FILE* file;
    PC read;
    file = fopen(fileName, "rb");
    if (file == NULL) {
        printf("Such file not exists\n");
    }
    else {
        printf("|Student's surname|Num Proc|Type of proc|Cache mem|Type video control|Video memory|Video memory type|Num HD|Capacity HD|Num peripherals|OC|\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&read, sizeof(PC), 1, file) != EOF && !feof(file)) {
            printf("|%17s|%8d|%12s|%7dGB|%18s|%10dGB|%17s|%4dGB|%9dGB|%15d|%2s|\n", read.surname, read.numberOfProcessors, read.typeOfProcessors, read.memoryCapacity,
                read.typeOfVideoController, read.videoMemoryCapacity, read.videoMemoryType, read.numberOfHardDrives, read.capacityOfHardDrives,
                read.peripherals, read.OC);
        }
        fclose(file);
    }
}
void removes() 
{
    char fileName[40];
    printf("Enter the name of the file you want to delete:\n");
    scanf("%s", fileName);
    FILE* file;
    file = fopen(fileName, "rb");
    if (!file) {
        printf("Such file not exists!\n");
    }
    else {
        remove(fileName);
        printf("The file was successfully deleted!\n");
        fclose(file);
    }
}
void typicalConfigurations() 
{
    char fileName[40];
    int p;
    printf("Enter the name of the file you want to print typical configurations:\n");
    scanf("%s", fileName);
    printf("Enter 'p':\n");
    scanf("%d", &p);
    FILE* file;
    PC f;
    int count = 0;
    file = fopen(fileName, "rb");
    if (!file) {
        printf("Such file not exists!\n");
    }
    else {
         while (fread(&f, sizeof(PC), 1, file) != EOF && !feof(file)) {
            count++;
        }
        int a[count];
        for(int i = 0; i < count; i++)
            a[i] = 0;
       int counter = 0;
        printf("|Num Proc|Type of proc|Cache mem|Type video control|Video memory|Video memory type|Num HD|Capacity HD|Num peripherals|OC|\n");
                printf("----------------------------------------------------------------------------------------------------------------------\n");
       while(checker(a,count)){
           fseek(file,0,SEEK_SET);
           int flag = 0; // cicly 'for' for files
           int cur1 = 0;
           PC exemplar = {0};
           while (fread(&f, sizeof(PC), 1, file) != EOF && !feof(file)) {
                if(a[cur1]){
                    cur1++;
                    continue;
                }
                if(!flag){
                exemplar.numberOfProcessors = f.numberOfProcessors;
                exemplar.memoryCapacity = f.memoryCapacity;
                exemplar.videoMemoryCapacity = f.videoMemoryCapacity;
                exemplar.numberOfHardDrives = f.numberOfHardDrives;
                exemplar.capacityOfHardDrives = f.capacityOfHardDrives;
                exemplar.peripherals = f.peripherals;
                strcat(exemplar.typeOfProcessors, f.typeOfProcessors);
                strcat(exemplar.typeOfVideoController, f.typeOfVideoController);
                strcat(exemplar.videoMemoryType, f.videoMemoryType);
                strcat(exemplar.OC, f.OC);
                flag = 1;
                }
                if(equals(exemplar,f)){
                    a[cur1] = 1;
                    counter++;
                }
                cur1++;
           }
           if(counter > p){
                printf("|%8d|%12s|%7dGB|%18s|%10dGB|%17s|%4dGB|%9dGB|%15d|%2s|\n",exemplar.numberOfProcessors, exemplar.typeOfProcessors, exemplar.memoryCapacity,
                        exemplar.typeOfVideoController, exemplar.videoMemoryCapacity, exemplar.videoMemoryType, exemplar.numberOfHardDrives, exemplar.capacityOfHardDrives,
                        exemplar.peripherals, exemplar.OC);
           }
           counter = 0;
       }       
    }
}

int checker(int *a, int n)
{
    for(int i = 0; i < n; i++)
        if(a[i] == 0) return 1;
    return 0;
}

int equals(PC p, PC c)
{
    if((p.numberOfProcessors == c.numberOfProcessors) && (p.memoryCapacity == c.memoryCapacity) &&
    (p.videoMemoryCapacity == c.videoMemoryCapacity) && (p.numberOfHardDrives == c.numberOfHardDrives) &&
    (p.capacityOfHardDrives == c.capacityOfHardDrives) && (p.peripherals == c.peripherals) && 
    (!strcmp(p.typeOfProcessors, c.typeOfProcessors)) && (!strcmp(p.typeOfVideoController, c.typeOfVideoController))
    && (!strcmp(p.videoMemoryType, c.videoMemoryType)) && (!strcmp(p.OC, c.OC))) return 1;
    else return 0;
}
