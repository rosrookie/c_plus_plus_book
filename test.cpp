/*
 * @Author: Loren
 * @Date: 2022-04-18 23:21:19
 * @LastEditTime: 2022-05-05 23:52:09
 * @FilePath: /c_plus_plus_book/test.cpp
 * @Description:
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char **argv)
{

    string str = "Hkllo";
    string phrase = "Hello World";
    string slang = "Hiya";

    cout << (str > phrase) << endl;
    cout << (slang > str) << endl;
}