/*
 * @Author: Loren
 * @Date: 2022-04-13 23:40:29
 * @LastEditTime: 2022-04-14 01:30:11
 * @FilePath: /c_plus_plus_book/test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include <iostream>

int main()
{
    int x = 0;
    int &ref_x = x;
    std::cout << &x << " " << &ref_x << std::endl;
    return 0;
}