//decpack.h
#ifndef DECPACK_H
#define DECPACK_H
typedef struct
{
  int size;
  int used;
  unsigned char *data;
} DecPack;

DecPack* DecPack_create(int size);

void DecPack_insert(DecPack *dp, int val);

int DecPack_delete(DecPack *dp);

void DecPack_print(DecPack *dp);

void DecPack_destroy(DecPack *dp);
#endif
