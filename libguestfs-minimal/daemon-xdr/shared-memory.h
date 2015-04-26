#ifndef SHARED_MEMORY_H_
#define SHARED_MEMORY_H_

#include <stdlib.h>
#include <stdint.h>

struct shared_memory;

struct shared_memory_ops
{
  int (*open) (struct shared_memory *shmem);
  int (*close) (struct shared_memory *shmem);
  uint64_t (*get_size) (struct shared_memory *shmem);
  void *(*get_ptr) (struct shared_memory *shmem);
  void (*print) (struct shared_memory *shmem, int n);
};

struct shared_memory
{
  struct shared_memory_ops *ops;
  
  /* In the real struct, private data used by each connection module
   * follows here.
   */  
};

extern struct shared_memory *new_shared_memory (const char *name, uint64_t size);
extern void free_shared_memory (struct shared_memory *shmemv);

#endif /* SHARED_MEMORY_H_ */
