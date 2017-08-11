/* The following code example is taken from the book
 * "The C++ Standard Library - A Tutorial and Reference, 2nd Edition"
 * by Nicolai M. Josuttis, Addison-Wesley, 2012
 *
 * (C) Copyright Nicolai M. Josuttis 2012.
 * Permission to copy, use, modify, sell and distribute this software
 * is granted provided this copyright notice appears in all copies.
 * This software is provided "as is" without express or implied
 * warranty, and with no claim as to its suitability for any purpose.
 */
#include <iostream>
#include <deque>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    // create empty deque of strings
    deque<string> coll; //创建一个空的deque，元素类型为string

    // insert several elements
    coll.assign (3, string("string")); //给coll赋值3个"string"
    coll.push_back ("last string"); //在容器最后压入一个"last string"
    coll.push_front ("first string"); //在容器开头压入一个"first string"

    // print elements separated by newlines
    copy (coll.cbegin(), coll.cend(),
          ostream_iterator<string>(cout,"\n")); //使用迭代器，用拷贝算法输出coll容器的内容
    cout << endl;

    // remove first and last element
    coll.pop_front(); //删除容器第一个元素
    coll.pop_back(); //删除容器最后一个元素

    // insert "another" into every element but the first
    for (unsigned i=1; i<coll.size(); ++i) {
        coll[i] = "another " + coll[i]; //用元素索引来访问并修改容器内容(从第二个元素开始修改)
    }

    // change size to four elements
    coll.resize (4, "resized string"); //把容器大小调整为4，多出来的元素使用"resized string"来初始化

    // print elements separated by newlines
    copy (coll.cbegin(), coll.cend(),
          ostream_iterator<string>(cout,"\n")); //使用迭代器，用拷贝算法输出coll容器的内容
}
