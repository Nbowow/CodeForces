#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long A[500005];
long long P[500005];

int main()
{
    long long i, n, ans, total, total3, temp;
    
    scanf("%lld", &n);

    for(i=1; i<=n; i++)
        scanf("%lld", &A[i]);

    P[0] = 0;
    for(i=1; i<=n; i++)
        P[i] = P[i-1] + A[i];
    
    total = P[n];
    if(total % 3 != 0) {ans = 0;}
    else{
        total3 = total / 3;
        temp = 0;
        ans = 0;
        for(i=1; i<n; i++) {
            if(P[i] == total3 * 2)
                ans += temp;
            if(P[i] == total3)
                temp ++;
        }
    }
    printf("%lld", ans);
    return 0;
}