#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>
#include <string.h>

#include "compress01.h"

int main(int argc, char **argv)
{
    // Постановка задачи.
    // Есть поток, состоящий из байтов, от 0 до 255. Конечный размер не известен, содержимое тоже. 
    // Нужно макимально эффективно сжимать входящий поток без потерь и записывать в файл.

    // todo:
    // Прочитать файл ~1-2GB в память
    FILE *file;
    long incoming_file_size = 0;
    unsigned char *filename = "/opt/testdata/Master.csv";
    

    file = fopen(filename, "rb");
    if (file == NULL){
        printf("ERROR: Can't open file %s\n", filename);
        return -1;
    }
    
    fseek(file, 0, SEEK_END);
    incoming_file_size = ftell(file);
    rewind(file);
    printf("File:  %s\n", filename);
    printf("Size:  %ld bytes\n", incoming_file_size);

    printf("Memory allocation... ");
    void *file_in_memory = malloc(incoming_file_size + 1);
    if(!file_in_memory) perror("malloc error");
    printf("ok. \n");

    printf("Reading file... ");
    size_t bytes_read = fread(file_in_memory, 1, incoming_file_size, file);
    if (bytes_read != incoming_file_size) {
        fprintf(stderr, "Ошибка чтения файла\n");
        free(file_in_memory);
        fclose(file);
        perror("Cant'read file into memory\n");
        return -1 ;
    }
    printf("ok. \n");
    fclose(file);

    // command line
    char line[100];
    printf("cmd >  ");
    fgets(line, sizeof(line), stdin); // Ожидаем ввод строки

    
    line[strcspn(line, "\n")] = 0;

    printf("Вы ввели: %s\n", line);
    free(file_in_memory);


    //printf("long = %d\n", sizeof(long));
    return 0;
}