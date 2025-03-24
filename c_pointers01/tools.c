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
void
*get_random_number(unsigned char num_size)
{
    void *random_number = malloc(num_size);
    FILE *urandom_file;
    
    if( (urandom_file = fopen("/dev/urandom", "r")) == NULL)
    {
        printf("Opening file error\n\n\n");
        exit(1);
    }

    int bytes_read = fread(random_number, 1, num_size, urandom_file) ;
    
    printf("bytes readed: %d\n", bytes_read);

    // for( char i = 0; i < num_size; i++ ) {
    //     printf("i: %d\taddr: %p\t value: %d\n", i, random_number+i, *((unsigned char *)(random_number+i)));
    // }
    
    fclose(urandom_file);

    // printf("addr: %p\trandom_number = %lu\n", random_number, *(unsigned long*)random_number);
    return (void*)random_number;
}
