#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, temp, total, test, ans;
    int A[500];
    scanf("%d", &n);

    total = 0;
    
    for(int i=1; i<=n; i++) {
        scanf("%d", &A[i]);
        total += A[i];
    }

    for(int i=1; i<=n; i++) {
        for(int j=1; j<=i; j++) {
            if(A[i]>A[j]) {
                temp = A[i];
                A[i] = A[j];
                A[j] = temp;                
            }
        }
    }

    test = 0;
    ans = 0;

    for(int i=1; i<=n; i++) {
        test += A[i];
        ans += 1;
        if(test > total/2) { break;}
    }

    printf("%d", ans);
}

// 2 4 3 1 2
// 4 2 3 1 2
// 4 3 2 1 2
// 4 3 2 2 1
