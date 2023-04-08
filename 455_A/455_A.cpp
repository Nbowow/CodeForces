#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    int A[100005];
    long long D[2][100005];
    long long ans;

    scanf("%d", &n);

    for(int i=0;i<n;i++)
        scanf("%d", &A[i]);

    sort(A, A+n);

    D[0][0] = 0; D[1][0] = A[0];
    for(int i=1;i<n;i++) {
        if(A[i] == A[i-1]) {
            D[0][i] = D[0][i-1];
            D[1][i] = D[1][i-1] + A[i];
        }
        else if(A[i] == A[i-1] + 1) {
            D[0][i] = max(D[0][i-1], D[1][i-1]); //지금 선택x
            D[1][i] = D[0][i-1] + A[i];//지금 선택o
        }
        else {
            D[0][i] = max(D[0][i-1], D[1][i-1]);
            D[1][i] = max(D[0][i-1], D[1][i-1]) + A[i];
        }
    }

    ans = max(D[0][n-1], D[1][n-1]);
    printf("%lld", ans);

    return 0;
}

// 2 5 5 6 7 8 8 8 9 10
// 0 2 2 10 10 17 17 17 34 34
// 2 5 10 8 17 18 26 34 26 44