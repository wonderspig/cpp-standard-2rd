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
#include <array>
#include <algorithm>
#include <functional>
#include <numeric>
#include "print.hpp"
using namespace std;

int main()
{
    // create array with 10 ints
    array<int,10> a = { 11, 22, 33, 44 }; //用初值列对array进行初始化，剩余的元素初始化为0

    PRINT_ELEMENTS(a); //打印array中的值

    // modify last two elements
    a.back() = 9999999; //在最后压入一个9999999
    a[a.size()-2] = 42; //把当前array的倒数第二个值改为42
    PRINT_ELEMENTS(a); //打印array中的值

    // process sum of all elements
    cout << "sum: " 
         << accumulate(a.begin(),a.end(),0) //对array中所有值求和
         << endl;

    // negate all elements
    // 对array中所有值取反后，放回array中
    transform(a.begin(),a.end(),    // source
              a.begin(),            // destination
              negate<int>());       // operation
    PRINT_ELEMENTS(a); //打印当前array中的值
}

