#include <iostream>
#include <stdio.h>
#include <stack>

using namespace std;

#define MAX 10
#define MaxInt 1000

typedef struct
{
    char start;
    char terminal;
    char city[MAX];
    int vexnum;
    int arcs[MAX][MAX];
    bool S[MAX];
    int D[MAX];
    int Path[MAX];
    stack<char> out;
} Graph;


void ShortestPath_DIJ(Graph &G, int v0)
{
    int n = G.vexnum;
    int v=0;
    for(v=0; v<n; ++v)
    {
        G.S[v]=false;
        G.D[v]=G.arcs[v0][v];
        if(G.D[v]<MaxInt)
            G.Path[v]=v0;
        else
            G.Path[v]=-1;
    }
    G.S[v0]=true;
    G.D[v0]=0;
    //cout<<G.D[0]<<G.D[1]<<G.D[2]<<endl;
    //cout<<G.Path[0]<<G.Path[1]<<G.Path[2]<<endl;
    //初始化结束
    for(int i=1; i<n; ++i)
    {
        int min=MaxInt;
        for(int w=0; w<n; ++w)
        {
            if(!G.S[w]&&G.D[w]<min)
            {
                v=w;
                min=G.D[w];
            }
        }
        G.S[v]=true;
        for(int w=0; w<n; ++w)
        {
            if(!G.S[w]&&(G.D[v]+G.arcs[v][w]<G.D[w]))
            {
                G.D[w]=G.D[v]+G.arcs[v][w];
                G.Path[w]=v;
            }
        }
    }
}

void InitGarcs(Graph &G)
{
    for (int i=0; i<MAX; i++)
        for(int j=0; j<MAX; j++)
            G.arcs[i][j] = MaxInt;
}

int main()
{
    while(1)
    {
        int Dout[MAX];
        int n=0;
        Graph G[MAX];
        while(1)
        {
            InitGarcs(G[n]);

            int m, a;
            scanf("%d %d",&G[n].vexnum,&m);

            if(G[n].vexnum==0&&m==0)
                break;

            for(int i=0; i<G[n].vexnum; ++i)
            {
                scanf(" %c",&G[n].city[i]);
            }
            //cout << G.vexnum<<m<<G.city[m-3]<<G.city[m-2]<<G.city[m-1]<<endl;
            for (int i=0; i<m; ++i)
            {
                char v,t;
                scanf(" %c %c %d",&v,&t, &a);
                G[n].arcs[v-65][t-65]=a;
                //cout<<(int)v<<endl<<(int)t<<endl<<G.arcs[v-65][t-65]<<endl;
            }
            scanf(" %c %c",&G[n].start,&G[n].terminal);
            //cout<<G.start<<G.terminal<<endl;
            ShortestPath_DIJ(G[n],(int)G[n].start-65);
            //cout<<G.D[0]<<G.D[1]<<G.D[2]<<endl;
            //cout<<G.Path[0]<<G.Path[1]<<G.Path[2]<<endl;

            int p = (int)G[n].terminal - 65;
            G[n].out.push((char)(p+65));
            while(G[n].Path[p]!=(int)G[n].start-65)
            {
                //cout<<(char)(p+65)<<' ';
                p=G[n].Path[p];
                G[n].out.push((char)(p+65));
            }
            G[n].out.push(G[n].start);
            G[n].out.push('\n');
            Dout[n]=G[n].D[G[n].terminal-65];
            ++n;
            //cout<<G.terminal<<endl;
            //for(int i =0; i<m; ++i)
            //  cout<<a<<endl<<G.arcs[0][0]<<endl<<G.arcs[0][1]<<G.arcs[1][2]<<endl;
        }


        cout<<endl;
        for(int i=0;i<n; i++)
        {
            while(!G[i].out.empty())
            {
                if(G[i].out.top()=='\n')
                {
                    cout<<Dout[i];
                    cout<<G[i].out.top();
                    G[i].out.pop();
                }
                cout<<G[i].out.top()<<' ';
                G[i].out.pop();
            }
            cout<<endl;
        }
    }
}
