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
    vector<int> AD; //child��
    vector<int> DR; //edge�� ���⼺
    vector<int> RS; //child���� ���� �� ����
};

Node C[100005];

int dfs1(int nd, int PT) //�Ʒ��ʿ��� �޾Ƽ� �ø��� �͸� ���
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
            rt += C[nd].RS[i] + C[nd].DR[i]; //�Ʒ��ʿ��� ���� �� + �ڽ��� ���⼺
    C[nd].dsum = rt; //���⿡ �ڱ� �Ʒ��� ���� ��������
    return rt;
}

void dfs2(int nd, int pt, int uans, int dr) //������ �������� �� ���
{
    int i,s;
    s = C[nd].AD.size();
    if(pt == 0) { //�ڽ��� ��Ʈ��� �ΰ��
        C[nd].ans = C[nd].dsum;
    }
    else {
        if(dr == 0) //������ �������̸� ���� ������
            C[nd].ans = uans + 1;
        else //������ �������̸� ���� ������
            C[nd].ans = uans - 1;
    }
 
    for(i=0; i<s; i++) { 
        if(C[nd].AD[i] != C[nd].pt) {
            dfs2(C[nd].AD[i], nd, C[nd].ans, C[nd].DR[i]);
            //C[nd].AD�� �ڽ�, nd�� �� �ڽ�
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
        C[x].AD.push_back(y); C[x].DR.push_back(0); //0�� ������
        C[x].RS.push_back(0); //�Ʒ��ʿ��� ���� ��
        C[y].AD.push_back(x); C[y].DR.push_back(1); //1�� ������
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