#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

#include "random01.h"

int main(int argc, char **argv)
{
    // 79991234567 (11)
    // < 1000000
    int number_rate        = 999999;
    int phone_number_value =  0;
    int phone_number_size  = 7;
    //arc4random_buf(phone_number_value,phone_number_size);
    
    // инициализация rand
    srand(time(0));
    for(int nums_counter = 0; nums_counter < 100; nums_counter++)
    {
    phone_number_value = rand()%10000000000+1;
    while (phone_number_value < 1000000000 || phone_number_value > 9999999999  )
    {
        phone_number_value = rand()%10000000000+1;
    }
       
       
    //    printf("random number: %d \nsize: %d\n", phone_number_value, sizeof(phone_number_value));
    printf("%d,", phone_number_value);
    }

}