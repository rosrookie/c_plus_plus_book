/*
 * @Author: Loren
 * @Date: 2022-04-22 16:16:16
 * @LastEditTime: 2022-04-22 16:26:18
 * @FilePath: /c_plus_plus_book/code/concurrency/demo1.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include <iostream>
#include <thread>

void hello()
{
    std::cout << "Hello Concurrent World\n";
}

int main()
{
    std::thread t(hello);
    t.join();
}