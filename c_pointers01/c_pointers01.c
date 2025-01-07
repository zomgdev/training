#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

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
int main(int argc, char **argv)
{
    // todo
    // Задача - разобраться с работой указателей.
    // 1. Как размещать данные в заранее зарезервированном объеме памяти.
    // 2. Как наращивать память при добавлении данных
    // 3. Выделение непрерывного участка памяти

    int user_input = 0;

    printf("Press enter...");
    sscanf("%d", &user_input);

}