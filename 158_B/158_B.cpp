#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, a, b, c, d, ans, rest;
    a = 0;
    b = 0;
    c = 0;
    d = 0;
    ans = 0;
    rest = 0;

    int S[500005];
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
    {
        scanf("%d", &S[i]);
        if(S[i] == 1) { a += 1;}
        else if(S[i] == 2) { b += 1;}
        else if(S[i] == 3) { c += 1;}
        else { d += 1;}
    }
    ans += d;

    ans += c;
    a -= c;
    if(a<0) { a = 0;}

    ans += b/2;
    rest = b - (b/2)*2;
    if(rest>0) { 
        ans += 1;
        a -= 2;
    }
    if(a<0) { a = 0;}

    if(a>0) {
        ans += a/4;
        rest = a - (a/4)*4;
        if(rest>0) { ans += 1;}
    }
    
    printf("%d", ans);
    return 0;
}