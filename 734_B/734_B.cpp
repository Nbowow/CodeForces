#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, d;
    int n1, n2, ans;

    ans = 0;
    scanf("%d %d %d %d", &a, &b, &c, &d);

    n1 = min(c, d);
    n1 = min(a, n1);
    
    a -= n1;
    ans += n1*256;

    n2 = min(a, b);
    ans += n2*32;

    printf("%d", ans);

    return 0;
}