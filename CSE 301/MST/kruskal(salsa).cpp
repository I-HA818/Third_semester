#include<bits/stdc++.h>
using namespace std;

int numOfedges,vertex;
vector<string> vertexNames;
vector<pair<int,pair<string,string>>> edges;
vector<pair<int,pair<string,string>>> mst;

void readInput(){
	freopen("inputKruskal.txt","r",stdin);
        cin >> numOfedges;
        string s,d;
        int w; 
        for(int i=0;i<numOfedges;i++){
        	cin >> s >> d >> w;
        	if(find(vertexNames.begin(),vertexNames.end(),s)==vertexNames.end())
        		vertexNames.push_back(s);
        	if(find(vertexNames.begin(),vertexNames.end(),d)==vertexNames.end())
        		vertexNames.push_back(d);
        	edges.push_back(make_pair(w,make_pair(s,d)));
        }
        sort(edges.begin(),edges.end());
        
        for(int i=0;i<edges.size();i++)
        	cout << edges[i].first <<" "<<edges[i].second.first<<" "<<edges[i].second.second<<endl;
       
        
        vertex=vertexNames.size();
        //for(int i=0;i<vertexNames.size();i++)
        //	cout << vertexNames[i]<<endl;
			
}
vector<set<string>> nodes;
void make_Set(){
	
	for(int i=0;i<vertexNames.size();i++){
		set<string> verTEX;
		verTEX.insert(vertexNames.at(i));
		nodes.push_back(verTEX);	
	}
	/*for(int i=0;i<nodes.size();i++){
		for(auto x:nodes[i])
			cout << x<<" ";
		cout <<endl;	
	}*/
}
void kruskal(){
	int totalWeight=0;
	make_Set();
	for(int i=0;i<edges.size();i++){
		string u=edges[i].second.first;
		string v=edges[i].second.second;
		int j,k;
		for(j=0;j<nodes.size();j++)
			if(nodes[j].find(u)!=nodes[j].end()){
				break;
			}
		for(k=0;k<nodes.size();k++)
			if(nodes[k].find(v)!=nodes[k].end())
				break;
		if(j!=k){
			nodes[j].insert(nodes[k].begin(),nodes[k].end());
			nodes.erase(nodes.begin()+k);
			mst.push_back(edges[i]);
			totalWeight+=edges[i].first;
		}	
		
	}
	cout <<"Total="<<totalWeight<<endl;
}

int main(){
	readInput();
	kruskal();
	cout <<"MST:"<<endl;
	for(int i=0;i<mst.size();i++)
        	cout <<mst[i].second.first<<" "<<mst[i].second.second<<" "<< mst[i].first <<endl;
	return 0;
}

