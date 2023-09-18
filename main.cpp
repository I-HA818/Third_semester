#include <iostream>
#include<string>
#define SIZE 100
#define V 5
#define INF 999
using namespace std;

int graph[SIZE][SIZE];
int d[SIZE][SIZE];
int p[SIZE][SIZE];
string places[V]={"Dhaka","Gazipur","Tangail","Narayanganj","Cumilla"};

void readInput(){
    int E,w,i,j,k;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            if(i==j) graph[i][j]=0;
            else graph[i][j]=INF;
        }
    }


   string s,d;
    freopen("floydInput.txt.txt","r",stdin);
    cin >> E;

    for(int i=0;i<E;i++){
        cin >> s >> d >> w ;
        for(j=0;j<V;j++){
            for(k=0;k<V;k++){
                if(s==places[j] && d==places[k]){
                    graph[j][k]=w;

                }
            }

        }
    }




}

void printGraph(){
    for(int i=0;i<V;i++){
        for(int j=0;j<V;j++){
            cout<< graph[i][j] << " ";
        }
        cout << endl;
  }
}
void FloydWarshall(){
    int i,j,k;
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            d[i][j]=graph[i][j];
            if(i==j || graph[i][j]==INF) p[i][j]=-1;
            else if(i!=j && graph[i][j]<INF) p[i][j]=i;
        }
    }
    for(k=0;k<V;k++){
        for(i=0;i<V;i++){
            for(j=0;j<V;j++){
                if(d[i][k]+d[k][j]<d[i][j] && (d[k][j]!=INF && d[i][k]!=INF)){
                   d[i][j]=d[i][k]+d[k][j];
                   p[i][j]=p[k][j];
                }
            }
        }
    }
}

void printPath(int s,int t){
    if(p[s][t]==-1) {
            cout << "No such path." ;
            return;
    }
    else if(p[s][t]==s){
        cout << places[s] << "->" ;
    }
    else {
        printPath(s,p[s][t]);
        printPath(p[s][t],t);
    }

}
int main()
{
    readInput();
    FloydWarshall();
    printGraph();
    cout << endl;

        for(int i=0;i<V;i++){
                cout<< "Source: "<< places[i]<< endl;
        for(int j=0;j<V;j++){
            printPath(i,j);
           if(j!=i) cout<< places[j];
            cout << endl;
        }
        cout<< endl;
}


    return 0;
}
