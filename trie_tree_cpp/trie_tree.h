/*
 * File: trie_tree.h
 * Created Date: Saturday, August 31st 2019, 11:12:42 am
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
#ifndef __TRIE_TREE_H__
#define __TRIE_TREE_H__
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

struct trieNode_t
{
    std::unordered_map<char, trieNode_t *> childs;
    int prefixes;
    bool wordend;
    trieNode_t()
    {
        prefixes = 0;
        wordend = false;
    }
};

class trieTree_t
{
private:
    trieNode_t *root;
    int wordcnt;

public:
    trieTree_t(/* args */)
    {
        root = new trieNode_t();
        wordcnt = 0;
    }
    ~trieTree_t()
    {
    }

public:
    bool search(std::string word);
    int freqency(std::string word);
    int insert(std::string word);
    int delaword(std::string word);
    int size() const;
};

#endif