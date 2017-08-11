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
#include "print.hpp"
using namespace std;

// type for runtime sorting criterion
//定义一个函数对象为排序准则
class RuntimeCmp {
  public:
    enum cmp_mode {normal, reverse}; //函数对象可以自己带状态
  private:
    cmp_mode mode;
  public:  
    // constructor for sorting criterion
    // - default criterion uses value normal
    RuntimeCmp (cmp_mode m=normal) : mode(m) { //构造函数初始化函数对象的状态
    }
    // comparison of elements
    // - member function for any element type
    template <typename T> //排序准则
    bool operator() (const T& t1, const T& t2) const {
        return mode==normal ?  t1<t2
                            :  t2<t1;
    }
    // comparison of sorting criteria判断排序准的相等的情况
    bool operator== (const RuntimeCmp& rc) const {
        return mode == rc.mode;
    }
};

// type of a set that uses this sorting criterion
typedef set<int,RuntimeCmp> IntSet; //以RuntimeCmp为排序准则(使用默认normal)，定义set容器

int main()
{
    // create, fill, and print set with normal element order
    // - uses default sorting criterion
    IntSet coll1 = { 4, 7, 5, 1, 6, 2, 5 }; //赋初值
    PRINT_ELEMENTS (coll1, "coll1: "); //打印

    // create sorting criterion with reverse element order
    RuntimeCmp reverse_order(RuntimeCmp::reverse); //创建一个排序准则对象，排序准则对象状态为reverse

    // create, fill, and print set with reverse element order
    IntSet coll2(reverse_order); //用新创建的排序准则，创建第二个set
    coll2 = { 4, 7, 5, 1, 6, 2, 5 }; //第二个set赋初值
    PRINT_ELEMENTS (coll2, "coll2: "); //打印

    // assign elements AND sorting criterion
    coll1 = coll2; //赋值，此时第二个set的排序准则也会赋值给第一个set
    coll1.insert(3); //第一个set插入3
    PRINT_ELEMENTS (coll1, "coll1: "); //打印

    // just to make sure...
    if (coll1.value_comp() == coll2.value_comp()) { //比较排序准则
        cout << "coll1 and coll2 have the same sorting criterion"
             << endl;
    }
    else {
        cout << "coll1 and coll2 have a different sorting criterion"
             << endl;
    }
}
