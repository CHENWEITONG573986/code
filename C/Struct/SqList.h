/*
作者：陈维桐
时间：2024/9/10
类容：动态数组(c语言实现)
*/
#include <stdio.h>
#include <stdlib.h>
typedef struct SqList SqList;
typedef int ElemType;
typedef ElemType (*Func1)(SqList *, int);
typedef int (*Func2)(SqList *, int, int);
typedef int (*Func3)(SqList *, int);
// 顺序表结构体
struct SqList
{
    // 数组管理指针
    ElemType *elem;
    // 最大容量
    int size;
    // 当前存放长度
    int length;
    // 查看
    Func1 at;
    // 插入
    Func2 insert;
    // 删除
    Func3 erase;
    // 修改
    Func2 revise;
};

// 扩容
void Expansion(SqList *L)
{
    // 扩展容量
    L->size *= 2;
    // 创建临时指针维护数组
    int *Temp = L->elem;
    // 开辟新容量的数组
    L->elem = (ElemType *)calloc(L->size, sizeof(ElemType));
    // 将原数据从旧内存空间搬运到新内存空间
    for (int i = 0; i < L->length; i++)
    {
        L->elem[i] = Temp[i];
    }
    // 释放旧内存空间
    free(Temp);
}

// 查看
// L为this指针，index为查看的索引
ElemType At(SqList *L, int index)
{
    if (index >= L->length || index < 0)
    {
        printf("索引值不合法\n");
        return -1;
    }
    return L->elem[index];
}

// 插入
// L为this指针，index为插入的索引，value为插入的值
int Insert(SqList *L, int index, int value)
{
    if (index > L->length || index < 0)
    {
        printf("索引值不合法\n");
        return 0;
    }
    // 扩容
    if (L->length == L->size)
        Expansion(L);
    // 数据后移
    for (int i = L->length; i > index; i--)
    {
        L->elem[i] = L->elem[i - 1];
    }
    // 插入数据
    L->elem[index] = value;
    // 更新长度
    L->length++;
    return 1;
}
// 删除
// L为this指针，index为删除的索引
int Erase(SqList *L, int index)
{
    if (index >= L->length || index < 0)
    {
        printf("索引值不合法");
        return 0;
    }
    // 删除数据
    L->elem[index] = 0;
    // 更新长度
    L->length--;
    // 数据前移
    for (int i = index; i < L->length; i++)
    {
        L->elem[i] = L->elem[i + 1];
    }
    return 1;
}
// 修改
// L为this指针，index为修改的索引，value为修改的值
int Revise(SqList *L, int index, int value)
{
    if (index >= L->length || index < 0)
    {
        printf("索引值不合法");
        return 0;
    }
    L->elem[index] = value;
    return 1;
}

// 初始化
SqList InitSqList()
{
    SqList L;
    // 初始化容量
    L.size = 10;
    // 开辟内存空间
    L.elem = (ElemType *)calloc(L.size, sizeof(ElemType));
    // 初始化长度大小
    L.length = 0;
    // 查看
    L.at = At;
    // 插入
    L.insert = Insert;
    // 删除
    L.erase = Erase;
    // 修改
    L.revise = Revise;
    return L;
}
