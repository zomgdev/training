#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <malloc.h>
#include <time.h>
#include <math.h>
#include <fcntl.h>

#include "c_pointers01.h"

// Просто читаем unsigned int из /dev/urandom
// .. но это не точно
unsigned int get_random_int(){
    unsigned char *random_number = malloc(4);
    unsigned int  *random_int;// = malloc(4);
    FILE *urandom_file;
    
    if( (urandom_file = fopen("/dev/urandom", "r")) == NULL)
    {
        printf("Opening file error\n\n\n");
        exit(1);
    }

    int bytes_read = fread(random_number, 1, 4, urandom_file) ;
    
    printf("bytes readed: %d\n", bytes_read);
    for(char i=0;i<4;i++)
        printf("i: %d\taddr: %p\t value: %d\n", i, random_number+i, *(random_number+i));
    
    fclose(urandom_file);
    // for(int i=0;i<4;i++) printf("%d ", *random_bytes[i]);
    // printf("\n");
    // printf("%d %d %d %d\n", *random_bytes[0], *random_bytes[1], *random_bytes[2], *random_bytes[3]);
    // sscanf(random_bytes, "%d", &random_number);
    random_int = (int*)(random_number+0);

    printf("addr: %ls\trandom_int = %d\n", random_int, *random_int);
    return *random_int;
}

int test()
{
    int test;
    test = 124;

    printf("test called: %d\n", test);
    
    return test;
}

int main(int argc, char **argv)
{
    // todo
    // Задача - разобраться с работой указателей.
    // 1. Как размещать данные в заранее зарезервированном объеме памяти.
    // 2. Как наращивать память при добавлении данных
    // 3. Выделение непрерывного участка памяти

    // Телефонный номер:
    // префикс - 3
    // тело    - 7
    // если рандомное число меньше 7 знаков, то дополняем нулями

    // параметры акивного терминала
    struct winsize w;

    // cli и все что с этим связано
    char cli_str[255];


    // структура для хранения номеров
    struct PersonalData *testData = malloc(sizeof(struct PersonalData));


    if(!testData)
        perror("malloc error");
    
    // Размеры
    printf("Sizing...\n");
    printf("char          - %lu\t unsigned char      - %lu\n", sizeof(char), sizeof(unsigned char));
    printf("int           - %lu\t unsigned int       - %lu\t short int       - %lu\n", sizeof(int),  sizeof(unsigned int), sizeof(short int));
    printf("long          - %lu\t unsigned long      - %lu\n", sizeof(long), sizeof(unsigned long));
    printf("long long     - %lu\t unsigned long long - %lu\n", sizeof(long long), sizeof(unsigned long long));
    printf("unsigned      - %lu\n", sizeof(unsigned));
    printf("\n\n");

    // Просто набор чисел для тестирования endians.
    unsigned int TestNums[] = {0,1,255,256,65535,65536,16777216,482976324};
    char *filename[] = {"./testfile.bin"};
    // Открываем файл на запись
    FILE *testfile = fopen("./testfile.bin", "w+");
    fwrite(&TestNums, 4, 8, testfile);
    fclose(testfile);

    // Тест преобразования массива char в int
    // char *charr[] = {255,255,255,0};
    unsigned char *charvar = malloc(4); 
    unsigned int  *intvar  = malloc(4);

    *intvar = 256;
    *(charvar+0) = 255;
    *(charvar+1) = 255;
    *(charvar+2) = 0;
    *(charvar+3) = 0;

    // printf("charr    = %p\n", charr);
    // printf("*charr   = %hhn\n", *charr);
    // printf("sizeof(charr) %lu\n", sizeof(charr));
    
    printf("charvar\n");

    for(char i=0; i<4; i++) 
        printf("charvar: %p\t *charvar + %d = %d\n", charvar+i, i, *(charvar+i));

    printf("intvar  = %p\n", intvar);
    printf("*intvar  = %d\n", *intvar);
    printf("sizeof(intvar) %lu\n", sizeof(*intvar));

    *intvar = *((int *)(charvar+0));
    
    printf("char2int - %d\n\n", *intvar);
    // Тестирование самописной функции рандома
    unsigned int dd;
    // *dd = test();

    dd = get_random_int();
    printf("> %u\n\n", dd);
    
   

    // memory_buffer[10] = 123;
    // for(int i=0; i<100; i++)
    // {
    //     printf("%d\t %p %d\n", i, *memory_buffer+i, &memory_buffer[i]);
    // }

    // выводим дампик памяти
    // show_mem(&memory_buffer);

    // А это наша мощная командная строфа!
    // while (1) 
    // { 
    //     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
    //     printf ("lines: %d columns %d\n", w.ws_row, w.ws_col);
    //     printf("cmd: ");
    //     scanf("%s", cli_str); 
    //     // printf(">>>%s\n", &cli_str);
    // }

}
// void show_mem(char *mem_pointer)
// {
//     struct winsize w; 
//     ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
//     // rows w.ws_row
//     // cols w.ws_col
//     int current_row = 0;
//     int current_col = 0;
    
//     // for(int mem_offset = 0; mem_offset < 1000; mem_offset++ )
//     mem_pointer = 123;

//     printf("Curent mem_pointer addr: %p\n", *mem_pointer);
//     printf("Curent mem_pointer value: %d\n", mem_pointer);
//     for(int printed_rows = w.ws_row-6; printed_rows > 0; printed_rows--) 
//     {
        
//         printf("Addr: %p value: %d ", (char *)mem_pointer, (char )mem_pointer);
//         // for(int current_col = 0; current_col < w.ws_col / 4 - 20; current_col++)
//         // {
//         //     printf("()%d\t", (char)&mem_pointer);
//         //     mem_pointer = (char *)mem_pointer+1;
//         // }
//         mem_pointer = (char *)mem_pointer+1;
//         printf("\n");
//     }
// }