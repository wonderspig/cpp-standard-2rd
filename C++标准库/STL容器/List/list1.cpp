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
#include <list>
#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std;
//打印链表l1和l2
void printLists (const list<int>& l1, const list<int>& l2)
{
    cout << "list1: ";
    copy (l1.cbegin(), l1.cend(), ostream_iterator<int>(cout," "));
    cout << endl << "list2: ";
    copy (l2.cbegin(), l2.cend(), ostream_iterator<int>(cout," "));
    cout << endl << endl;
}

int main()
{
    // create two empty lists
    list<int> list1, list2; //创建两个空链表

    // fill both lists with elements
    for (int i=0; i<6; ++i) {
        list1.push_back(i);  //list1:0，1，2，3，4，5
        list2.push_front(i); //list2:5，4，3，2，1，0
    }
    printLists(list1, list2); //打印链表l1和l2

    // insert all elements of list1 before the first element with value 3 of list2
    // - find() returns an iterator to the first element with value 3
    //在l2链表中找到值为3的位置pos，把链表l1的全部内容，移动插入这个位置pos之前
    list2.splice(find(list2.begin(),list2.end(),  // destination position
                      3),
                 list1);                          // source list
    printLists(list1, list2); //打印链表l1和l2(l1为空)

    // move first element of list2 to the end
    //把l2的第一个元素，移动到l2的尾部位置pos
    list2.splice(list2.end(),        // destination position
                 list2,              // source list
                 list2.begin());     // source position
    printLists(list1, list2); //打印链表l1和l2

    // sort second list, assign to list1 and remove duplicates
    list2.sort(); //对l2进行泡嘘
    list1 = list2; //把l2赋值给l1
    list2.unique(); //把l2中相邻且值相同的重复元素删除(只保留一个)
    printLists(list1, list2); //打印链表l1和l2

    // merge both sorted lists into the first list
    list1.merge(list2); //把已排序的l1和l2进行合并(目的地为l1)
    printLists(list1, list2); //打印链表l1和l2
}
