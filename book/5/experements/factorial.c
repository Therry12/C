// Рекурсия, реализованная с помощью цикла и рекурсии
#include <stdio.h>

int find_fac_loop(int number) {
    int i = number, res = 1;
    while (i) {
        res = res * i; 
        i--;
    }
    printf("%d\n", res);
    
    return res;
}

long find_fac_recursive(long number) {
    if (1 == number) return number;     
   
    return number * find_fac_recursive(number - 1);  
}
int main(void) {
    int number, res;

    printf("Enter number: ");
    scanf("%d", &number);
    res = find_fac_recursive(number);

    printf("Factorial %d - %d\n", number, res);
}
