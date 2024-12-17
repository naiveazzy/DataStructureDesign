
#include <stdio.h>
#include <stdlib.h>
#include "PreDefines.h"

#define _AUTOINITSTACK_SIZE_ 10
#define _AUTOINITSTACK_INCREASE_ 10

typedef int ElemType_Sq_t;

typedef struct SqStack {
    ElemType_Sq_t *elem;    // 存储栈元素的数组指针
    int top;                // 栈顶元素的下一个空间位标
    int size;               // 数组指针elem存储的元素数量
    int increase;           // 栈空间不够时扩容的量
} SqStack;

Status AutoInitStack_Sq(SqStack &S);
Status InitStack_Sq(SqStack &S, int size, int increase);
Status Push_Sq(SqStack &S, ElemType_Sq_t e);
Status Pop_Sq(SqStack &S, ElemType_Sq_t &e);
Status IsStackEmpty_Sq(SqStack &S);

Status PrintStack_Sq(SqStack &S);

