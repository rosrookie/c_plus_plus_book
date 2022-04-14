/*
 * @Author: Loren
 * @Date: 2022-04-14 22:44:38
 * @LastEditTime: 2022-04-15 00:06:40
 * @FilePath: /c_plus_plus_book/code/chapter1/demo2.cpp
 * @Description: const pointer and pointer to const.
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */

#include <iostream>

int main(int argc, char **argv)
{
    int x = 10;
    const int *ptr = &x;

    *ptr = 1;

    x = 100;

    ptr = nullptr;

    int y = 1;

    int *const p2 = &y;

    p2 = &x;

    *p2 = 100;

    int *const gg = nullptr;


    const int q;

    const int *z;

    int *const o;
    
}