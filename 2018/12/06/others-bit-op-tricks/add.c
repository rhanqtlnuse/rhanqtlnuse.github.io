#include <stdio.h>

#define BIT(n, i) ((n) & (1 << (i)))

int add(const int a, const int b) {
    int sum = 0, carry = 0;
    for (int i = 0; i < 32; i++) {
        int t = BIT(a, i) ^ BIT(b, i);
    #if 0
        printf("a[%d] = %d, b[%d] = %d\n", i, BIT(a, i), i, BIT(b, i));
    #endif
        sum |= t ^ carry;
        carry = ((BIT(a, i) & BIT(b, i)) | (t & carry)) << 1;
    #ifdef DEBUG
        printf("sum[%2d] = %d, carry = %d\n", i, BIT(sum, i) >> i, carry >> i);
    #endif
    }
    return sum;
}

int main(void) {
    int a, b;
    scanf("%d%d", &a, &b);
    printf("actual: %d, expected: %d\n", add(a, b), a + b);

    return 0;
}
