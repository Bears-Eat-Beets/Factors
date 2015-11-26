#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void get_factors(uint32_t num)
{
    uint32_t i;
    for (i = 1; i <= num; ++i) {
        if ((num % i) == 0)
            printf("%u ", i);
    }

    return;
}

void get_prime_factors(uint32_t num)
{
    uint32_t div = 2;
    while (num != 0) {
        if (num % div) {
            div = div + 1;
        }
        else {
            num = num / div;
            printf("%d ", div);
            if (num == 1)
                break;
        }
    }
}

//- Count the number of bits in a number
int get_bit_count(uint32_t n)
{
    if (n == 0)
        return 0;
    int c = 0;

    while (!(n & 0x80000000)) {
        n <<= 1;
        c++;
    }

    printf("[BITS]: %d\n", 32-c);
    return 32 - c;
}

void get_bitshift_numbers(uint32_t K)
{
    int B = get_bit_count(K);
    uint32_t Rotated;

    printf("[SHIFTS]: ");

    int i;
    for (i = 0; i <= B; i++) {
        //- Rotate number by i bits
        Rotated = (K >> i) | (K << (32 - i));

        //- Delegate work to factorise
        printf("%u ", Rotated);
    }
}

void main()
{
    printf("Factor cross-checking program\n");
    char *input;
    int num;
    size_t size = 0;

    while(1)
    {
        printf("Factor: ");
        getline(&input, &size, stdin);

        if (strcasecmp(input, "q") == 0)
            break;
        else {
            num = atoi(input);
            printf("[F]: ");
            get_factors(num);
            printf("\n[P]: ");
            get_prime_factors(num);
            printf("\n");
            get_bitshift_numbers((uint32_t)num);
            printf("\n\n");
        }
    }

    return;
}