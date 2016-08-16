# Simple Hashtable Implementation in C

```sh
$ make
$ make test
```

Include "hashtable.h" to use functions.

Example usage in "test_hashtable.c".

Important functions applied to the type of value stored in the hashtable that must be implemented.
- A void function that takes a single void pointer argument:
  void (*free_func)(void*)
- A copy function that returns a duplicate representation of the value.
  This copy_func must return NULL on any kind of failure.
  void* (*copy_func)(void*)
