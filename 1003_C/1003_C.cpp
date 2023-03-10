#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    int A[5005];
    int P[5005];
    double M;

    scanf("%d%d", &n, &k);
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &A[i]);
    }
    P[0] = 0;
    M = 0.0;
    for(int i=1; i<=n; i++) {
        P[i] = P[i-1] + A[i];
    }

    for(int i=k; i<=n; i++) {
        for(int j=i; j<=n; j++){
            M = max(M,double(P[j] - P[j-i]) / double(i));
        }
    }

    printf("%lf", M);

}