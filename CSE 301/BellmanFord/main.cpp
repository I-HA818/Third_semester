#include<iostream>
using namespace std;
#define size 100
int graph[size][size];
string name[size];
bool visit[size];
int V=0;

void readInput()
{
    int E,w;
    string s,d;
    cin >> V;
    for(int i=0;i<V;i++)
        cin >> name[i] ;

        cin >> E;
        for(int i=0;i<E;i++){
            cin>> s >> d >> w;
            for(int j=0;j<V;j++){
                for(int k=0;k<V;k++){
                    if(s==name[j] && d==name[k]){
                        graph[j][k]=w;
                    }
                }
            }
        }

}
void initialize(int *distance, int *previ,int source){
	for(int i=0;i<V;i++){
		distance[i]=INT_MAX;
		previ[i]=-1;
		visit[i]=false;
	}
	distance[source]=0;
}

void relax(int *distance,int *previ,int u , int v){
	if(distance[v]> distance[u]+graph[u][v]){
		distance[v]=distance[u]+graph[u][v];
		previ[v]=u;
	}
}
bool bellman(int *distance,int *previ,int source){
	initialize(distance,previ,source);
	int n,u,v;
	for(int i=0;i<V-1;i++){
        visit[u]=true;
        for(u=0;u<V;u++)
	for(int v=0;v<V;v++){
		if(graph[u][v]){
			relax(distance,previ,u,v);
		}
	}
	}
	for(u=0;u<V;u++)
	for(int v=0;v<V;v++){
        if(graph[u][v]){
           if(distance[v]>distance[u]+graph[u][v]) return false;
           }
	}

    return true;
}

void printPath(int *previ,int node){
    if(previ[node]==-1){
        cout<<name[node]<<" ->";
        return;
    }
    printPath(previ,previ[node]);
    cout<<name[node]<<" ->";
}


int main(){

    bool ans;
	int distance[size],previ[size],source;
    freopen("BellmanInput.txt","r",stdin);
    readInput();
    cin>>source;
    ans=bellman(distance,previ,source);
    if(ans==true) cout << "No negetive cycle" << endl;
    else  cout<< "Negetive cycle present "<<endl;

    cout<<"Shortest path from "<< name[source]<<endl;
    for(int i=1;i<V;i++){
        printPath(previ,i);
         cout<<distance[i]<<endl;

    }
}
