#ifndef EXTRA_WIN_H_
#define EXTRA_WIN_H_

#include <stdarg.h>

extern int asprintf(char** __restrict ret, const char * __restrict format, ...);
extern int vasprintf(char** __restrict ret, const char * __restrict format, va_list ap);

int gettimeofday(struct timeval * tp, struct timezone * tzp);
char* realpath(const char* path, char* resolved_path);

char* strndup(const char*s, size_t n);
void* memmem(const void *l, size_t l_len, const void *s, size_t s_len);

/* Returned buffer must be freed by caller */
char* getusername();

/* To free the returned buffer, call the LocalFree function. */
char* getusid();

FILE* open_memstream(char **ptr, size_t *sizeloc);

int symlink(const char *path1, const char *path2);

#endif /* EXTRA_WIN_H_ */
