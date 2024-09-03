#include <stdio.h>
#include <stdint.h>

#define OK 0
#define WRONG_INPUT 1

#define FIRST_BYTE 31
#define FIRST_BYTE_OFFSET 24
#define SECOND_BYTE_OFFSET 16
#define THIRD_BYTE_OFFSET 8
#define MAX_BYTE (uint32_t) 255

void enter_byte(int *return_code, unsigned char *byte);

uint32_t pack(uint32_t byte1, uint32_t byte2, uint32_t byte3, uint32_t byte4);

void print_bin_packed(uint32_t packed_number);

int main()
{
    int return_code = OK;
    unsigned char byte1, byte2, byte3, byte4;

    enter_byte(&return_code, &byte1);

    enter_byte(&return_code, &byte2);

    enter_byte(&return_code, &byte3);

    enter_byte(&return_code, &byte4);

    if (return_code == OK)
    {
        uint32_t packed = pack(byte1, byte2, byte3, byte4);
        print_bin_packed(packed);
		
        uint32_t extracted1 = (packed & (MAX_BYTE << FIRST_BYTE_OFFSET)) >> FIRST_BYTE_OFFSET;
        uint32_t extracted2 = (packed & (MAX_BYTE << SECOND_BYTE_OFFSET)) >> SECOND_BYTE_OFFSET;
        uint32_t extracted3 = (packed & (MAX_BYTE << THIRD_BYTE_OFFSET)) >> THIRD_BYTE_OFFSET;
        uint32_t extracted4 = (packed & MAX_BYTE);
        printf(" %u %u %u %u\n", extracted1, extracted2, extracted3, extracted4);
    }
    return return_code;
}

uint32_t pack(uint32_t byte1, uint32_t byte2, uint32_t byte3, uint32_t byte4)
{
    uint32_t first_part = (byte1 & MAX_BYTE) << FIRST_BYTE_OFFSET;
    uint32_t second_part = (byte2 & MAX_BYTE) << SECOND_BYTE_OFFSET;
    uint32_t third_part = (byte3 & MAX_BYTE) << THIRD_BYTE_OFFSET;
    uint32_t fourth_part = (byte4 & MAX_BYTE);
    uint32_t bin_num = first_part + second_part + third_part + fourth_part;
    return bin_num;
}

void print_bin_packed(uint32_t packed)
{
    printf("Result: ");
    uint32_t mask = 1 << FIRST_BYTE;
    while (mask)
    {
        if (packed & mask)
            printf("1");
        else
            printf("0");
        mask >>= 1;
    }
    printf(" ");
}

void enter_byte(int *return_code, unsigned char *byte)
{
    if (*return_code == OK)
    {
        printf("Введите байт: ");
        int rc = scanf("%hhu", byte);
        if (rc != 1)
        {
            printf("Error: байт введён неверно.\n");
            *return_code = WRONG_INPUT;
        }
    }
}
