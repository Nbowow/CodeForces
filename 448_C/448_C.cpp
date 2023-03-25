//배열 0부터가 아닌 1부터 입력받으니까 너무 복잡하다.
//앞으로 0부터 받도록하자..

#include <cstdio>
#include <bits/stdc++.h>
#include <windows.h>

using namespace std;


int stroke(int n, int A[])
{
    int mn, ans, p, q;
    int cnt = 0;
    //printf("hi I'm %d\n", n);
    //Sleep(1000);
    mn = 1000000000;
    for(int i=1; i<=n; i++)
        mn = min(mn, A[i]);

    for(int i=1; i<=n; i++)
        A[i] -= mn;

    ans = mn; //가로 stroke
    //printf("ans = %d\n", ans);
    p = 1;
    
    while(p < n) {
        //printf("cnt : %d\n", cnt);
        while(p < n && A[p] == 0) p++;
        
        if(p == n+1) break;
        
        q = p;
        while(q < n && A[q+1] > 0) q++;
        //printf("p : %d, q : %d\n", p, q);
        ans += stroke(q-p+1, A+p-1); //A+p-1 이 매우중요!!!(이것때문에 2시간 날림..)
        //cnt += 1;
    }

    return min(n, ans);
    
}

int main()
{
    int n;
    int A[6000];

    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d", &A[i]);
    }
    printf("%d", stroke(n, A));

    return 0;
}