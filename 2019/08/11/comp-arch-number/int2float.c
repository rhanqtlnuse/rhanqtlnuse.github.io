#include <stdio.h>

union i2f {
    int i;
    float f;
};

int main(void) {
    union i2f u;

    printf("E = 0:\n");

    printf("  M = 0:\n");
    u.i = 0x00000000;
    printf("    0x%08x %f\n", u.i, u.f);
    u.i = 0x80000000;
    printf("    0x%08x %f\n", u.i, u.f);

    printf("  M != 0:\n");
    u.i = 0x1 << 22;
    printf("    0x%08x %f\n", u.i, u.f);
    u.i = 0x4fffff;
    printf("    0x%08x %f\n", u.i, u.f);

    printf("1 <= E <= 254:\n");

    u.i = (0x1f << 23) | 0x4ffff0;
    printf("    0x%08x %f\n", u.i, u.f);
    u.i = (0x80 << 23) | 0x7fffff;
    printf("    0x%08x %f\n", u.i, u.f);
    u.i = (0x80 << 23) | 0x0f00ff;
    printf("    0x%08x %f\n", u.i, u.f);

    printf("E = 255:\n");

    printf("  M = 0:\n");
    u.i = 0xff << 23;
    printf("    0x%08x %f\n", u.i, u.f);
    u.i = (0x1 << 31) | (0xff << 23);
    printf("    0x%08x %f\n", u.i, u.f);

    printf("  M != 0:\n");
    u.i = (0xff << 23) | (0x01 << 3);
    printf("    0x%08x %f\n", u.i, u.f);
    u.i = (0x1 << 31) | (0xff << 23) | (0x01 << 15);
    printf("    0x%08x %f\n", u.i, u.f);

    return 0;
}