#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>

#define DECL_VECTOR_STRUCT(NAME, TYPE)                                         \
    struct NAME                                                                \
    {                                                                          \
        TYPE *vec;                                                             \
        unsigned capacity;                                                     \
        unsigned size;                                                         \
    }

#define DECL_VECTOR_INIT(NAME, TYPE)                                           \
    DECL_VECTOR_STRUCT(NAME, TYPE);                                            \
    struct NAME vector = { (TYPE##*)calloc(sizeof(TYPE), 0)

#endif /* !VECTOR_H */
