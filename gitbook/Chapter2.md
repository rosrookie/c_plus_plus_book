<!--
 * @Author: Loren
 * @Date: 2022-05-05 22:17:33
 * @LastEditTime: 2022-05-05 23:51:45
 * @FilePath: /c_plus_plus_book/gitbook/Chapter2.md
 * @Description: 
 * 
 * Copyright (c) 2022 by Loren, All Rights Reserved. 
-->

# Chapter2

## 标准库 string

标准库`string`表示 **可变长** 的字符序列。使用该标准库必须包含 `string` 头文件，即： `#include <string>`

### 定义和初始化 string 对象
一个类可以定义多种初始化对象，只不过这些方式之间必须有所不同： **初始值数量** 或者 **初始值类型不同** 。

```C++
#include <string>
using std::string;

string s1;              // 默认初始化，s12为一个空字符串
string s2(s1);          // s2 是 s1 的副本
string s2 = s1;         // 等价于 s2(s1)， s2 是 s1 的副本
string s3("Value");     // s3 是字面值 "Value" 的副本，除了字面值最后那个空字符
string s3 = "Value";    // 等价于 s3("Value")，s3 是字面值 "Value" 的副本
string s4(n, 'c');      // 把 s4 初始化为由连续 n 个字符 c 组成的串
```

#### 直接初始化和拷贝初始化
使用 `=` 去初始化一个变量。称为 **拷贝初始化(copy initialization)** 。编译器会将等号右侧的值拷贝到新创建的对象中去。如果不使用等号，使用括号 `()` 去初始化一个变量，称为 **直接初始化(direct initialization)**。
```C++
std::string s5 = "Hello";  // 拷贝初始化
std::string s6("Hello");   // 直接初始化
std::string s7(10, 'a');   // 直接初始化
```

### string 对象上的操作
一个类除了要规定初始化其对象的方式外，还要定义对象上 **所能执行的操作**。

string 对象的大多数操作如下

|      操作      |                                      含义                                     |
|:--------------:|:-----------------------------------------------------------------------------:|
|    os << s     |                         将 s 写到输出流 os 中，返回 os                        |
|     is >> s    |              从 is 中读取字符串赋给 s ，字符串以空白分隔，返回 is             |
| getline(is, s) |                      从 is 中读取一行，赋值给 s ，返回 is                     |
|    s.empty()   |                 判断 s 是否为空。为空返回 ture，否则返回 false                |
|    s.size()    |                      返回 s 中字符的个数。不包含空字符串                      |
|      s[n]      |                    返回 s 中第 n 个字符的值，位置从 0 开始                    |
|     s1 + s2    |                           返回 s1 和 s2 连接后的结局                          |
|     s1 = s2    |                   用 s2 的副本代替 s1 中原来的字符。(赋值）                   |
|    s1 == s2    | 如果 s1 和 s2 中的字符完全一样，则相等。 string对象的相等性判断对 大小写 敏感 |
|  <, <=, >, >=  |              利用字符在字典中的顺序进行比较。且对字母的大小写敏感             |


#### 读写 string 对象
string对象会自动忽略 **开头处的空白(即：空格、换行、制表符等)，并从第一个真正的字符开始，直到遇见下一处空白为止**。
```C++
string s = "    Hello     ";
cout << s << endl;  // 输出 Hello，结果中没任何空格
```

string对象的输入输出都是 **返回运算符左侧的运算对象作为结果**。
```C++
string s1, s2;
cin >> s1 >> s2;   // 把第一个输入读到 s1 中，把第二个输入读到 s2 中
cout << s1 << s2 << endl;   // 输出两个 string 对象
```
如果给上述程序输入`    Hello   World!  `， 那么 `s1 = Hello`，`s2 = World!`

#### 读取未知数量的 string 对象
使用 `while` 循环。 TODO


#### 使用 getline 读取一整行
当想要保留输入的空白字符串的时候，就可以用 `getline()` 去代替 `>>` 运算符。

`getline()` 函数的参数是 一个输入流和一个string对象，函数读取输入流， **直到遇见换行符为止(包含换行符)** 。然后把所读取的对象存入到 string 对象中去 **(不存换行符)** 。

注意： `getline()` 只要 **一遇到换行符** 就会结束读取操作并返回。如果开始就是换行符，那么就会返回空字符。


#### string::size_type 类型

TODO


#### 比较 string 对象

需要注意的是，在比较 string 对象的时候，**对大小写敏感**。

大小的定义：

1. 如果两个 string 对象的长度不同，且 较短对象 的每个字符都与 较长对象 **对应位置上的字符相同** 。此时称： 较短的对象 **小于** 较长的对象。
2. 如果两个 string 对象在某些对应位置上不一致，则结果是 string 对象中 **第一对相异字符** 比较的结果(ASCII码)

```C++
string str = "Hello";
string phrase = "Hello World";
string slang = "Hiya";
```
根据规则1可知： `str < phrase`

根据规则2可知： `slang > str` 且 `slang > phrase`。因为 `i` 的 ASCII 码的 10机制表示为105，而 `e` 的ASCII码的10进制为 101。
