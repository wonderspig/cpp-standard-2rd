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
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main()
{
    // two shared pointers representing two persons by their name
    shared_ptr<string> pNico(new string("nico")); //构造一个指向string的智能指针
    shared_ptr<string> pJutta(new string("jutta")); //构造一个指向string的智能指针

    // capitalize person names
    (*pNico)[0] = 'N'; //*pNico是一个string，也就是访问string的第一个元素
    pJutta->replace(0,1,"J"); //调用string类的成员函数replace(替换)
    
    // put them multiple times in a container
    vector<shared_ptr<string>> whoMadeCoffee; //把智能指针安插进容器，容器默认都是按值传递，所以复制的是智能指针，而不是真实的数据
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pJutta);
    whoMadeCoffee.push_back(pNico);
    whoMadeCoffee.push_back(pJutta); //多次的安插导致有多个智能指针指向同一个目标
    whoMadeCoffee.push_back(pNico);

    // print all elements
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  ";
    }
    cout << endl;

    // overwrite a name again
    *pNico = "Nicolai"; 

    // print all elements again
    for (auto ptr : whoMadeCoffee) {
        cout << *ptr << "  ";
    }
    cout << endl;
    
    // print some internal data
    cout << "use_count: " << whoMadeCoffee[0].use_count() << endl; //use_count是智能指针的成员函数，用来统计当前目标有多少个拥有者
}
