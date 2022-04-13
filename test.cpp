/*
 * @Author: Loren
 * @Date: 2022-04-13 23:40:29
 * @LastEditTime: 2022-04-14 01:05:21
 * @FilePath: /c_plus_plus_book/test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include <iostream>

int main()
{
    int x = 10;
    int value = 0;
    int *ptr = &x;                   // 指针变量ptr的初始化
    value = *ptr;                    // 解引用，将指针ptr所指向的对象赋值给value
    std::cout << value << std::endl; // 输出 10；

    int &f = *ptr; //

    int *p1, p2;
}