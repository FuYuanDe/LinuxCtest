#include <stdio.h>

void func();

void a() {
    printf("Inside a()\n");
    int i = 0;

    for (; i < 0xffffff; ++i);
    func();
    return;
}

static void b() {
    printf("Inside b()\n");
    int i = 0;

    for (; i < 0xffffff; ++i);
    return;
}

int main() {
    printf("Inside main()\n");
    int i = 0;
    for (; i < 0xfffff; ++i);
    a();
    b();
    return 0;
}


void func() {
    printf("Inside func\n");
    int i = 0;

    for (; i < 0xffffff; ++i);
    return;
}


