#ifndef HASH_NODE_CONTACT_H
#define HASH_NODE_CONTACT_H
using namespace std;

class hashNodeContact
{
public:
    char *name;
    char *phone;
    char *email_id;
    hashNodeContact *next;

    hashNodeContact(char *n, char *p, char *i)
    {
        name = new char[strlen(n)+1];
        strcpy(name, n);
        phone = new char[strlen(p)+1];
        strcpy(phone, p);
        email_id = new char[strlen(i)+1];
        strcpy(email_id, i);
        next = NULL;
    }

    ~hashNodeContact()
    {
        if(next!=NULL)
        {
            delete next;
            next = NULL;
        }
        delete [] name;
        delete [] phone;
        delete [] email_id;
    }
};
#endif // HASH_NODE_CONTACT_H
