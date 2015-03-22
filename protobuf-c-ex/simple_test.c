#include <stdlib.h>
#include <stdio.h>
#include <simple.pb-c.h>

struct A {
  int a;
};

struct B {
  struct A *sa;
  int b;
};

struct C {
  double c;
};

void funcA (struct A *sa, int i) { printf ("inside funcA()\n"); }
void funcB (struct B *sb, int i) { printf ("inside funcB()\n"); }
void funcC (struct C *sc, int i) { printf ("inside funcC()\n"); }

typedef void (*gfunc) (struct A * sa, int i);

void HFunc (gfunc f, struct A *sa, int i) {
  (*f)(sa, i);
}

int main(int argc, char* argv[])
{
    HFunc (funcA, NULL, 1);
    HFunc ((gfunc)funcB, NULL, 2);
    HFunc ((gfunc)funcC, NULL, 3);

    Example__ListDevices list_devs, *unpacked_list_devs;
    uint8_t *buf;
    size_t len;

    example__list_devices__init(&list_devs);
    list_devs.id = 100;
    list_devs.name = "abcde";
    
    len = example__list_devices__get_packed_size((Example__ListDevices const *)&list_devs);
    buf = malloc(len);
    if (!buf) {
        printf("ERROR: malloc()\n");
        exit(EXIT_FAILURE);
    }
    
    example__list_devices__pack((Example__ListDevices const *)&list_devs, buf);
    unpacked_list_devs = example__list_devices__unpack(NULL, len, buf);

    printf("id: %d, name: %s\nenum FILE: %d\n", unpacked_list_devs->id, unpacked_list_devs->name, EXAMPLE__DEVICE_TYPE__FILE);
    example__list_devices__free_unpacked(unpacked_list_devs, NULL);

    return 0;
}
