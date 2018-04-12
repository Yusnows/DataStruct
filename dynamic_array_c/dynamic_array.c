/*************************************************************************
	> File Name: dynamic_array.c
	> Author: yusnows
	> Mail: YusnowsLiang@gmail.com
	> Created Time: Thu 12 Apr 2018 07:10:57 PM CST
    > Copyright@yusnows: All rights reserve!
 ************************************************************************/

#include<stdio.h>
#include"dynamic_array.h"

/*************************************************************************
 *this function is to delete a data(node) int the dynamic array,
 *you should chang this function to fit you data type.
 *it is used at the clear function. you can look the function int this file.
 *the following two definitions of deladata are the typical cases, I think.
 *you can read them and implement you own function with the function that you
 *want.
 **************************************************************************/
/*************************************************************************
*   example 1.
int deladata(d_type* node)
{
    if(node != NULL)
    {
        if(node->name!=NULL)
        {
            free(node->name);
            node->name=NULL;
        }
        if(node->ID_type!=NULL)// && node->ID_type_need_free==1)
        {
            free(node->ID_type);
            node->ID_type=NULL;
        }
        if(node->child!=NULL)
        {
            arrayclear(node->child);
            free(node->child);
            node->child=NULL;
        }
        free(node);
        node=NULL;
    }
    return 0;
}
*example 1 is relative to the struct node. here is its definition.
struct node_t
{
    darray_t* child;
    int lineno;
    char *name;
    char* ID_type;
    union{
        int I_type;
        float F_type;
    };
};
typedef node_t d_type;

* example 2 is much simple than example 1. here it is.
int deladata(d_type* dptr) 
{
    free(dptr);
    return 0;
}
* this d_type is define as the follow.
typedef int d_type;
*
*
********************************************************************************************/

int deladata(d_type* dptr) 
{
    free(dptr);
    return 0;
}

darray_t* allocnewarray()
{
    darray_t* ret = (darray_t*)malloc(sizeof(darray_t));
    if(ret == NULL)
        return NULL;
    ret->initial = arrayInitial;
    ret->push_back_ptr = arraypush_back_ptr;
    ret->push_back_val = arraypush_back_val;
    ret->pop_back_ptr = arraypop_back_ptr;
    ret->pop_back_val = arraypop_back_val;
    ret->insert_ptr = arrayinsert_ptr;
    ret->insert_val = arrayinsert_val;
    ret->remove = arrayremove;
    ret->at_ptr = array_at_ptr;
    ret->at_val = array_at_val;
    ret->size = arraysize;
    ret->clear = arrayclear;
    ret->isFull = arrayisFull;
    ret->isEmpty = arrayisEmpty;
    ret->recap = arrayrecap;
    if(arrayInitial(ret,8)!=0)
        if(arrayInitial(ret,8)!=0)
        {
            free(ret);
            return NULL;
        }
    return ret;
}

int arrayInitial(darray_t* arr, int cap)
{
    arr->top = -1;
    arr->capacity = cap;
    arr->ptr = (d_type**)malloc(sizeof(d_type*)*(arr->capacity));
    if(arr->ptr == NULL)
        return -1;
    return 0;
}

int arraypush_back_ptr(darray_t* arr, d_type* val)
{
    if(arrayisFull(arr)==1)
    {
        if(arrayrecap(arr,(*arr).capacity*2)!=0)
            return -1;
        printf("array capacity increase to %d\n",arr->capacity);
    }
    (arr->ptr)[++(arr->top)] = val;
    return 0;
}

int arraypush_back_val(darray_t* arr, d_type val)
{
    d_type* tmp = (d_type*)malloc(sizeof(d_type));
    if(tmp == NULL)
        return -1;
    if(arrayisFull(arr)==1)
    {
        if(arrayrecap(arr,(arr->capacity)*2)!=0)
            return -1;
    }
    *tmp = val;
    (arr->ptr)[++(arr->top)] = tmp;
    return 0;
}
int arrayinsert_ptr(darray_t* arr, int pos, d_type* val)
{
    if(pos>=arr->capacity)
    {
        int cap_tmp = arr->capacity;
        while(cap_tmp<=pos)
        cap_tmp=cap_tmp*2;
        if(arrayrecap(arr,(arr->capacity)*2)!=0)
            return -1;
    }
	else if(arrayisFull(arr)==1)
	{
        if(arrayrecap(arr,(arr->capacity)*2)!=0)
            return -1;
	}
    if(pos>arr->top)
    {
        for(int i=arr->top;i<pos;++i)
            (arr->ptr)[i]=NULL;
        (arr->ptr)[pos]=val;
        arr->top=pos;
    }
    else
    {
        for(int i=arr->top+1;i > pos;--i)
            (arr->ptr)[i] = (arr->ptr)[i-1];
        (arr->ptr)[pos] = val;
        arr->top = (arr->top)+1;
    }
    return 0;
}
int arrayinsert_val(darray_t* arr, int pos, d_type val)
{
    if(pos>=arr->capacity)
    {
        int cap_tmp = arr->capacity;
        while(cap_tmp<=pos)
        cap_tmp=cap_tmp*2;
        if(arrayrecap(arr,(arr->capacity)*2)!=0)
            return -1;
    }
	else if(arrayisFull(arr)==1)
	{
        if(arrayrecap(arr,(arr->capacity)*2)!=0)
            return -1;
	}
    d_type* tmp = (d_type*)malloc(sizeof(d_type));
    *tmp = val;
    if(pos>arr->top)
    {
        for(int i=arr->top;i<pos;++i)
            (arr->ptr)[i]=NULL;
        (arr->ptr)[pos]=tmp;
        arr->top=pos;
    }
    else
    {
        for(int i=arr->top+1;i > pos;--i)
            (arr->ptr)[i] = (arr->ptr)[i-1];
        (arr->ptr)[pos] = tmp;
        arr->top = (arr->top)+1;
    }
    return 0;
}
d_type* arraypop_back_ptr(darray_t* arr)
{
    d_type* r = NULL;
    if(arrayisEmpty(arr))
        return r;
    if(arr->ptr[(arr->top)]!=NULL)
    {
        r = (*arr).ptr[(arr->top)];
//        free((*arr).ptr[(*arr).top]);
        (*arr).ptr[(arr->top)--]=NULL;
    }
    if(arraysize(arr)<(*arr).capacity/3 && (*arr).capacity>8)
        if(arrayrecap(arr,(*arr).capacity/2)!=0);
    return r;
}

d_type arraypop_back_val(darray_t * arr)
{
    d_type ret;
    if( arrayisEmpty(arr) ==1 )
        return ret;
    if(arr->ptr[(arr->top)]!=NULL)
    {
        ret = *(arr->ptr[arr->top]);
//        deladata((*arr).ptr[(*arr).top]);
        free((arr->ptr)[arr->top]);
        (*arr).ptr[(arr->top)--]=NULL;
    }
    if(arraysize(arr)<(*arr).capacity/3 && (*arr).capacity>8)
        if(arrayrecap(arr,(*arr).capacity/2)!=0);
    return ret;
}


int arrayremove(darray_t* arr, int pos)
{
    if(pos<0||pos>arr->top)
        return -1;
    deladata(arr->ptr[pos]);
    arr->ptr[pos]=NULL;
    return 0;
}

d_type* array_at_ptr(darray_t* arr, int pos)
{
    if(pos<0||pos>arr->top)
        return NULL;
    return arr->ptr[pos];
}
d_type array_at_val(darray_t* arr,int pos)
{
    if(pos<0||pos>arr->top)
        return *(arr->ptr[0]);
    if(arr->ptr[pos]!=NULL)
        return *(arr->ptr[pos]);
    else
        return *(arr->ptr[0]);
}

int arraysize(darray_t* arr)
{
    return (*arr).top+1;
}

int arrayclear(darray_t* arr)
{
    while(arrayisEmpty(arr)!=1)
    {
        if(arr->ptr[(arr->top)]!=NULL)
        {
            deladata(arr->ptr[(arr->top)]);
            (*arr).ptr[(arr->top)--]=NULL;
        }
        else
        {
            arr->top--;
        }
        if(arraysize(arr)<(*arr).capacity/3 && (*arr).capacity>8)
            if(arrayrecap(arr,(*arr).capacity/2)==0)
            {
                printf("array capacity reduce to %d\n",arr->capacity);
            }
    }
        return 0;
}

int arrayisFull(darray_t* arr)
{
    if(arr->top >= arr->capacity-1)
        return 1;
    else
        return 0;
}

int arrayisEmpty(darray_t* arr)
{
    if(arr == NULL)
        return 1;
    if(arr->top == -1)
        return 1;
    else
        return 0;
}

int arrayrecap(darray_t* arr,int newcap)
{
    d_type** newPtr = (d_type**)malloc(sizeof(d_type*)*newcap);
    if(newPtr != NULL)
    {
        int cap_tmp;
        cap_tmp= newcap>(arr->capacity)?(arr->capacity):newcap;
        memcpy(newPtr,arr->ptr,cap_tmp*sizeof(d_type*));
        free(arr->ptr);
        arr->ptr = newPtr;
        arr->capacity = newcap;
        return 0;
    }
    else
    {
        return -1;
    }
}

