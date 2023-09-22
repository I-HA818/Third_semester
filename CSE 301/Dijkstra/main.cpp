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
int extract_min(int *distance){
	int min =INT_MAX,in;
	for(int i=0;i<V;i++){
		if(min>=distance[i]&& visit[i] == false)
			{
				min=distance[i];
				in=i;
			}
	}
	return in;
}
void relax(int *distance,int *previ,int u , int v){
	if(distance[v]> distance[u]+graph[u][v]){
		distance[v]=distance[u]+graph[u][v];
		previ[v]=u;
	}
}
void dijkstra(int *distance,int *previ,int source){
	initialize(distance,previ,source);
	int n,u,v;
	while(n<V){
	u=extract_min(distance);
	visit[u]=true;
	for(int v=0;v<V;v++){
		if(graph[u][v]){
			relax(distance,previ,u,v);
		}
	}
    n++;
	}

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

	int distance[size],previ[size],source;
    freopen("dijkInput.txt","r",stdin);
    readInput();
    cin>>source;
    dijkstra(distance,previ,source);

    cout<<"Shortest path from Dhaka:"<<endl;
    for(int i=1;i<V;i++){
        printPath(previ,i);
         cout<<distance[i]<<endl;

    }
}
