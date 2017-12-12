#ifndef INFIX_TO_POSTFIX_H
#define INFIX_TO_POSTFIX_H
#include <cstring>
using namespace std;

class node
{
public:
    char ch;
    node* next;

    node(char c)
    {
        ch=c;
        next=NULL;
    }

    ~node()
    {
        if(next!=NULL)
        {
            delete next;
            next=NULL;
        }
    }
};

class stack
{
public:
    node* start;

    stack()
    {
        start=NULL;
    }

    void pop()
    {

        if(start!=NULL)
        {
            node *temp = start;
            start = start->next;
            temp->next = NULL;
            delete temp;
        }
    }

    void push(char ch)
    {
        if(start==NULL) start = new node(ch);

        else
        {
            node *temp = new node(ch);
            temp->next = start;
            start = temp;
        }
    }

    char top()
    {
        if(start!=NULL)
        {
            return start->ch;
        }
    }

    bool empty()
    {
        return start==NULL ? true : false;
    }
};

void convertToPostFix(char *inFix, char *postFix)
{
    stack s;
    s.push('(');

    int i=0,k=0;
    while(!s.empty())
    {
        if(inFix[i]=='(')
        {
            s.push('(');
        }
        else if(inFix[i]==')')
        {
            while(s.top()!='(')
            {
                postFix[k]=s.top();
                k++;
                s.pop();
            }
            s.pop();
        }
        else if(inFix[i]=='+' || inFix[i]=='-' || inFix[i]=='/' || inFix[i]=='*' || inFix[i]=='^')
        {
            if(inFix[i]=='+' || inFix[i]=='-')
            {
                if(s.top()=='*' || s.top()=='/' || s.top()=='^')
                {
                    postFix[k]=s.top();
                    k++;
                    s.pop();
                    s.push(inFix[i]);
                }
                else s.push(inFix[i]);
            }
            else if(inFix[i]=='*' || inFix[i]=='/')
            {
                if(s.top()=='^')
                {
                    postFix[k]=s.top();
                    k++;
                    s.pop();
                    s.push(inFix[i]);
                }
                else s.push(inFix[i]);
            }
            else if(inFix[i]=='^') s.push(inFix[i]);
        }
        else
        {
            postFix[k]=inFix[i];
            k++;
        }
        i++;
    }
    postFix[k]='\0';
}
#endif // INFIX_TO_POSTFIX_H
