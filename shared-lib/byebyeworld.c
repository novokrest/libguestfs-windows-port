#include <stdio.h>

#include "world.h"

int
byebye_world (char const *msg)
{
  printf ("Bye-bye, world: %s!\n", msg);
  
  return 1;
}

