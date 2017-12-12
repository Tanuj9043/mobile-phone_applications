#ifndef EDIT_DISTANCE_H
#define EDIT_DISTANCE_H
#include <cstring>
using namespace std;

int editDistance(char *a, char *b, int i, int j)
{
    if(i==0)
    {
        return j;
    }
    if(j==0)
    {
        return i;
    }

    if(a[i-1]==b[j-1])
    {
        return editDistance(a, b, i-1, j-1);
    }
    else
    {
        int ins = 1 + editDistance(a, b, i, j-1);

        int del = 1 + editDistance(a, b, i-1, j);

        int rep = 1 + editDistance(a, b, i-1, j-1);

        return min(ins, min(del, rep));
    }
}
#endif // EDIT_DISTANCE_H
