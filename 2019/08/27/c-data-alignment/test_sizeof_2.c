#include <stdio.h>
#include <stddef.h>

struct SX2 {
    short a;        // 2 bytes
    struct {
        char b;     // 1 byte
        double c;   // 8 bytes
    } inner;
    int d;          // 4 bytes
};

struct SX2_flatted {
    short a;    // 2 bytes
    char b;     // 1 byte
    double c;   // 8 bytes
    int d;      // 4 bytes
};

int main(void) {
    struct SX2 x;
    printf("sizeof(struct SX2) = %d\n", sizeof(struct SX2));
    printf("    offsetof(SX2::inner.b) = %llu\n", offsetof(struct SX2, inner.b));
    printf("    offsetof(SX2::inner.c) = %llu\n", offsetof(struct SX2, inner.c));
    printf("    offsetof(SX2::d) = %llu\n", offsetof(struct SX2, d));
    printf("    %p\n", &x.a);
    printf("    %p\n", &x.inner.b);
    printf("    %p\n", &x.inner.c);
    printf("    %p\n\n", &x.d);

    struct SX2_flatted sx2_f;
    printf("sizeof(struct SX2_flatted) = %d\n", sizeof(struct SX2_flatted));
    printf("    offsetof(SX2_flatted::b) = %llu\n", offsetof(struct SX2_flatted, b));
    printf("    offsetof(SX2_flatted::c) = %llu\n", offsetof(struct SX2_flatted, c));
    printf("    offsetof(SX2_flatted::d) = %llu\n", offsetof(struct SX2_flatted, d));
    printf("    %p\n", &sx2_f.a);
    printf("    %p\n", &sx2_f.b);
    printf("    %p\n", &sx2_f.c);
    printf("    %p\n\n", &sx2_f.d);
    
    return 0;
}