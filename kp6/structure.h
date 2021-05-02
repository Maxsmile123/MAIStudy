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
	char typeOfProcessors[5]; // 1 - x32, 2 - x64
	int memoryCapacity;
	char typeOfVideoController[10]; // 1 - built-in, 2 - external, 3 - AGP, 4 - PCI
	int videoMemoryCapacity;
	char videoMemoryType[10]; // SCSI/IDE(1) or ATA/SATA(2)
	int numberOfHardDrives;
	int capacityOfHardDrives; 
	int peripherals;
	char OC[9]; // 1 - windows, 2 - linux, 3 - macOS
} PC;

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
    char fileName[40];
    int records;
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
            printf("Enter student's PC memory capacity:\n");
            scanf("%d", &add.memoryCapacity);
            printf("Enter student's PC type of video controller:\n");
            printf("1. built-in\n2. external\n3. AGP\n4. PCI\n");
            scanf("%s", add.typeOfVideoController);
            printf("Enter student's PC video memory capacity:\n");
            scanf("%d", &add.videoMemoryCapacity);
            printf("Enter student's PC video memory type:\n");
            printf("1. SCSI/IDE\n2. ATA/SATA\n");
            scanf("%s", add.videoMemoryType);
            printf("Enter student's PC number of hard drives:\n");
            scanf("%d", &add.numberOfHardDrives);
            printf("Enter student's PC capacity of hard drives:\n");
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
        printf("|Student's surname|Num Proc|Type of proc|Memory|Type video control|Video memory|Video memory type|Num HD|Capacity HD|Num peripherals|OC|\n");
        printf("-------------------------------------------------------------------------------------------------------------------------------\n");
        while (fread(&read, sizeof(PC), 1, file) != EOF && !feof(file)) {
            printf("|%17s|%8d|%12s|%6d|%18s|%12d|%17s|%6d|%11d|%15d|%2s|\n", read.surname, read.numberOfProcessors, read.typeOfProcessors, read.memoryCapacity,
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
    printf("Enter the name of the file you want to print typical configurations:\n");
    scanf("%s", fileName);
    FILE* file;
    PC f;
    PC exemplar;
    file = fopen(fileName, "rb");
    if (!file) {
        printf("Such file not exists!\n");
    }
    else {
        int sum[6];
        for (int i = 0; i < 6; i++)
            sum[i] = 0;
        /* 0) numberOfProcessors
        *  1) memoryCapacity
        *  2) videoMemoryCapacity
        *  3) numberOfHardDrives
        *  4) capacityOfHardDrives
        *  5) peripherals
        */
        int counterChars[11];
        for (int i = 0; i < 11; i++)
            counterChars[i] = 0;
        /* 0) x32
        *  1) x64
        *  2) built-in
        *  3) external
        *  4) AGP
        *  5) PCI
        *  6) SCSI/IDE
        *  7) ATA/SATA
        *  8) Windows
        *  9) Linux
        * 10) MacOS
        */
        int count = 0; // Number of records
        while (fread(&f, sizeof(PC), 1, file) != EOF && !feof(file)) {
            sum[0] += f.numberOfProcessors;
            sum[1] += f.memoryCapacity;
            sum[2] += f.videoMemoryCapacity;
            sum[3] += f.numberOfHardDrives;
            sum[4] += f.capacityOfHardDrives;
            sum[5] += f.peripherals;
            if (f.typeOfProcessors == "x32") counterChars[0]++;
            if (f.typeOfProcessors == "x64") counterChars[1]++;
            if (f.typeOfVideoController == "built-in") counterChars[2]++;
            if (f.typeOfVideoController == "external") counterChars[3]++;
            if (f.typeOfVideoController == "AGP") counterChars[4]++;
            if (f.typeOfVideoController == "PCI") counterChars[5]++;
            if (f.videoMemoryType == "SCSI/IDE") counterChars[6]++;
            if (f.videoMemoryType == "ATA/SATA") counterChars[7]++;
            if (f.OC == "Windows") counterChars[8]++;
            if (f.OC == "Linux") counterChars[9]++;
            if (f.OC == "MacOS") counterChars[10]++;
            count++;
        }
        int mins[6];
        for (int i = 0; i < 6; i++)
            mins[i] = INT_MAX;
        while (fread(&f, sizeof(PC), 1, file) != EOF && !feof(file)) {
            if (abs(f.numberOfProcessors - sum[0] / count) < mins[0]) {
                mins[0] = abs(f.numberOfProcessors - sum[0] / count);
                exemplar.numberOfProcessors = f.numberOfProcessors;
            }
            if (abs(f.memoryCapacity - sum[1] / count) < mins[1]) {
                mins[1] = abs(f.memoryCapacity - sum[1] / count);
                exemplar.memoryCapacity = f.memoryCapacity;
            }
            if (abs(f.videoMemoryCapacity - sum[2] / count) < mins[2]) {
                mins[2] = abs(f.videoMemoryCapacity - sum[2] / count);
                exemplar.videoMemoryCapacity = f.videoMemoryCapacity;
            }
            if (abs(f.numberOfHardDrives - sum[3] / count) < mins[3]) {
                mins[3] = abs(f.numberOfHardDrives - sum[3] / count);
                exemplar.numberOfHardDrives = f.numberOfHardDrives;
            }
            if (abs(f.capacityOfHardDrives - sum[4] / count) < mins[4]) {
                mins[4] = abs(f.capacityOfHardDrives - sum[4] / count);
                exemplar.capacityOfHardDrives = f.capacityOfHardDrives;
            }
            if (abs(f.peripherals - sum[5] / count) < mins[5]) {
                mins[5] = abs(f.peripherals - sum[5] / count);
                exemplar.peripherals = f.peripherals;
            }
        }
        if (counterChars[0] >= counterChars[1]) strcat(exemplar.typeOfProcessors, "x32");
        else strcat(exemplar.typeOfProcessors, "x64");
        int max = 0;
        int max_i = 2;
        for (int i = 2; i < 6; i++)
            if (counterChars[i] > max) {
                max = counterChars[i];
                max_i = i;
            }
        if (max_i == 2) strcat(exemplar.typeOfProcessors, "built-in");
        if (max_i == 3) strcat(exemplar.typeOfVideoController, "external");
        if (max_i == 4) strcat(exemplar.typeOfVideoController, "AGP");
        if (max_i == 5) strcat(exemplar.typeOfVideoController, "PCI");
        if (counterChars[6] >= counterChars[7]) strcat(exemplar.videoMemoryType, "SCSI/IDE");
        else strcat(exemplar.videoMemoryType, "ATA/SATA");
        max = 0;
        max_i = 8;
        for (int i = 8; i < 11; i++)
            if (counterChars[i] > max) {
                max = counterChars[i];
                max_i = i;
            }
        if (max_i == 8) strcat(exemplar.OC, "Windows");
        if (max_i == 9) strcat(exemplar.OC, "Linux");
        if (max_i == 10) strcat(exemplar.OC, "MacOS");

        printf("|Num Proc|Type of proc|Memory|Type video control|Video memory|Video memory type|Num HD|Capacity HD|Num peripherals|OC|\n");
        printf("----------------------------------------------------------------------------------------------------------------------\n");
       
        printf("|%17s|%8d|%12s|%6d|%18s|%12d|%17s|%6d|%11d|%15d|%2s|\n",exemplar.numberOfProcessors, exemplar.typeOfProcessors, exemplar.memoryCapacity,
                exemplar.typeOfVideoController, exemplar.videoMemoryCapacity, exemplar.videoMemoryType, exemplar.numberOfHardDrives, exemplar.capacityOfHardDrives,
                exemplar.peripherals, exemplar.OC);
        
        fclose(file);
    }
}
#endif

