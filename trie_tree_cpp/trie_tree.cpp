/*
 * File: trie_tree.cpp
 * Created Date: Saturday, August 31st 2019, 3:35:08 pm
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

#include <vector>
#include "trie_tree.h"

bool trieTree_t::search(std::string word)
{
    trieNode_t *current = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        trieNode_t *node = current->childs[ch];
        if (!node)
            return false;
        current = node;
    }
    return current->wordend;
}

int trieTree_t::freqency(std::string word)
{
    trieNode_t *current = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        trieNode_t *node = current->childs[ch];
        if (!node)
        {
            return 0;
        }
        current = node;
    }
    return current->prefixes;
}

int trieTree_t::insert(std::string word)
{
    trieNode_t *current = this->root;
    for (int i = 0; i < word.size(); i++)
    {
        char ch = word[i];
        trieNode_t *node = current->childs[ch];
        if (!node)
        {
            node = new trieNode_t();
            current->childs[word[i]] = node;
        }
        current = node;
        current->prefixes++;
    }
    current->wordend = true;
    this->wordcnt++;
    return 0;
}

int trieTree_t::delaword(std::string word)
{
    if (!this->search(word))
        return -1;
    trieNode_t *current = this->root;
    std::vector<trieNode_t *> todeletes;
    for (int i = 0; i < word.size(); ++i)
    {
        char ch = word[i];
        trieNode_t *node = current->childs[ch];
        if ((--(node->prefixes)) == 0)
        {
            todeletes.push_back(node);
            current->childs[ch] = nullptr;
        }
        current = node;
    }
    for (int i = todeletes.size() - 1; i >= 0; --i)
    {
        delete todeletes[i];
    }
    this->wordcnt--;
    return 0;
}

int trieTree_t::size() const
{
    return this->wordcnt;
}
