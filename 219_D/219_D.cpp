#include <cstdio>
#include <bits/stdc++.h>

using namespace std;

int n;

class Node{
public:
    int pt;
    int dsum;
    int nchild;
    int ans;
    vector<int> AD; //child들
    vector<int> DR; //edge의 방향성
    vector<int> RS; //child마다 받은 값 저장
};

Node C[100005];

int dfs1(int nd, int PT) //아래쪽에서 받아서 올리는 것만 계산
{
    int i, s, rt;
    C[nd].pt = PT;
    s = C[nd].AD.size();
    C[nd].nchild = 0;
    rt = 0;
    for(i=0; i<s; i++) {
        if(C[nd].AD[i] != C[nd].pt) {
            C[nd].nchild++;
            C[nd].RS[i] = dfs1(C[nd].AD[i], nd);
        }
    }
    for(i=0; i<s; i++)
        if(C[nd].AD[i] != C[nd].pt)
            rt += C[nd].RS[i] + C[nd].DR[i]; //아래쪽에서 받은 값 + 자신의 방향성
    C[nd].dsum = rt; //여기에 자기 아래쪽 값이 적혀있음
    return rt;
}

void dfs2(int nd, int pt, int uans, int dr) //위에서 내려오는 것 계산
{
    int i,s;
    s = C[nd].AD.size();
    if(pt == 0) { //자신이 루트노드 인경우
        C[nd].ans = C[nd].dsum;
    }
    else {
        if(dr == 0) //위에서 정방향이면 나는 역방향
            C[nd].ans = uans + 1;
        else //위에서 역방향이면 나는 정방향
            C[nd].ans = uans - 1;
    }
 
    for(i=0; i<s; i++) { 
        if(C[nd].AD[i] != C[nd].pt) {
            dfs2(C[nd].AD[i], nd, C[nd].ans, C[nd].DR[i]);
            //C[nd].AD는 자식, nd는 나 자신
        }
    }
    return;
}

int main()
{
    int i, x, y;
    int ans;
    scanf("%d", &n);
    for(i=1; i<n; i++) {
        scanf("%d %d", &x, &y);
        C[x].AD.push_back(y); C[x].DR.push_back(0); //0은 정방향
        C[x].RS.push_back(0); //아래쪽에서 받은 값
        C[y].AD.push_back(x); C[y].DR.push_back(1); //1은 역방향
        C[y].RS.push_back(0);
    }
    dfs1(1, 0);
    dfs2(1, 0, 0, 0);
    ans = 300000;

    for(i=1; i<=n; i++) ans = min(ans, C[i].ans);
    printf("%d\n", ans);
    for(i=1; i<n; i++) {
        if(i>1) printf(" ");
        if(ans == C[i].ans) printf("%d", i);
    }
    printf("\n");
    return 0;
}