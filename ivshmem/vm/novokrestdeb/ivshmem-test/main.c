#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#include "ivshmem-ops.h"

static char const *DEFAULT_MESSAGE = "Hello, ivshmem!";
static char const *opts = "m:";

typedef struct {
  char const *message;
} ivshmem_args;

static void 
do_getopt (int argc, char *const *argv, char const *opts, ivshmem_args *args)
{
  int c;
  
  opterr = 0;

  while ((c = getopt (argc, argv, opts)) != -1) {
    switch (c) {
      case 'm':
        args->message = optarg;
        break;
      default:
        break;
    }
  }
}

int
main (int argc, char *argv[])
{
  int err;
  ivshmem_args args;

  args.message = DEFAULT_MESSAGE;
  do_getopt (argc, argv, opts, &args);

  err = ivshmem_write (args.message);
  if (err) {
    fprintf (stderr, "Error occurred during writing message to ivshmem\n");
    exit (EXIT_FAILURE);
  }
  return 0;
}
