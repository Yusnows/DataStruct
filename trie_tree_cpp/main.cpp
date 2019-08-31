/*
 * File: main.cpp
 * Created Date: Saturday, August 31st 2019, 4:11:17 pm
 * Author: yusnows
 * -----
 * Last Modified: Sat Aug 31 2019
 * Modified By: yusnows
 * -----
 * Copyright (c) 2019 nju-visg
 * 
 * All shall be well and all shall be well and all manner of things shall be well.
 * Nope...we're doomed!
 * -----
 * HISTORY:
 * Date      	By	Comments
 * ----------	---	----------------------------------------------------------
 */

#include <iostream>
#include "trie_tree.h"
using namespace std;

int main()
{
    trieTree_t trietree;
    trietree.insert("harshita");
    trietree.insert("harsh");
    trietree.insert("sharma");
    trietree.insert("harry");

    trietree.insert("Liang Yuqin");
    trietree.insert("Liang Yubin");
    trietree.insert("Liang Qiuli");
    trietree.insert("Fang Hao");
    trietree.insert("Jiang Peiyuan");
    trietree.insert("Chen Fei");
    trietree.insert("Bei Siyuan");
    trietree.insert("Zhang Rongli");
    trietree.insert("Mo Jinchen");
    trietree.insert("Ou Lin");
    string p;
    cout << "Enter the prefix :";
    cin >> p;
    cout << trietree.freqency(p) << endl;
    cout << trietree.size() << endl;
    trietree.delaword("Liang Yuqin");
    cout << trietree.freqency(p) << endl;
    cout << trietree.search("Liang Yubin") << endl;
    cout << trietree.size() << endl;

    return 0;
}
