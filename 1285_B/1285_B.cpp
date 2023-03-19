#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long A[500005];
long long P[500005];
long long M[500005];


int main()
{
    long long i, j, t, n, ans, MN, Yas;
    
    scanf("%lld", &t);

    for(i=1; i<=t; i++) {
        scanf("%lld", &n);

        for(j=1; j<=n; j++) 
            scanf("%lld", &A[j]);

        P[0] = 0;
        for(int j=1; j<=n; j++)
            P[j] = P[j-1] + A[j];
        Yas = P[n];

        MN = 0;
        ans = 1;

        for(j=1; j<n; j++) {
            M[j] = P[j] - MN; //j번째 합 중 제일 큰 값
            MN = min(MN, P[j]);
            if(M[j] >= Yas) {ans = 0;}
        }

        for(j=1; j<=n; j++)
            P[j] -= A[1]; //첫번째 원소 빼고 돌리기 위한 선행작업

        MN = 0;
        for(j=2; j<=n; j++) {
            M[j] = P[j] - MN; //j번째 합 중 제일 큰 값
            MN = min(MN, P[j]);
            if(M[j] >= Yas) {ans = 0;}
        }
        
        if(ans == 1) {printf("YES\n");}
        else{printf("NO\n");}
        
    }

    return 0;
}