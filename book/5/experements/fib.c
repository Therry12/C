// Программа для нахождения числа фибоначчи до 100

#include <stdio.h>



// 1 2 3 4

long long fib_loop(long long number) {
    long long fib = 0, fib_1 = 0, fib_2 = 1;

    for (int i = 2; i <= number; i++) {
        fib = fib_1 + fib_2;
        fib_1 = fib_2;
        fib_2 = fib;
        printf("%lld\n", fib);
    }

    return fib;
}

long long fib_recursive(long long number) {
    if (number == 0 || number == 1) return number;
    return fib_recursive(number - 1) + fib_recursive(number - 2);
}

int main(void) {
    long long number;

    printf("Введите число: ");
    scanf("%lld", &number);

    if (number < 0) {
        printf("Число должно быть больше нуля!\n");
        return 1;
    }

    if (0 == number) {
        printf("Число фибоначчи: 0\n");
    }

    if (1 == number) {
        printf("Число фибоначчи: 1\n");
    }

    printf("Число фибонначи %d\n", fib_recursive(number));
    return 0;
}

