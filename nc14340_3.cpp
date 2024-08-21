#include<bits/stdc++.h>
#include<time.h>
#include<iostream>
#include<ostream>
#include<cstdio>
#include<algorithm>
#include<iomanip>
#include<cstring>
#include<string>
#include<cmath>
#include<stack>
#include<queue>
#include<vector>
#include<set>
#include<map>
using namespace std;
#define maxn 10000000
typedef long long ll;
const int INF=0x7fffffff;//2147483647
const int SUP=0x80000000;//-2147483648
#define loop(a,b,i) for(int i=a;i<b;i++)
#define loopx(a,b,i) for(int i=a;i<=b;i++)
#define lson (p<<1)
#define rson ((p<<1)|1)
#define mid ((l+r)>>1)
#define MAX 100005
char mapp[50][50];
int d[50][50];//存储是否到达过该位置
int g[50][50];//存储火灾到达此位置时间
int dir[8][2]={1,0,-1,0,0,-1,0,1,1,1,1,-1,-1,1,-1,-1};
int n,m,flag;
struct node
{
    int x,y,t;
}now,nex;
queue <node> cot;
int judge(int x,int y)//判断是否越界及是否到达过
{
    return x>=1&&x<=n&&y>=1&&y<=m&&d[x][y]==0;
}
int bfsman(int x,int y)//人是否可以走出及最短逃离时间
{
    memset(d,0,sizeof(d));
    now.x=x;
    now.y=y;
    now.t=0;
    d[x][y]=1;
    while(!cot.empty())cot.pop();
    cot.push(now);
    while(!cot.empty())
    {
        now=cot.front();
        cot.pop();
        if(mapp[now.x][now.y]=='E')return now.t;
        for(int i=0;i<4;i++)
        {
            nex.x=now.x+dir[i][0];
            nex.y=now.y+dir[i][1];
            nex.t=now.t+1;
            if(judge(nex.x,nex.y)&&nex.t<g[nex.x][nex.y]&&mapp[nex.x][nex.y]!='#')
            {
                d[nex.x][nex.y]=1;
                cot.push(nex);
            }
        }
    }
    return -1;
}
void bfsfire(int x,int y)//火到达此位置的时间
{
    memset(d,0,sizeof(d));
    memset(g,0,sizeof(g));
    now.x=x;
    now.y=y;
    now.t=0;
    d[x][y]=1;
    g[x][y]=0;
    while(!cot.empty())cot.pop();
    cot.push(now);
    while(!cot.empty())
    {
        now=cot.front();
        cot.pop();
        for(int i=0;i<8;i++)
        {
            nex.x=now.x+dir[i][0];
            nex.y=now.y+dir[i][1];
            nex.t=now.t+1;
            if(judge(nex.x,nex.y))
            {
                d[nex.x][nex.y]=1;
                cot.push(nex);
                if(mapp[nex.x][nex.y]=='E')
                    g[nex.x][nex.y]=nex.t+1;
                else
                    g[nex.x][nex.y]=nex.t;
            }
        }
    }
}
int main()
{
    int t;
    int x,y,a,b;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                cin>>mapp[i][j];
                if(mapp[i][j]=='S')
                {
                    x=i;y=j;
                }
                if(mapp[i][j]=='*')
                {
                    a=i;b=j;
                }
            }
        bfsfire(a,b);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << g[i][j] << ' ';
        }
        cout << endl;
    }
        int ans=bfsman(x,y);
        if(ans!=-1)cout<<ans<<endl;
        else cout<<"T_T"<<endl;
    }
    return 0;
}
