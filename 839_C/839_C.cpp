#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n;

class Node {
public:
    int pt;
    int nchild;
    vector<int> AD;
};

Node C[100005]; //전역변수로 만들면 0으로 초기화 되어 있다.

void dfs1(int nd, int PT)
{
    int i, s;
    C[nd].pt = PT;
    s = C[nd].AD.size();
    C[nd].nchild = 0;
    for(i=0; i<s; i++) {
        if(C[nd].AD[i] != PT) {
            C[nd].nchild++;
            dfs1(C[nd].AD[i], nd);
        }
    }
}

double dfs2(int nd) 
{
    int i, s;
    double retv;
    retv = 0;
    if(C[nd].nchild == 0) return 0;
    
    s = C[nd].AD.size();
    for(i=0; i<s; i++) {
        if(C[nd].AD[i] != C[nd].pt) {
            retv += dfs2(C[nd].AD[i]) + 1;
        }
    }
    return retv / C[nd].nchild;
}

int main()
{
    int i, x, y;
    double ans;
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        scanf("%d %d", &x, &y);
        C[x].AD.push_back(y);
        C[y].AD.push_back(x);
    }
    dfs1(1, 0);
    ans = dfs2(1);
    printf("%f", ans);

    return 0;
}