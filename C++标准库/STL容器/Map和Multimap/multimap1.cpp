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
#include <map>
#include <string>
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    // create multimap as string/string dictionary
    multimap<string,string> dict; //创建一个空的multimap

    // insert some elements in random order
    dict.insert ( { {"day","Tag"}, {"strange","fremd"},
                    {"car","Auto"}, {"smart","elegant"},
                    {"trait","Merkmal"}, {"strange","seltsam"},
                    {"smart","raffiniert"}, {"smart","klug"},
                    {"clever","raffiniert"} } ); //使用初值列的方式插入值

    // print all elements 设置流格式之后，打印map所有内容
    cout.setf (ios::left, ios::adjustfield);
    cout << ' ' << setw(10) << "english "
         << "german " << endl;
    cout << setfill('-') << setw(20) << ""
         << setfill(' ') << endl;
    for ( const auto& elem : dict ) {
        cout << ' ' << setw(10) << elem.first
             << elem.second << endl;
    }
    cout << endl;

    // print all values for key "smart" 打印map中key为smart的内容
    string word("smart"); //创建一个string(用来在map中搜索)
    cout << word << ": " << endl;
    for (auto pos = dict.lower_bound(word);
         pos != dict.upper_bound(word);
         ++pos) {
            cout << "    " << pos->second << endl; //打印key为smart的内容
    }

    // print all keys for value "raffiniert" 同理打印key为raffiniert的内容
    word = ("raffiniert");
    cout << word << ": " << endl;
    for (const auto& elem : dict) {
        if (elem.second == word) {
            cout << "    " << elem.first << endl;
        }
    }
}
