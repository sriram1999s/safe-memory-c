# safe-memory-c
Safe allocation and deallocation of memory in C

## Interfaces Provided :

- smalloc
- sfree

> The maximum number of locations kept track of can be modified by changing ```MAX_LOC```in ```safe_mem.c```

## Usage :

Sample client ( ```client.c``` )

```c
#include <stdio.h>
#include <stdlib.h>
#include "safe_mem.h"

int main() {
  char *ptr = smalloc(sizeof(char));
  int *arr = smalloc(5 * sizeof(int));

  // double free will not cause segmentation fault
  sfree(ptr);
  sfree(ptr);

  sfree(arr);

  int a = 5;
  int *b = &a;
  // freeing location on stack will not cause segmentation fault
  sfree(b);
}
```

## Compilation & Running :

```sh
gcc client.c safe_mem.c

```

### Sample output :
```sh
Invalid free()!!, not freeing memory at location 0x557d7858d2a0
Invalid free()!!, not freeing memory at location 0x7fff397ff17c
```
