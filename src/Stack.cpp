#include "../headers/Stack.h"

/*  
    @name:          AutoInitStack_Sq
    @description:   调用InitStack_Sq以及预定义的初始化值自动初始化栈
    @param          S：             需要初始化的栈
    @return:        若初始化成功则返回 SUCCESS 否则返回 ERROR
*/
Status AutoInitStack_Sq(SqStack &S)
{
    return InitStack_Sq(S, _AUTOINITSTACK_SIZE_, _AUTOINITSTACK_INCREASE_);
}

/*  
    @name:          InitStack_Sq
    @description:   初始化栈
    @param          S：             需要初始化的栈
    @param          size：          初始化栈的大小
    @param          increase：      栈扩容时的增量
    @return:        若初始化成功则返回 SUCCESS 否则返回 ERROR
*/
Status InitStack_Sq(SqStack &S, int size, int increase) 
{
    if (size <= 0 || increase <= 0) 
    {
        return ERROR;
    }

    S.elem = (ElemType_Sq_t*)malloc(sizeof(ElemType_Sq_t) * size);

    if (S.elem == NULL)
    {
        return ERROR;
    }

    S.top = 0;
    S.size = size;
    S.increase = increase;

    return SUCCESS;
}

/*  
    @name:          Push_Sq
    @description:   将元素入栈
    @param          S：             需要操作的栈
    @param          e：             需要入栈的元素
    @return:        若入栈成功则返回 SUCCESS 否则返回 ERROR
*/
Status Push_Sq(SqStack &S, ElemType_Sq_t e)
{
    if (S.elem == NULL) 
    {
        return ERROR;
    }

    // 栈满，用S.increase的值增加栈容量
    if (S.top == S.size - 1)
    {
        ElemType_Sq_t* p = (ElemType_Sq_t*)realloc(S.elem, sizeof(ElemType_Sq_t) * (S.size + S.increase));
        S.elem = p;
        
        if (S.elem == NULL)
        {
            return ERROR;
        }

        S.size += S.increase;
    }

    // 将元素入栈
    S.elem[S.top++] = e;

    return SUCCESS;

}

/*  
    @name:          Pop_Sq
    @description:   将元素入栈
    @param          S：             需要操作的栈
    @param          e：             出栈的元素
    @return:        若入栈成功则返回 SUCCESS 并使元素 e 变为出栈的元素数值，否则返回 ERROR
*/
Status Pop_Sq(SqStack &S, ElemType_Sq_t &e)
{
    if (S.elem == NULL) 
    {
        return ERROR;
    }

    // 栈内无元素
    if (S.top == 0)
    {
        return ERROR;
    }

    e = S.elem[--S.top];

    return SUCCESS;
}

/*  
    @name:          IsStackEmpty_Sq
    @description:   返回栈是否为空
    @param          S：             需要操作的栈
    @return:        若栈空返回TRUE，栈非空返回FALSE，栈未初始化返回ERROR
*/
Status IsStackEmpty_Sq(SqStack &S)
{
    if (S.elem == NULL)
    {
        return ERROR;
    }

    if (S.top == 0)
    {
        return TRUE;
    } else {
        return FALSE;
    }
}

/*  
    @name:          PrintStack_Sq
    @description:   打印栈，调试时用
    @param          S：             需要打印的栈
    @return:        打印成功返回 SUCCESS 否则返回 ERROR
*/
Status PrintStack_Sq(SqStack &S)
{

    if (S.elem == NULL)
    {
        return ERROR;
    }

    printf("Stack's size: %d/%d\n", S.top, S.size);
    printf("===Start to print stack!===\n");
    
    for (int i = 0; i < S.top; i++) 
    {
        if (i == 0)
        {
            printf("   top->%d\n", S.elem[i]);
            continue;
        }

        if (i == S.top - 1)
        {
            printf("bottom->%d\n", S.elem[i]);
            break;
        }

        printf("\t%d\n", S.elem[i]);
    }
    
    printf("===Printing Stack ended!===\n");

    return SUCCESS;
}
