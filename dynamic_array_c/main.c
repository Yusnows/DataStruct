/*************************************************************************
	> File Name: main.c
	> Author: yusnows
	> Mail: YusnowsLiang@gmail.com
	> Created Time: Thu 12 Apr 2018 07:28:10 PM CST
    > Copyright@yusnows: All rights reserve!
 ************************************************************************/

#include<stdio.h>
#include"dynamic_array.h"

int main()
{
    darray_t* arr = allocnewarray();
    for(int i=0;i<16;++i)
    {
        arr->push_back_val(arr,i);
    }
    printf("the size of array is: %d\n",arr->size(arr));
    for(int i=0;i<16;++i)
    {
        printf("%d\n",arr->pop_back_val(arr));
    }
    printf("the size of array is: %d\n",arr->size(arr));
    for(int i=0;i<16;++i)
    {
        arr->push_back_val(arr,i);
    }
    arr->insert_val(arr,24,24);
    printf("the size of array is: %d\n",arr->size(arr));
    printf("arr->ptr[24] is %d\n",arr->at_val(arr,24));
    arr->clear(arr);
    printf("the size of array is: %d\n",arr->size(arr));

    return 0;
}

