#include <stdio.h>

unsigned int gcd(unsigned int m, unsigned int n) {
    unsigned int result;
    while (n > 0) {
        result = m % n;
        m = n;
        n = result;
    }

    return m;
}

unsigned int gcd_recursive(unsigned int m, unsigned int n) {
    if (m % n == 0) {
        return n;
    }

    return gcd(n, m % n);
}

int main(void) {
    unsigned int m = 0;
    unsigned int n = 0;

    printf("find the GCD(greatest common divisor) of: \n");
    scanf("%u %u", &m, &n);

    unsigned int result = gcd(m, n);
    printf("the HCF of %u and %u is: %u\n", m, n, result);

    unsigned int result_by_recursive = gcd_recursive(m, n);
    printf("the HCF of %u and %u is: %u\n", m, n, result_by_recursive);

    return 0;
}