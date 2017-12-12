#ifndef TRIE_H
#define TRIE_H
#include "Trie_Node.h"
#include "Hash_Table_Contact.h"
using namespace std;

class Trie
{
    TrieNode* root;
    int numContact;

public:

    Trie()
    {
        root = new TrieNode(0);
        numContact = 0;
    }

    void addNumHelper(char *num, TrieNode* node, char *n)
    {
        if(num[0]=='\0')
        {
            strcpy(node->name,n);
            node->isTerminal = true;
            return;
        }

        int currentNum = num[0]-'0';

        //Find if a node exist or not
        TrieNode* childNode = NULL;

        if(node->children[currentNum]!=NULL)
        {
            childNode = node->children[currentNum];
        }
        else
        {
            childNode = new TrieNode(currentNum);
            node->children[currentNum] = childNode;
        }
        addNumHelper(num+1,childNode,n);
    }

    void addNum(char *num, char *n)
    {
        addNumHelper(num, root, n);
        numContact++;
    }

    void findNum(char *word, hashTableContact &contact)
    {
        TrieNode* node = root;
        int i;
        for(i=0; word[i]!='\0'; i++)
        {
            int currentNum = word[i]-'0';

            if(node->children[currentNum]==NULL)
            {
                break;
            }
            else
            {
                node = node->children[currentNum];//moving node forward will automatically make temp to move forward in next loop
            }
        }
        if(word[i]=='\0')
        {
            contact.printDetails(node->name);
        }
        else
        {
            cout << "Contact Not Found\n";
        }
        return ;//checking if that node is terminal of not.
    }
};
#endif // TRIE_H
