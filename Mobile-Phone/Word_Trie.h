#ifndef WORD_WordTrie_H
#define WORD_WordTrie_H
#include <unordered_map>
using namespace std;

class WordWordTrieNode
{
public:
    char data;
    bool isTerminal;
    unordered_map<char,WordWordTrieNode* > children;

    WordWordTrieNode(char d)
    {
        if(d>=65 && d<=90) data = (char)(d+32);
        else data = d;
        isTerminal = false;
    }
};

class WordTrie
{
    WordWordTrieNode* root;
    int numWords;

public:

    WordTrie()
    {
        root = new WordWordTrieNode('\0');
        numWords = 0;
    }

    void addWordsHelper(char *word, WordWordTrieNode* node)
    {
        if(word[0]=='\0')
        {
            node->isTerminal = true;
            return;
        }

        char currentChar = word[0];

        //Find if a node exist or not
        WordWordTrieNode* childNode = NULL;
        if(node->children.find(currentChar)==node->children.end())
        {
            childNode = new WordWordTrieNode(currentChar);
            node->children[currentChar] = childNode;
        }
        else
        {
            childNode = node->children.find(currentChar)->second;
        }
        addWordsHelper(word+1,childNode);
    }

    void addWord(char *word)
    {
        addWordsHelper(word, root);
        numWords++;
    }

    bool findWord(char *word)
    {
        WordWordTrieNode* node = root;

        for(int i=0; word[i]!='\0'; i++)
        {
            int currentChar = word[i];
            if(word[i]>=65 && word[i]<=90) currentChar = (char)(word[i]+32);
            auto temp = node->children.find(currentChar);

            if(temp==node->children.end())
            {
                return false;
            }
            else
            {
                node = temp->second;//moving node forward will automatically make temp to move forward in next loop
            }
        }
        return node->isTerminal;//checking if that node is terminal of not.
    }
};
#endif // WORD_WordTrie_H
