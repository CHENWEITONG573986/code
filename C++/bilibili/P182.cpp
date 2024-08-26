#include <iostream>
#include <string>
using namespace std;
// 数组类模板
template <class T>
class MyArray
{
private:
    // 指针指向堆区开辟的真实的数组
    T *pAddress;
    // 数组容量
    int m_Capacity;
    // 数组元素个数
    int m_Size;

public:
    // 无参构造
    MyArray(){};
    // 有参构造
    MyArray(int capacity);
    // 拷贝构造（深拷贝）
    MyArray(const MyArray &arr);
    // 赋值运算符重载（深拷贝）
    MyArray &operator=(const MyArray &arr);
    // 尾插法
    void Push_Back(T val);
    // 尾删法
    void Pop_Back(); 
    // 通过下标的方式访问数据
    T& operator[](int index);
    // 析构，释放堆区空间
    ~MyArray();
};

template <class T>
MyArray<T>::MyArray(int capacity)
{
    m_Capacity = capacity;
    m_Size = 0;
    pAddress = new T[m_Capacity];
}

template <class T>
MyArray<T>::MyArray(const MyArray &aar)
{
    this->m_Capacity = aar.m_Capacity;
    this->m_Size = aar.m_Size;
    // 深拷贝
    this->pAddress = new T[this->m_Capacity];
    for (int i = 0; i < this->m_Size; i++)
    {
        this->pAddress[i] = aar.pAddress[i];
    }
}

template <class T>
MyArray<T> &MyArray<T>::operator=(const MyArray &arr)
{
    // 先判断原来堆区是否存放数据，如果存放，先释放
    if (this->pAddress != NULL)
    {
        delete[] pAddress;
        pAddress = NULL;
    }
    this->m_Capacity = arr.m_Capacity;
    this->m_Size = arr.m_Size;
    this->pAddress = new T[this->m_Capacity];
    for (int i = 0; i < this->m_Size; i++)
    {
        this->pAddress[i] = arr.pAddress[i];
    }
    return *this;
}
template <class T>
void MyArray<T>::Push_Back(T val)
{
    // 判断容量是否已满
    if (this->m_Capacity == this->m_Size)
    {
        cout << "数组已满，无法插入" << endl;
        return;
    }
    this->pAddress[this->m_Size] = val;
    this->m_Size++;
}

template <class T>
void MyArray<T>::Pop_Back()
{
    if (this->m_Size == 0)
    {
        cout << "数组为空，无法删除" << endl;
        return;
    }
    this->m_Size--;
}

template <class T>
T& MyArray<T>::operator[](int index)
{
    return this->pAddress[index];
}

template <class T>
MyArray<T>::~MyArray()
{
    if (pAddress != NULL)
    {
        delete[] pAddress;
        pAddress = NULL;
    }
}

int main()
{
    MyArray<int> arr(10);
    MyArray<int> arr2(arr);
    MyArray<int> arr3;
    arr3 = arr2;
    arr[0] = 100;
    cout << arr[0] << endl;
    cout << arr2[0] << endl;
    cout << arr3[0] << endl;
    // arr2[0] = 1000;
    // cout << arr2[0] << endl;
    // cout << arr3[0] << endl;
    // arr2.Push_Back(100);
    // arr2.Push_Back(100);
    // arr2.Push_Back(100);
    return 0;
}