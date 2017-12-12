#ifndef HASH_TABLE_CONTACT_H
#define HASH_TABLE_CONTACT_H
#include "Hash_Node_Contact.h"
#include <cstring>
using namespace std;

class hashTableContact
{
public:
    int tableSize;
    int currentSize;
    hashNodeContact **buckets;

    int hashFunction(char *key)
    {
        int ans = 0;
        int currentPower = 1;
        int len = strlen(key);

        for(int i=0; i<len; i++)
        {
            ans += currentPower*key[len-i-1];
            currentPower *= 37;
            currentPower %= tableSize;
            ans %= tableSize;
        }
        return ans;
    }

    void reHash()
    {
        int oldTableSize = tableSize;
        tableSize *= 2;
        currentSize = 0;
        hashNodeContact **oldBuckets = buckets;
        buckets = new hashNodeContact *[tableSize];
        for(int i=0; i<tableSize; i++)
        {
            buckets[i]=NULL;
        }

        for(int i=0; i<oldTableSize; i++)
        {
            hashNodeContact *temp = oldBuckets[i];
            while(temp)
            {
                insert(temp->name, temp->phone, temp->email_id);
                temp = temp->next;
            }
            delete oldBuckets[i];
        }
        delete [] oldBuckets;
    }

    hashTableContact()
    {
        currentSize = 0;
        tableSize = 7;
        buckets = new hashNodeContact *[tableSize];
        for(int i=0; i<tableSize; i++)
        {
            buckets[i] = NULL;
        }
    }

    void insert(char *key, char *p, char *i)
    {
        int z = hashFunction(key);

        hashNodeContact *node = new hashNodeContact(key, p, i);
        node->next = buckets[z];
        buckets[z] = node;
        currentSize++;

        float loadFactor = (float)currentSize/tableSize;
        if(loadFactor > 0.7)
        {
            reHash();
        }
    }

    hashNodeContact *find(char *key)
    {
        int i = hashFunction(key);

        hashNodeContact *temp = buckets[i];

        while(temp)
        {
            if(strcmp(key, temp->name)==0)
            {
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }

    void remove(char *key)
    {
        int i = hashFunction(key);

        hashNodeContact *temp = buckets[i];

        if(strcmp(key,buckets[i]->name)==0)
        {
            buckets[i] = buckets[i]->next;
            temp->next=NULL;
            delete temp;
        }
        else
        {
            while(temp)
            {
                if(strcmp(key, buckets[i]->name)==0)
                {
                    hashNodeContact *target = temp;
                    target = target->next;
                    temp->next = target->next;
                    delete target;
                    target = NULL;
                    return;
                }
                temp = temp->next;
            }
        }
    }

    void printNames()
    {
        int k=1;
        for(int i=0; i<tableSize; i++)
        {
            hashNodeContact *temp = buckets[i];
            while(temp)
            {
                cout << k << ". " << temp->name << endl;
                temp = temp->next;
                k++;
            }
        }
    }

    void printDetails(char *key)
    {
        hashNodeContact *temp = find(key);
        if(temp!=NULL)
        {
            cout << "Name               :   " << temp->name << endl;
            cout << "Phone              :   " << temp->phone << endl;
            cout << "Email ID           :   " << temp->email_id << endl;
        }
        else
        {
            cout << "Contact Not Found" << endl;
        }
        return;
    }

    ~hashTableContact()
    {
        for(int i=0; i<tableSize; i++)
        {
            if(buckets[i]!=NULL)
            {
                delete buckets[i];
            }
        }
        delete [] buckets;
    }
};
#endif // HASH_TABLE_CONTACT_H

