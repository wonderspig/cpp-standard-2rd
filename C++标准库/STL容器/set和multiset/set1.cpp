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
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    // type of the collection:
    // - no duplicates
    // - elements are integral values
    // - descending order
    set<int,greater<int>> coll1; //创建一个容器set，>为排序准则

    // insert elements in random order using different member functions
    coll1.insert({4,3,5,1,6,2});
    coll1.insert(5); //插入会失败

    // print all elements打印容器内容
    for (int elem : coll1) {
        cout << elem << ' ';
    }
    cout << endl;

    // insert 4 again and process return value
    auto status = coll1.insert(4); //插入个4，接受返回值，看看是否成功
    if (status.second) { //如果成功，打印以下，新元素的位置
        cout << "4 inserted as element "
             << distance(coll1.begin(),status.first) + 1 << endl;
    }
    else {
        cout << "4 already exists" << endl; //否则打印，此元素值已存在
    }

    // assign elements to another set with ascending order
    set<int> coll2(coll1.cbegin(),coll1.cend()); //创建第二个容器(和第一个容器得当前值一样),已<为排序准则
    
    // print all elements of the copy using stream iterators 打印第二个容器的内容
    copy (coll2.cbegin(), coll2.cend(),
          ostream_iterator<int>(cout," "));
    cout << endl;

    // remove all elements up to element with value 3
    coll2.erase (coll2.begin(), coll2.find(3)); //删除第二个容器到数值3之前的所有内容

    // remove all elements with value 5
    int num;
    num = coll2.erase (5); //删除数值为5的所有元素，并关心删除了多少个元素，set不是0就是1
    cout << num << " element(s) removed" << endl;

    // print all elements打印第二个容器的内容
    copy (coll2.cbegin(), coll2.cend(),
          ostream_iterator<int>(cout," "));
    cout << endl;
}
