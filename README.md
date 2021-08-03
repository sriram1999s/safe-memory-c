# safe-memory-c
Safe allocation and deallocation of memory in C


> The maximum number of locations kept track of can be modified by changing ```MAX_LOC```in ```safe_mem.c```

## Hijacking

A shell script ```hijack.sh``` is provided.

Make sure to have the ```safe_mem.c``` file in the working directory.

Assuming the client file is ```hijack_client.c```, run :
```shell
hijack.sh hijack_client
```
```hijack.out``` is produced

## Normal Usage :

### Interfaces Provided :

- smalloc
- sfree

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

### Compilation & Running :

```sh
gcc client.c safe_mem.c

```

### Sample output :
```sh
Invalid free()!!, not freeing memory at location 0x557d7858d2a0
Invalid free()!!, not freeing memory at location 0x7fff397ff17c
```
