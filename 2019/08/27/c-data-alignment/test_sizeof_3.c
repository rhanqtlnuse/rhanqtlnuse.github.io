#include <stdio.h>
#include <stddef.h>

struct P1 { int a; char b; int c; char d; };
struct P2 { int a; char b; char c; long d; };
struct P3 { short a[3]; char b[3]; };
struct P4 { short a[3]; char *b[3]; };
struct P5 { struct P3 a[2]; struct P2 t; };

int main(void) {
    printf("%llu\n", offsetof(struct P1, a));
    printf("%llu\n", offsetof(struct P1, b));
    printf("%llu\n", offsetof(struct P1, c));
    printf("%llu\n", offsetof(struct P1, d));
    struct P1 p1;
    printf("%p\n", &p1.a);
    printf("%p\n", &p1.b);
    printf("%p\n", &p1.c);
    printf("%p\n\n", &p1.d);

    printf("%llu\n", offsetof(struct P2, a));
    printf("%llu\n", offsetof(struct P2, b));
    printf("%llu\n", offsetof(struct P2, c));
    printf("%llu\n", offsetof(struct P2, d));
    struct P2 p2;
    printf("%p\n", &p2.a);
    printf("%p\n", &p2.b);
    printf("%p\n", &p2.c);
    printf("%p\n\n", &p2.d);

    /* struct P3 { short a[3]; char b[3]; }; */
    printf("%llu\n", offsetof(struct P3, a));
    printf("%llu\n", offsetof(struct P3, b));
    struct P3 p3;
    printf("%p\n", &(p3.a[0]));
    printf("%p\n", &(p3.a[1]));
    printf("%p\n", &(p3.a[2]));
    printf("%p\n", &(p3.b[0]));
    printf("%p\n", &(p3.b[1]));
    printf("%p\n\n", &(p3.b[2]));

    /* struct P4 { short a[3]; char *b[3]; }; */
    printf("%llu\n", offsetof(struct P4, a));
    printf("%llu\n", offsetof(struct P4, b));
    struct P4 p4;
    printf("%p\n", &(p4.a[0]));
    printf("%p\n", &(p4.a[1]));
    printf("%p\n", &(p4.a[2]));
    printf("%p\n", &(p4.b[0]));
    printf("%p\n", &(p4.b[1]));
    printf("%p\n\n", &(p4.b[2]));

    /* struct P5 { struct P3 a[2]; struct P2 t; }; */
    printf("%llu\n", offsetof(struct P5, a));
    printf("%llu\n", offsetof(struct P5, t));
    struct P5 p5;
    printf("%p\n", &(p5.a[0].a[0]));
    printf("%p\n", &(p5.a[0].a[1]));
    printf("%p\n", &(p5.a[0].a[2]));
    printf("%p\n", &(p5.a[0].b[0]));
    printf("%p\n", &(p5.a[0].b[1]));
    printf("%p\n", &(p5.a[0].b[2]));
    printf("%p\n", &(p5.a[1].a[0]));
    printf("%p\n", &(p5.a[1].a[1]));
    printf("%p\n", &(p5.a[1].a[2]));
    printf("%p\n", &(p5.a[1].b[0]));
    printf("%p\n", &(p5.a[1].b[1]));
    printf("%p\n", &(p5.a[1].b[2]));
    printf("%p\n", &(p5.t.a));
    printf("%p\n", &(p5.t.b));
    printf("%p\n", &(p5.t.c));
    printf("%p\n", &(p5.t.d));

    return 0;
}