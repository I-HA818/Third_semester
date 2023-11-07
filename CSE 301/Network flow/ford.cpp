#include <iostream>
#include<bits/stdc++.h>
#include<cstring>
#include<vector>
#define Size 100

using namespace std;

string source,destination;
vector<string> Vname;
int graph[Size][Size];
int rgraph[Size][Size];
int vertex,edge;

int indexnum(string str){
    for(int i=0;i<Vname.size();i++){
        if(Vname[i]==str) return i;
    }
    return -1;
}

void readInput(){
    freopen("ford.txt","r",stdin);
    cin>>edge;
    int cost;
    string s,d;
    for(int i=0;i<edge;i++){
        cin>>s>>d>>cost;
        if(find(Vname.begin(),Vname.end(),s)==Vname.end()) Vname.push_back(s);
        if(find(Vname.begin(),Vname.end(),d)==Vname.end()) Vname.push_back(d);
            int m=indexnum(s);
            int n=indexnum(d);
            graph[m][n]=cost;
            rgraph[m][n]=graph[m][n];
    }
    cin>>source>>destination;
    vertex=Vname.size();


}

bool bfs(int parent[]){
    int s,d,u;
    queue<int> q;
    bool visited[vertex];
    for(int i=0;i<vertex;i++) visited[i]=false;
    s=indexnum(source);
    d=indexnum(destination);
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int v=0;v<vertex;v++){
            if(visited[v]==false && rgraph[u][v]>0){
                if(v==d){
                    parent[v]=u;
                    return true;
                }
                q.push(v);
                parent[v]=u;
                visited[v]=true;
            }
        }
    }
    return false;
}

int ford(){
    int i,j;
    int parent[vertex];
    int maxFlow=0;
    while(bfs(parent)){
        int flow=INT_MAX;
        int u,v,s;
        s=indexnum(source);
        v=indexnum(destination);
        while(v!=s){
            u=parent[v];
            flow=min(flow,rgraph[u][v]);
            v=parent[v];
        }
        v=indexnum(destination);
        while(v!=s){
            u=parent[v];
            rgraph[u][v]-=flow;
            v=parent[v];
        }
        maxFlow+=flow;
    }
    return maxFlow;
}


int main()
{
    readInput();
    int maxflow=ford();
    cout<<"Maximum flow is: " << maxflow <<endl;
    return 0;
}
