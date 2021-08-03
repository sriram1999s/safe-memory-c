#include<stdio.h>
#include<stdlib.h>

#define MAX_LOC 10

void *_store[MAX_LOC];
int _ix = 0;

void _disp_store();

void* smalloc(int size) {
  void *temp;
  if(_ix < MAX_LOC) {
    temp = malloc(size);
    _store[_ix] = temp;
    ++_ix;
  } else {
    printf("Maximum location limit reached!!");
  }
  return temp;
}

void sfree(void* ptr) {
  for(int i = 0; i < MAX_LOC; ++i)
  {
    if(_store[i] == ptr) {
      free(ptr);
      _store[i] = 0;
      return;
    }
  }
  printf("Invalid free()!!, not freeing memory at location %p\n", ptr);
}

void _disp_store() {
  for(int i = 0; i < MAX_LOC; ++i) {
    printf("%p\n", _store[i]);
  }
}
