<!--
 * @Author: Loren
 * @Date: 2022-04-22 17:07:18
 * @LastEditTime: 2022-04-22 17:18:41
 * @FilePath: /c_plus_plus_book/gitbook/concurrency_3.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Loren, All Rights Reserved. 
-->

# 线程间共享数据

线程间潜在问题就是修改共享数据。

## 条件竞争
经常发生在多个对象对一个数据块内容进行修改的时候。

### 避免条件竞争
使用互斥量(mutex)，即 `std::mutex`创建互斥量，然后通过成员函数 `lock()` 进行上锁，再通过 `unlock()` 进行解锁。但是在实际编程的时候，不推荐去调用，因为调用就意味着在出口必须解锁。

C++11提供了一个 `std::lock_guard`，会在构造对象的时候提供已锁的互斥量，并在析构的时候进行解锁。

下面的例子展示了如何使用 `std::mutex` 和 `std::lock_guard`，对一个列表进行访问保护。使用上述对象都在 `<mutex>` 头文件中

```C++
#include <list>
#include <mutex>
#include <algorithm>
std::list<int> some_list; // 1
std::mutex some_mutex; // 2
void add_to_list(int new_value)
{
std::lock_guard<std::mutex> guard(some_mutex); // 3
some_list.push_back(new_value);
}
bool list_contains(int value_to_find)
{
std::lock_guard<std::mutex> guard(some_mutex); // 4
return std::find(some_list.begin(),some_list.end(),value_to_find) != some_list.end()
;
}
```