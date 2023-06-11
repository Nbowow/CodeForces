#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

long long n, m, L, R, V;
long long A[200005];
class Node {
public:
    long long mn, upd;
    long long Left, Right;

};

Node T[1000000];

long long build(long long nd, long long lf, long long rg)
{
    long long mid, lr, rr; //left return, rignt return
    T[nd].Left = lf;
    T[nd].Right = rg;
    if(lf == rg) { //leaf 노드
        T[nd].mn = A[lf];
        T[nd].upd = 0;
    }
    else {
        mid = (lf+rg)/2;
        lr = build(nd*2, lf, mid);
        rr = build(nd*2+1, mid+1, rg);
        T[nd].mn = min(lr, rr);
        T[nd].upd = 0;
    }
    return T[nd].mn + T[nd].upd;
}

long long query(long long nd, long long lf, long long rg)
{
    long long mid, lr, rr;
    if(lf <= T[nd].Left && rg >=T[nd].Right) { //전부
        return T[nd].mn + T[nd].upd;
    }
    else {
        mid = (T[nd].Left + T[nd].Right)/2;
        if(rg <= mid) { //왼쪽만으로 해결
            return (lr = query(nd*2, lf, rg) + T[nd].upd);
        }
        else if(lf > mid) { //오른쪽만으로 해결
            return (rr = query(nd*2+1, lf, rg) + T[nd].upd);
        }
        else {
            lr = query(nd*2, lf, rg);
            rr = query(nd*2+1, lf, rg);
            return min(lr, rr) +T[nd].upd;
        }
    }
}

void update(long long nd, long long lf, long long rg, long long v)
{
    long long mid;
    if(lf<=T[nd].Left && rg >= T[nd].Right) { //전체업뎃
        T[nd].upd += v;
    }
    else {
        mid = (T[nd].Left + T[nd].Right) / 2;
        if(rg <= mid) { //왼쪽만 업데이트
            update(nd*2, lf, rg, v);
        }
        else if(lf > mid) { //오른쪽만 업데이트
            update(nd*2+1, lf, rg, v);
        }
        else {
            update(nd*2, lf, rg, v);
            update(nd*2+1, lf, rg, v);
        }
        T[nd].mn = min(T[nd*2].mn + T[nd*2].upd, T[nd*2+1].mn + T[nd*2+1].upd);

    }
}

int main()
{
    long long i, c, PV, P1, P2;
    scanf("%lld", &n);
    for(i=1; i<=n; i++)
        scanf("%lld", &A[i]);
    build(1, 1, n);
    scanf("%lld", &m);
    for(i=1; i<=m; i++) {
        scanf("%lld%lld", &L, &R);
        L++; R++;
        c = getchar();
        if(c == '\n') { //rmq
            if(L<=R) {
                printf("요기\n");
                PV = query(1, L, R);
            }
            else {
                printf("요기2\n");
                P1 = query(1, L, n);
                P2 = query(1, 1, R);
                PV = min(P1, P2);
            }
            printf("%lld\n", PV);
        }
        else { //inc
            scanf("%lld", &V);
            if(L<=R) {
                printf("요기3\n");
                update(1, L, R, V);
            }
            else {
                printf("요기4\n");
                update(1, L, n, V);
                update(1, 1, R, V);
            }
        }
    }
    
    return 0;

}