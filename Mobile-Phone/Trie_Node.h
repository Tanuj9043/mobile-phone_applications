#ifndef TRIE_NODE_H
#define TRIE_NODE_H
#include "Hash_Table_Contact.h"
#include <cstring>
using namespace std;

class TrieNode
{
public:
    int num;
    char name[100];
    bool isTerminal;
    TrieNode* children[10];

    TrieNode(int d)
    {
        num = d;
        name[0]='\0';
        isTerminal = false;
        for(int i=0; i<10; i++) children[i]=NULL;
    }
};
#endif // TRIE_NODE_H
