<!--
 * @Author: Loren
 * @Date: 2022-04-22 16:27:43
 * @LastEditTime: 2022-04-22 17:06:12
 * @FilePath: /c_plus_plus_book/gitbook/concurrency_2.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Loren, All Rights Reserved. 
-->

# 线程管理

## 线程管理基础
每个程序至少有一个线程： 执行 `main()` 函数的线程，而其余的函数有其各自的 **入口函数**。线程与原始线程，即以 `main()` 为入口函数的线程同时运行。当线程执行完入口函数后，线程也会退出。

### 启动线程
线程一般在创建对象的时候启动。

启动了线程，就需要明确一个问题：是要 **等待线程结束(加入式)**，还是让其 **自主运行(分离式)** 。无论是那种形式，都必须在 **线程对象销毁之前** 做出决定。

#### 等待线程完成
`join()`函数

该函数是一个简单粗暴的等待线程完成或者不等待。使用该函数可以保证局部变量在线程完成以后，才被销毁。在实际编程中，原始线程要么有自己的工作要做，要么启动多个子线程来做一些有用的工作，并且等到这些线程结束。

`detach()`函数

该函数可以在一个线程启动以后，对线程进行分离。意味着该线程将会在后台运行，也就意味主线程不能与之产生直接交互。也就是说， **不会等待这个线程结束**。如果线程分离，那么就不能有 `std::thread` 对象能够引用它。

#### 向线程函数传参
向线程函数传参很简单
```C++
void fun(int i, std::string const& str);
std::thread t(fun, 3, "hello");
```

但是在C++中，当指向一个 **动态变量的指针作为参数** 传递给线程的时候，需要考虑类型转换的问题
```C++
void fun(int i, std::string const& str);
void fun2(int i)
{
    char buffer[1024];
    sprintf(buffer, "%i", i);
    std::thread t(fun, 3, buffer);
    t.detach();
}
```
在这种情况下，`buffer`是一个指针变量，指向一个局部变量，然后局部变量通过 `buffer` 传递到新线程中。函数有很大可能在字面值转换为 `std::string` 对象之前崩溃。因此，需要在传递之前，完成转换
```C++
void fun(int i, std::string const& str);
void fun2(int i)
{
    char buffer[1024];
    sprintf(buffer, "%i", i);
    std::thread t(fun, 3, std::string(buffer));
    t.detach();
}
```

这一部分建议回顾C++函数传参相关内容


### 转移线程所有权
假设要写一个在后台启动线程的函数，想通过新线程返回的所有权去调用这个函数，而不是等待线程结束再去调用；或者是创建一个线程，并在函数中转移所有权，都必须要 **等待线程结束**。

C++11引入了 `std::move()`函数，可以转让对象的所有权。

```C++
void some_function();
void some_other_function();
std::thread t1(some_function); // 1
std::thread t2=std::move(t1); // 2
t1=std::thread(some_other_function); // 3
std::thread t3; // 4
t3=std::move(t2); // 5
t1=std::move(t3); // 6 赋值操作将使程序崩溃
```

通过 `std::move()`将创建线程t2以后，t1的所有权就转移给了t2。从这以后，t1和执行线程就没有关系了。

### 识别线程
`std::thread::id` 对象可以自由拷贝和对比。如果两个对象的 `std::thread::id` 相等，说明这是同一个线程，或者都没有线程。

使用 `get_id()` 可以获取到 `std::thread` 对象相关联的线程ID。如果没有线程，则返回默认值。