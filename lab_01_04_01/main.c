#include<stdio.h>

#define OK 0

#define ROOMS_IN_THE_BUILDING 36
#define ROOMS_IN_THE_FLOOR 4


/**
 *@brief Функция получения подъезда.
 *
 *@return Номер подъезда.
 */
unsigned int getting_entrance(unsigned int room);

/**
 *@brief Функция получения этажа.
 *
 *@return Номер подъезда.
 */
unsigned int getting_floor(unsigned int room);

int main(void)
{
    unsigned int room = 0;
    printf("Введите, пожалуйста, номер комнаты: ");
    scanf("%u", &room);

    unsigned int entrance = getting_entrance(room);
    unsigned int floor = getting_floor(room);

    printf("Номер подъезда и этажа соответственно: %u %u ", entrance, floor);
    return OK;
}

unsigned int getting_entrance(unsigned int room)
{
    unsigned int entrance;
    if (room % ROOMS_IN_THE_BUILDING != 0)
        entrance = (room / (ROOMS_IN_THE_BUILDING)) + 1;
    else
        entrance = (room / (ROOMS_IN_THE_BUILDING));
    return entrance;
}

unsigned int getting_floor(unsigned int room)
{
    unsigned int floor;
    if (room % ROOMS_IN_THE_FLOOR != 0)
        floor = (room - (getting_entrance(room) - 1) * ROOMS_IN_THE_BUILDING) / ROOMS_IN_THE_FLOOR + 1;
    else
        floor = (room - (getting_entrance(room) - 1) * ROOMS_IN_THE_BUILDING) / ROOMS_IN_THE_FLOOR;
    return floor;
}
