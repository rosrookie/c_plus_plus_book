/*
 * @Author: Loren
 * @Date: 2022-04-22 17:17:20
 * @LastEditTime: 2022-04-22 17:17:20
 * @FilePath: /c_plus_plus_book/code/concurrency/demo2.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include <list>
#include <mutex>
#include <algorithm>

std::list<int> some_list;

std::mutex some_mutex;

void add_to_list(int new_value)
{
    std::lock_guard<std::mutex> guard(some_mutex); // 3
    some_list.push_back(new_value);
}

bool list_contains(int value_to_find)
{
    std::lock_guard<std::mutex> guard(some_mutex); // 4
    return std::find(some_list.begin(), some_list.end(), value_to_find) != some_list.end();
}