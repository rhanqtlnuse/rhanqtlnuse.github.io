#include <stdio.h>

#define offsetof(type, member) \
    ((unsigned long long) (&((type *) 0)->member))

#define to_struct(ptr, type, member) \
    ((type *) ((char *) (ptr) - offsetof(type, member)))

struct S {
    char a;
    int b;
    long long c;
};

int main(void) {
    printf("%llu %llu %llu\n", 
           offsetof(struct S, a), 
           offsetof(struct S, b), 
           offsetof(struct S, c));
        
    printf("%c\n", ((struct S *) 0x100000)->a);
    
    return 0;
}