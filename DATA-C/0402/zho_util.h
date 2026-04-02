#ifndef _ZHO_UTIL_H_
#define _ZHO_UTIL_H_

#define MAX(x, y)	(((x) > (y)) ? (x) : (y))
#define MIN(x, y)	(((x) < (y)) ? (x) : (y))

void show_array(int *array, int count);
int *create_array(int min_value, int max_value, int count);
void swap_int(int *one, int *other);

#endif
