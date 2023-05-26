#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int solve(int n, int l, int r)
{
    int mid, len;
    int x = 0;
    while(1)
    {
        n /= 2;
        x++;
        if(n == 1 || n == 0) break;
    }

    mid = pow(2, x);
    len = 2*(mid-1) + 1;

    if(l==1 && r==len) return n;
    if(l>mid) return solve(n/2, l-mid, r-mid);
    if(r<mid) return solve(n/2, l, r);

    if(l == mid && r == mid) return n%2; //»©¸ÔÀ½!

    if(l == mid) return solve(n/2, 1, r-mid) + n%2;
    if(r == mid) return solve(n/2, l, mid-1) + n%2;
    return solve(n/2, l, mid-1) + solve(n/2, 1, r-mid) + n%2;
}

int main()
{
    int n, l, r, mid;

    scanf("%d %d %d", &n, &l, &r);

    printf("%d", solve(n, l, r));

    return 0;
}
// 15 7 3 1
// 8 4 2 0
// 7 3 1

// 10
// 5 (0) 5
// 2 1 2 (0) 2 1 2
// 1 0 1 1 1 0 1 (0) 1 0 1 1 1 0 1 -> 8

// 7 2 5
// 3 (1) 3
// 1 [1 1 (1) 1] 1 1 -> 4

// 15
// 7 (1) 7
// 3 1 3 (1) 3 1 3
// 1 1 1 1 1 1 1 (1) 1 1 1 1 1 1 1 -> 8

// 8
// 4 (0) 4
// 2 0 2 (0) 2 0 2
// 1 0 1 0 1 0 1 (0) 1 0 1 0 1 0 1 -> 8

// 9
// 4 (1) 4
// 2 0 2 (1) 2 0 2
// 1 0 1 0 1 0 1 (1) 1 0 1 0 1 0 1 -> 8

// 4~7 : 4
// 8~15 : 8
// 2^2 ~ 2^3-1 : 2^2
// 2^3 ~ 2^4-1 : 2^3

// 2^n ~ 2^(n+1)-1: 2^n