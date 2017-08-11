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
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <iterator>
using namespace std;

int main()
{
    // create empty vector for strings
    vector<string> sentence; //构造一个vector，元素为string，内容为空

    // reserve memory for five elements to avoid reallocation
    sentence.reserve(5); //调整容量为5个元素

    // append some elements
    sentence.push_back("Hello,"); //在最后压入一个"Hello,"
    sentence.insert(sentence.end(),{"how","are","you","?"}); //在最后插入"how","are","you","?"

    // print elements separated with spaces
    copy (sentence.cbegin(), sentence.cend(),
          ostream_iterator<string>(cout," ")); //利用迭代器使用拷贝算法进行输出
    cout << endl;

    // print "technical data"
    cout << "  max_size(): " << sentence.max_size() << endl; //打印容器能容纳的最大值
    cout << "  size():     " << sentence.size()     << endl; //打印容器中当前的元素个数
    cout << "  capacity(): " << sentence.capacity() << endl; //打印容器当前在补充锌分配内存的情况下，能容纳的元素个数

    // swap second and fourth element
    swap (sentence[1], sentence[3]); //交换容器中第2和第4个元素

    // insert element "always" before element "?"
    sentence.insert (find(sentence.begin(),sentence.end(),"?"),
                     "always"); //在"?"的位置上，前插一个"always"

    // assign "!" to the last element
    sentence.back() = "!"; //把容器中最后一个元素替换成"!"
    
    // print elements separated with spaces
    copy (sentence.cbegin(), sentence.cend(),
          ostream_iterator<string>(cout," ")); //利用迭代器使用拷贝算法进行输出
    cout << endl;

    // print some "technical data" again
    cout << "  size():     " << sentence.size()     << endl; //打印容器中当前的元素个数
    cout << "  capacity(): " << sentence.capacity() << endl; //打印容器当前在补充锌分配内存的情况下，能容纳的元素个数

    // delete last two elements
    sentence.pop_back(); //删除最后一个元素
    sentence.pop_back(); //删除最后一个元素
    // shrink capacity (since C++11)
    sentence.shrink_to_fit(); //调整容量为当前元素个数(非强制看实现)

    // print some "technical data" again
    cout << "  size():     " << sentence.size()     << endl; //打印容器中当前的元素个数
    cout << "  capacity(): " << sentence.capacity() << endl; //打印容器当前在补充锌分配内存的情况下，能容纳的元素个数
}
