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
#include <forward_list>
#include "print.hpp"
using namespace std;

int main()
{
    forward_list<int> list = { 1, 2, 3, 4, 5, 97, 98, 99 }; //创建链表并用初值列赋值

    // find the position before the first even element
    auto posBefore = list.before_begin(); //取得第一个元素之前的一个元素的迭代器位置
    for (auto pos=list.begin(); pos!=list.end(); ++pos, ++posBefore) { //从第一个元素的位置处开始遍历链表
                                                                       //(分别把第一个元素位置，和第一个元素之前的元素位置，同时++，
                                                                       //一旦第一个元素找到,第一个元素之前的元素位置所在之处，就是待操作之处)
                                                                //可以把这个第一个元素之前的元素位置传入带_after后缀的成员操作函数中,进行插入
        if (*pos % 2 == 0) { //找到位置就跳出循环
            break;  // element found
        }
    }

    // and insert a new element in front of the first even element
    list.insert_after(posBefore,42); //对找到位置的前一个位置，进行后插操作
    PRINT_ELEMENTS(list); //打印链表
}
