#ifndef STRING_H
#define STRING_H
#include "string.h"
#endif  //STRING_H

#ifndef STDLIB_H
#define STDLIB_H
#include "stdlib.h"
#endif  //STDLIB_H

#ifndef UNISTD_H
#define UNISTD_H
#include "unistd.h"
#endif  //UNISTD_H

#ifndef STRING_H
#define STRING_H
#include "string.h"
#endif //STRING_H

#ifndef ERRNO_H
#define ERRNO_H
#include "errno.h"
#endif //ERRNO_H

#ifndef STDIO_H
#define STDIO_H
#include "stdio.h"
#endif //STDIO_H

typedef struct BST{
  char* word;
  int frequency;
  struct BST* left;
  struct BST* right;
} Node;
