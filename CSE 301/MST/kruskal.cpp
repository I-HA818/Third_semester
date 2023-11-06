#include <iostream>
#include<string>
#include<vector>
#include <utility>
#include <algorithm>

using namespace std;
const int N=1e5+10;
int parent[N];
int size[N];
int nodes,edges;
 vector<pair<int,pair<int,int>>> E;

void Make(int v){
    parent[v]=v;
    size[v]=1;
}

int Find(int v){
  if(v==parent[v]) return v;
  //path compression
  return parent[v]=Find(parent[v]);
}

void Union(int a,int b){
    a=Find(a);
    b=Find(b);
    if(a!=b){
            //union by size
        if(size[a]<size[b])
            swap(a,b);
        parent[b]=a;
        size[a]+=size[b];
    }

}
void readInput(){

      freopen("kruskalInput.txt","r",stdin);
    cin >> nodes >> edges;

    for(int i=0;i<edges;i++){
        int u,v,w;
        cin >> u>>v>>w;
        E.push_back({w,{u,v}});
        }
}
void kruskal(){
    sort(E.begin(),E.end());
        for(int i=0;i<=nodes;i++){
            Make(i);
        }
        int total_cost=0;
        cout <<"Selected edges are:" <<endl;
        for(auto &E : E){
            int w=E.first;
            int u=E.second.first;
            int v=E.second.second;
            if(Find(u) == Find(v)) continue;
            Union(u,v);
            total_cost+=w;

            cout << u << " " << v<< endl;
    }
    cout << "Total cost is: " << total_cost << endl;
}
int main()
{
       readInput();
       kruskal();
    return 0;
}
