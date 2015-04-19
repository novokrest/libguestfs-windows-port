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

typedef size_t (*guestfs_pack) (const ProtobufCMessage *message, uint8_t *data);
typedef ProtobufCMessage* (*guestfs_unpack) (const ProtobufCAllocator *allocator, size_t len, const uint8_t *data);

ProtobufCMessage*
pack_and_unpack (guestfs_pack f_pack, guestfs_unpack f_unpack, const ProtobufCMessage *message, uint8_t *data)
{
  size_t len;
  
  len = f_pack (message, data);
  
  return f_unpack (NULL, len + 50, data);
}

int test1()
{
    Example__Flag flag;
    size_t plen, slen;
    
    example__flag__init (&flag);
    flag.val = 0;
    plen = example__flag__get_packed_size (&flag);
    slen = sizeof (Example__Flag);
    printf ("%d : %d\n", plen, slen);

    HFunc (funcA, NULL, 1);
    HFunc ((gfunc)funcB, NULL, 2);
    HFunc ((gfunc)funcC, NULL, 3);

    Example__ListDevices list_devs, *unpacked_list_devs;
    ProtobufCMessage *result;
    uint8_t *buf;
    size_t len;

    example__list_devices__init(&list_devs);
    
    len = example__list_devices__get_packed_size((Example__ListDevices const *)&list_devs);
    buf = malloc(len + 100);
    if (!buf) {
        printf("ERROR: malloc()\n");
        exit(EXIT_FAILURE);
    }
    
    result = pack_and_unpack (example__list_devices__pack, example__list_devices__unpack, &list_devs, buf);
    unpacked_list_devs = (Example__ListDevices*) result;

    example__list_devices__free_unpacked(unpacked_list_devs, NULL);

    return 0;
}

#define FLAG_MESSAGE_SIZE 8

char *
test2_pack (size_t *len)
{
  char *buf;
  Example__ListDevices devs;
  Example__Device dev1, dev2;
  Example__SubList sub;
  Example__Flag flag;
  int devslen, dev1len, dev2len, sublen, flaglen, totallen;
  
  example__device__init (&dev1);
  dev1.name = "dev1_name";
  dev1.volume = 1313;
  dev1.type = EXAMPLE__DEVICE_TYPE__FILE;
  dev1len = example__device__get_packed_size (&dev1);
  
  example__device__init (&dev2);
  dev2.name = "dev2_name";
  dev2.volume = 7777;
  dev2.type = EXAMPLE__DEVICE_TYPE__DEV;
  dev2len = example__device__get_packed_size (&dev2);
  
  example__sub_list__init (&sub);
  sub.n_names = 3;
  sub.names = malloc (sizeof (char *) * sub.n_names);
  sub.names[0] = "sub1";
  sub.names[1] = "sub2";
  sub.names[2] = "sub3";
  sublen = example__sub_list__get_packed_size (&sub);
  
  example__list_devices__init (&devs);
  devs.n_devices = 2;
  devs.devices = malloc (sizeof (Example__Device *) * devs.n_devices);
  devs.devices[0] = &dev1;
  devs.devices[1] = &dev2;
  devs.sublist = &sub;
  devslen = example__list_devices__get_packed_size (&devs);

  totallen = dev1len + devslen;
  
  example__flag__init (&flag);
  flag.val = totallen;
  flaglen = example__flag__get_packed_size (&flag);
  
  *len = FLAG_MESSAGE_SIZE + totallen;
  buf = malloc (*len);
  memset (buf, 0, *len);
  
  assert (example__flag__pack (&flag, buf) == flaglen);
  assert (example__device__pack (&dev1, buf + FLAG_MESSAGE_SIZE) == dev1len);
  assert (example__list_devices__pack (&devs, buf + FLAG_MESSAGE_SIZE + dev1len) == devslen);
  
  printf ("test2_pack():\n" 
          "flaglen: %d\n"   
          "dev1len: %d\n"   
          "dev2len: %d\n"   
          "sublen: %d\n"    
          "devslen: %d\n"   
          "totallen: %d\n"  
          "len: %d\n" 
          "\n", 
          flaglen, dev1len, dev2len, sublen, devslen, totallen, *len);
  
  return buf;
}

void
test2_unpack (char *buf, size_t len)
{
  Example__Flag *flag;
  Example__ListDevices *devs;
  Example__Device *dev1, *dev2;
  Example__SubList *sub;
  int flaglen, dev1len, dev2len, sublen, devslen, totallen;
  
  printf ("Try unpack flag\n");
  flag = example__flag__unpack (NULL, 5, buf);
  assert (flag != NULL);
  flaglen = example__flag__get_packed_size (flag);
  printf ("Flag unpacked: %d\n", flag->val);
  
  dev1 = example__device__unpack (NULL, len - FLAG_MESSAGE_SIZE, buf + FLAG_MESSAGE_SIZE);
  dev1len = example__device__get_packed_size (dev1);
  assert (dev1 != NULL);
  
  devs = example__list_devices__unpack (NULL, len - FLAG_MESSAGE_SIZE - dev1len, buf + FLAG_MESSAGE_SIZE + dev1len);
  devslen = example__list_devices__get_packed_size (devs);
  assert (devs != NULL);
  
  sub = devs->sublist;
  sublen = example__sub_list__get_packed_size (sub);
  assert (sub != NULL);
  
  assert (flag != NULL && dev1 != NULL && devs != NULL && sub != NULL);
  printf ("After assert");
  
  printf ("test2_unpack(): \n"
          "flaglen: %d, flagval: %d\n"
          "dev1len: %d, dev1name: %s, dev1volume: %d, dev1type: %d\n" 
          "devslen: %d, n_devices: %d\n" 
          "devs_dev1len: %d, devs_dev1name: %s, devs_dev1volume: %d, devs_dev1type: %d\n" 
          "devs_dev2len: %d, devs_dev2name: %s, devs_dev2volume: %d, devs_dev2type: %d\n" 
          "sublen: %d, n_names: %d, names: %s, %s, %s\n" 
          "\n" 
          "" ,
          flaglen, flag->val,
          dev1len, dev1->name, dev1->volume, dev1->type,
          devslen, devs->n_devices,
          example__device__get_packed_size (devs->devices[0]), devs->devices[0]->name, devs->devices[0]->volume, devs->devices[0]->type,
          example__device__get_packed_size (devs->devices[1]), devs->devices[1]->name, devs->devices[1]->volume, devs->devices[1]->type,
          sublen, sub->n_names, sub->names[0], sub->names[1], sub->names[2]);
}

void 
test2 ()
{
  char *buf;
  size_t len;
  
  buf = test2_pack (&len);
  test2_unpack (buf, len);
}

void
test3 ()
{
  char buf[100];
  memset (buf, 0, sizeof buf);
  
  Example__Flag flag, *unpacked_flag_exact, *unpacked_flag;
  int packed_len;
  
  example__flag__init (&flag);
  flag.val = 7777;
  packed_len = example__flag__get_packed_size (&flag);
  assert (example__flag__pack (&flag, buf) == packed_len);
  
  unpacked_flag_exact = example__flag__unpack (NULL, packed_len, buf);
  assert (unpacked_flag_exact != NULL);
  unpacked_flag_exact = example__flag__unpack (NULL, sizeof (buf), buf);
  assert (unpacked_flag != NULL);
  
  printf ("flagval: %d\n", unpacked_flag->val);
}

void
test4()
{
  size_t size1, size2, size3;
  Example__Flag flag = EXAMPLE__FLAG__INIT;
  
  flag.val = 0;
  size1 = example__flag__get_packed_size (&flag);
  
  flag.val = 1;
  size2 = example__flag__get_packed_size (&flag);  
  
  flag.val = 3256346;
  size3 = example__flag__get_packed_size (&flag);
  
  printf ("size1: %d\n"
          "size2: %d\n"
          "size3: %d\n",
          size1, size2, size3);
}

void
print_sizes ()
{
  size_t flag_size, hdr_size, progress_size;
  Example__Flag flag = EXAMPLE__FLAG__INIT;
  Example__Header hdr = EXAMPLE__HEADER__INIT;
  Example__Progress progress = EXAMPLE__PROGRESS__INIT;
  
  example__flag__init (&flag);
  flag.val = 134;
  flag_size = example__flag__get_packed_size (&flag);
  
  example__header__init (&hdr);
  hdr_size = example__header__get_packed_size (&hdr);
  
  example__progress__init (&progress);
  progress.proc = 235;
  progress.serial = 1345424325;
  progress.position = -2425234;
  progress.total = -324545342;
  progress_size = example__progress__get_packed_size (&progress);
  
  printf ("Flag: %d\n"
          "Header: %d\n"
          "Progress: %d\n",
          flag_size, hdr_size, progress_size);
}

int main (int argc, char **argv)
{
  char *s = strdup (NULL);
  printf ("s: %s\n", s);
//  test2();
//  test3();
//  test4();
//  print_sizes ();

  return 0;
}


















