#include<bits/stdc++.h>
using namespace std;
int table[1000];

void ShiftTableCompute(string ptr)
{
    int i, j, m = ptr.length();
    for(i=0; i<1000; i++)
        table[i] = m;
    for(j=0; j<m-1; j++)
        table[ptr[j]] = m-1-j;
}

int Horspool(string str, string ptr)
{
    ShiftTableCompute(ptr);
    int n = str.length();
    int m = ptr.length();
    int i = m-1;
    int k;
    while(i<=n-1)
    {
        k = 0;
        while(k<m && ptr[m-1-k]==str[i-k])
        {
            k++;
        }
        if(k==m)
        {
            return i-m+1;
        }
        else
        {
            i = i + table[str[i]];
        }
    }
    return -1;
}

int main()
{
    string str, ptr;
    cout<<"Enter text";
    cin>>str;
    cout<<"Enter pattern";
    cin>>ptr;
    int res = Horspool(str, ptr);
    if(res==-1)
    {
        cout<<"Pattern not found";
    }
    else
    {
        cout<<"Pattern found at index "<<res+1;
    }
}