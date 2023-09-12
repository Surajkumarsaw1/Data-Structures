# LAB-3

## how_to_return_matrix_of_RX3

### For multi-dimention array

```c
// Generally, we assign
int mat[4][3];
```

This means that 3 integers will be stored in a group (let it be Z), such that there are 4 such groups of Z (let it be Y). The initial address of Y (which is ...) is stored in a variable.

NOTE : it can't be returned in c in this format.

### For double pointer

```c
// Generally, for pointers
int **arr;
```

This means a pointer (memory address) will be referencing a pointer that will point to an integer value.

NOTE : it can be returned in c in this format. with the help of ...

### Pointer and matrix

```c
typedef int (*IntArray3Ptr)[3];
```

group of 3 integers (let it be Z), such that inital address of variable_name (e.g. IntArray3Ptr) will point to the first group of Z.
