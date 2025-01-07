#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "compress01.h"

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

    return *phones_list;
}
int main(int argc, char **argv)
{
    // todo:
    // Постановка задачи.
    // Есть поток, состоящий из байтов, от 0 до 255. Конечный размер не известен, содержимое тоже. 
    // Нужно макимально эффективно сжимать входящий поток без потерь и записывать в файл.

    int number_rate         = 999999;
    
    // Сначала генерируем тестовый набор данных. Пусть это будет последовательность телефонных номеров, размером 1МБ.
    int *phones_list = get_phones_list(1000);

    //printf("long = %d\n", sizeof(long));

}