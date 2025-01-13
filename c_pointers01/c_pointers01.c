#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <malloc.h>
#include <time.h>
#include <math.h>

#include "c_pointers01.h"

int *get_phones_list(int numbers_count){

    int phone_number_value  = 0;
    int phone_number_size   = 7;

    int *phones_list = malloc(numbers_count*4);

    // инициализация rand
    srand(time(0));
    for(int nums_counter = 0; nums_counter < numbers_count; nums_counter++)
    {
    phones_list[numbers_count] = rand()%10000000000+1;
        
        while (phones_list[numbers_count] < 1000000000 || phones_list[numbers_count] > 9999999999  )
        {
            phones_list[numbers_count] = rand()%10000000000+1;
        }
     
        // printf("random number: %d \nsize: %d\n", phone_number_value, sizeof(phone_number_value));
        printf("%d, %d\n", phones_list[numbers_count], phones_list[numbers_count]);
    }

    return phones_list; 
}
    // Генератор псевдослучайного беззнакового целого
    // инициализация rand
    srand(time(NULL));

    for(int i=0;i<number_size;i++) multiplier*=10;
    srand(time(NULL));
    int random_number = rand()%multiplier+1;
    while (random_number < (multiplier/10) || random_number > (multiplier-1) ) {
        random_number = rand()%multiplier+1;
    }
    return random_number;
}


int main(int argc, char **argv)
{
    // todo
    // Задача - разобраться с работой указателей.
    // 1. Как размещать данные в заранее зарезервированном объеме памяти.
    // 2. Как наращивать память при добавлении данных
    // 3. Выделение непрерывного участка памяти

    // параметры акивного терминала
    struct winsize w;

    // cli и все что с этим связано
    char cli_str[255];

    // ээээксперименты!
    // счетчик номеров
    int phone_index = 0;
    // структура для хранения номеров
    struct PersonalData *testData = malloc(sizeof(struct PersonalData));

    if(!testData)
        perror("malloc error");
    
    // printf("%p\n", testData);
    // printf("%ld\n", sizeof(*testData));
    // printf("%d\n", testData->phone_number);
    // printf("%d\n", testData->phone_prefix);
    for(int i=0;i<4000000;i++)
    {
    testData->phone_index = i;
    testData->phone_prefix = get_random_number(3);
    testData->phone_number = get_random_number(7);
    printf("%d. ", testData->phone_index);
    printf("(%d)", testData->phone_prefix);
    printf("%d\n", testData->phone_number);

    }
    exit;

    
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