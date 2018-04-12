/*************************************************************************
	> File Name: dynamic_array.h
	> Author: yusnows
	> Mail: YusnowsLiang@gmail.com
	> Created Time: Thu 12 Apr 2018 07:11:04 PM CST
    > Copyright@yusnows: All rights reserve!
 ************************************************************************/

#ifndef _DYNAMIC_ARRAY_H
#define _DYNAMIC_ARRAY_H
#include <stdlib.h>
#include <string.h>
typedef int d_type; // your data type, if not 'int', please just replace 'int' with the type you need
struct darray;

typedef struct darray darray_t;

/*****************************************************************************
 *  |      | <----capacity
 *  |      | 
 *  |      |
 *  |      |
 *  |______|
 *  | data1| <------top
 *  |______| 
 *  | data0|
 *  |______| <------ptr
******************************************************************************/
struct darray
{
    int capacity;
    int top;
    d_type** ptr;

    int (*initial)(struct darray* selft,int capacity);
    int (*push_back_ptr)(struct darray* selft,d_type* val);
    d_type* (*pop_back_ptr)(struct darray* selft);
    int (*push_back_val)(struct darray* selft,d_type val);
    d_type (*pop_back_val)(struct darray* selft);
	int (*insert_ptr)(darray_t* selft, int pos, d_type* val);
	int (*insert_val)(darray_t* selft, int pos, d_type val);
	int (*remove)(darray_t* selft, int pos);
	d_type* (*at_ptr)(darray_t* selft, int pos);
	d_type (*at_val)(darray_t* selft,int pos);
    int (*size)(struct darray* selft);
    int (*clear)(struct darray* selff);
    int (*isFull)(struct darray* selft);
    int (*isEmpty)(struct darray* selft);
    int (*recap)(struct darray* selft,int newcap);
};

struct darray* allocnewarray();
int deladata(d_type* dptr);

int arrayInitial(struct darray* arr, int cap);
int arraypush_back_ptr(struct darray* arr, d_type* val);
int arraypush_back_val(struct darray* arr, d_type val);
d_type* arraypop_back_ptr(struct darray* arr);
d_type arraypop_back_val(struct darray* arr);

int arrayinsert_ptr(darray_t* arr, int pos, d_type* val);
int arrayinsert_val(darray_t* arr, int pos, d_type val);
int arrayremove(darray_t* arr, int pos);
d_type* array_at_ptr(darray_t* arr, int pos);
d_type array_at_val(darray_t* arr,int pos);

int arraysize(struct darray* arr);
int arrayclear(struct darray* arr);
int arrayisFull(struct darray* arr);
int arrayisEmpty(struct darray* arr);
int arrayrecap(struct darray* arr,int newcap);

#endif
