#include <stdio.h>
#include <stddef.h>

// #pragma pack (push)
// #pragma pack (1)

struct S1 {
    char a;
    short b;
    int c;
};

struct S2 {
   int b;     // 4 bytes
   short c;   // 2 bytes
   char d;    // 1 byte
   char a;    // 1 byte
};

// #pragma pack (pop)

struct S3 {
    char a;     // 1 byte
    short b;    // 2 bytes
    int c;      // 4 bytes
    double d;   // 8 bytes
};

struct SX {
    short a;
    struct {
        char b;
        int c;
    } inner;
    int d;
};

struct SX_flatted {
    short a;
    char b;
    int c;
    int d;
};

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

struct SX3 {
    short a;
    struct {
        char b;
        short c;
    } inner;
    int d;
};

struct SX4 {
    short a;
    struct {
        char b;
        char c;
    } inner;
    int d;
};

struct SX5 {
    double a;
    struct {
        char b;
        char c;
    } inner;
    int d;
};

struct SX6 {
    double a;
    char e;
    struct {
        char b;
        char c;
    } inner;
    int d;
};

struct SX7 {
    double a;
    short e;
    struct {
        char b;
        char c;
    } inner;
    int d;
};

struct SX8 {
    double a;
    struct {
        int b;
        char c;
    } inner;
    int d;
};

struct SX9 {
    int a;
    struct {
        int b;
        char c;
    } inner;
    double d;
};

struct SX10 {
    char a;
    struct {
        char b;
        double c;
        int d;
    } inner;
    int e;
};

struct SXX {
    short a;
    struct {
        char b;
        double c;
        struct {
            char d;
            int e;
        } inner2;
    } inner;
    int f;
};


int main(void) {
    printf(sizeof(long) == 8 ? "64-bit\n" : "32-bit\n");
    
    printf("%d\n", sizeof(struct { int a; int b; char c; }));
    printf("%d\n", sizeof(struct S1));
    
    // printf("%d\n", sizeof(struct S2));

    // printf("%d\n", sizeof(struct S3));
    
    printf("sizeof(struct SX) = %d\n", sizeof(struct SX));
    printf("    offsetof(SX::inner.b) = %llu\n\n", offsetof(struct SX, inner.b));

    
    printf("sizeof(struct SX_flatted) = %d\n", sizeof(struct SX_flatted));
    printf("    offsetof(SX_flatted::b) = %llu\n", offsetof(struct SX_flatted, b));
    printf("    offsetof(SX_flatted::c) = %llu\n", offsetof(struct SX_flatted, c));
    printf("    offsetof(SX_flatted::d) = %llu\n\n", offsetof(struct SX_flatted, d));

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

    printf("sizeof(struct SX3) = %d\n", sizeof(struct SX3));
    printf("    offsetof(SX3::inner.b) = %llu\n", offsetof(struct SX3, inner.b));
    printf("    offsetof(SX3::d) = %llu\n\n", offsetof(struct SX3, d));

    printf("sizeof(struct SX4) = %d\n", sizeof(struct SX4));
    printf("    offsetof(SX4::inner.b) = %llu\n", offsetof(struct SX4, inner.b));

    printf("sizeof(struct SX5) = %d\n", sizeof(struct SX5));
    printf("    offsetof(SX5::inner.b) = %llu\n", offsetof(struct SX5, inner.b));

    printf("sizeof(struct SX6) = %d\n", sizeof(struct SX6));
    printf("    offsetof(SX6::inner.b) = %llu\n", offsetof(struct SX6, inner.b));
    
    printf("sizeof(struct SX7) = %d\n", sizeof(struct SX7));
    printf("    offsetof(SX7::inner.b) = %llu\n", offsetof(struct SX7, inner.b));

    printf("sizeof(struct SX8) = %d\n", sizeof(struct SX8));
    printf("    offsetof(SX8::inner.c) = %llu\n", offsetof(struct SX8, inner.c));
    printf("    offsetof(SX8::d) = %llu\n\n", offsetof(struct SX8, d));

    printf("sizeof(struct SX9) = %d\n", sizeof(struct SX9));
    printf("    offsetof(SX9::inner.b) = %llu\n", offsetof(struct SX9, inner.b));
    printf("    offsetof(SX9::d) = %llu\n\n", offsetof(struct SX9, d));

    printf("sizeof(struct SX10) = %d\n", sizeof(struct SX10));
    printf("    offsetof(SX10::inner.b) = %llu\n", offsetof(struct SX10, inner.b));
    printf("    offsetof(SX10::inner.c) = %llu\n", offsetof(struct SX10, inner.c));
    printf("    offsetof(SX10::e) = %llu\n\n", offsetof(struct SX10, e));

    printf("sizeof(struct SXX) = %d\n", sizeof(struct SXX));
    printf("    offsetof(SXX::inner.b) = %llu\n", offsetof(struct SXX, inner.b));
    printf("    offsetof(SXX::inner.inner2.d) = %llu\n", offsetof(struct SXX, inner.inner2.d));
    printf("    offsetof(SXX::inner.inner2.e) = %llu\n", offsetof(struct SXX, inner.inner2.e));
    printf("    offsetof(SXX::f) = %llu\n", offsetof(struct SXX, f));

    return 0;
}