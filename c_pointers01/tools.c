#include <stdio.h>
#include <stdlib.h>

// Мелкие вспомогательные функции
void print_sizing()
{
    // Размеры
    printf("Sizing...\n");
    printf("char          - %lu\t unsigned char      - %lu\n", sizeof(char), sizeof(unsigned char));
    printf("int           - %lu\t unsigned int       - %lu\t short int       - %lu\n", sizeof(int),  sizeof(unsigned int), sizeof(short int));
    printf("long          - %lu\t unsigned long      - %lu\n", sizeof(long), sizeof(unsigned long));
    printf("long long     - %lu\t unsigned long long - %lu\n", sizeof(long long), sizeof(unsigned long long));
    printf("unsigned      - %lu\n", sizeof(unsigned));
    printf("\n\n");
}

// Просто читаем unsigned int из /dev/urandom
// .. но это не точно
void* get_random_number(char num_size){
    unsigned char *random_number = malloc(num_size);
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

    random_int = (int*)(random_number+0);

    printf("addr: %ls\trandom_int = %d\n", random_int, *random_int);
    return *random_int;
}
