/*
 * @Author: Loren
 * @Date: 2022-04-12 00:35:19
 * @LastEditTime: 2022-04-12 00:35:20
 * @FilePath: /c_plus_plus_book/code/chapter1/demo1.cpp
 * @Description: Scope Demo.
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */

/* 该程序仅仅做说明
 * 同时需要注意：函数内部不宜定义与全局变量相同的新变量
 */
#include <iostream>

int reused = 42;  // 全局变量
int main() {
  int unique = 0;  // 变量 unique 具有块作用域

  // 第一次输出：全局变量和局部变量
  std::cout << reused << " " << unique << std::endl;

  // 定义并初始化一个新的局部变量，该变量与全局变量同名，将会覆盖(隐藏)全局变量
  int reused = 0;  // 局部变量 reused 具有块作用域

  // 第二次输出：两个局部变量
  std::cout << reused << " " << unique << std::endl;

  // 第三次输出：显示访问全局变量
  std::cout << ::reused << " " << unique << std::endl;

  return 0;
}