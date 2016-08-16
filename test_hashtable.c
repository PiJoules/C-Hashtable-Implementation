#include <assert.h>
#include "hashtable.h"

#define SIMPLE_VOID(var) (void* (*)(void*))var

/**
 * Custom strdup function for testing.
 */
static char* str_copy(const char* str){
    size_t len = strlen(str);
    char* new_str = (char*)malloc(sizeof(char) * len + 1);
    if (!new_str){
        perror("malloc failed");
        return NULL;
    }
    strncpy(new_str, str, len);
    new_str[len] = '\0';
    return new_str;
}


int main(int argc, char* argv[]){
    size_t size = 100;
    Hashtable* ht = ht_create(size, free, SIMPLE_VOID(str_copy));

    assert(ht->size == 100);
    assert(ht->entry_count == 0);

    ht_set(ht, "key1", "val1");
    ht_set(ht, "key2", "val2");
    ht_set(ht, "key2", "val3");
    assert(ht->size == 100);
    assert(ht->entry_count == 2);

    assert(!strcmp(ht_get(ht, "key1"), "val1"));
    assert(!strcmp(ht_get(ht, "key2"), "val3"));
    assert(!ht_get(ht, "key3"));

    ht_remove(ht, "key2");
    ht_remove(ht, "key3");
    assert(ht->entry_count == 1);
    assert(!ht_contains(ht, "key2"));
    assert(!ht_contains(ht, "key3"));
    assert(ht_contains(ht, "key1"));

    assert(ht->size == 100);
    ht_free(ht);

    return 0;
}
