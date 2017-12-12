#ifndef EVALUATE_POSTFIX_H
#define EVALUATE_POSTFIX_H
#include <cstring>
using namespace std;

int power(int x, int y)
{
    int ans=1;
    for(int i=1; i<=y; i++)
    {
        ans *= x;
    }
    return ans;
}

class node2
{
public:
    char ch;
    node2*next;

    node2(char c)
    {
        ch=c;
        next=NULL;
    }

    ~node2()
    {
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};

class stack2
{
public:
    node2* start;

    stack2()
    {
        start=NULL;
    }

    void pop()
    {
        if(start!=NULL)
        {
            node2 *temp = start;
            start = start->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void push(char ch)
    {
        if(start==NULL) start = new node2(ch);

        else
        {
            node2 *temp = new node2(ch);
            temp->next = start;
            start = temp;
        }
    }

    char top()
    {
        return start->ch;
    }

    bool empty()
    {
        return start==NULL ? true : false;
    }
};

int evaluatePostFix(char *a)
{
    stack2 s;

    for(int i=0; a[i]!='\0'; i++)
    {
        if(a[i]>='0' && a[i]<='9') s.push(a[i]-'0');

        else
        {
            int y=s.top();
            s.pop();
            int x=s.top();
            s.pop();
            int m = power(x,y);

            if(a[i]=='+') s.push(x+y);

            else if(a[i]=='-') s.push(x-y);

            else if(a[i]=='/') s.push(x/y);

            else if(a[i]=='*') s.push(x*y);

            else if(a[i]=='^') s.push(m);
        }
    }
    return s.top();
}
#endif // EVALUATE_POSTFIX_H
