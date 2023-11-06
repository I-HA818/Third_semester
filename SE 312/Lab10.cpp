#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> Leftmost(string input,int mid){
	vector<string> transitions;
	string curr = "S";
	transitions.push_back(curr);
	if(curr=="S"){
		transitions.push_back("A1B");
              	curr = "A1B";
	}
	if(curr =="A1B"){
		for(int i=0;i<mid;i++){
		         transitions.push_back("0"+transitions.back());
		}
		curr=transitions.back();		
		curr.erase(curr.begin()+curr.find("A"));
		transitions.push_back(curr);
		
		curr.erase(curr.begin()+curr.find("B"));
		
		for(int i=mid+1;i<input.size();i++){
		         if(input[i]=='0'){
		         	transitions.push_back(curr+"0B");
				curr+="0";
			 }
			 else if(input[i]=='1'){
		         	transitions.push_back(curr+"1B");
				curr+="1";
			 }	
		}
		curr=transitions.back();		
		curr.erase(curr.begin()+curr.find("B"));
		transitions.push_back(curr);	
	}
	
	
	return transitions;
}

vector<string> Rightmost(string input,int mid){
	vector<string> transitions;
	string curr = "S";
	transitions.push_back(curr);
	if(curr=="S"){
		transitions.push_back("A1B");
              	curr = "A1B";
	}
	if(curr =="A1B"){
		curr="A1";
		for(int i=mid+1;i<input.size();i++){
			if(input[i]=='0'){
		         	transitions.push_back(curr+"0B");
				curr+="0";
			 }
			 else if(input[i]=='1'){
		         	transitions.push_back(curr+"1B");
				curr+="1";
			 }
		
		}
		         
		curr=transitions.back();		
		curr.erase(curr.begin()+curr.find("B"));
		transitions.push_back(curr);
		
		
		for(int i=0;i<mid;i++){
		         transitions.push_back("0"+curr);
			 curr=transitions.back();	
		}
		curr=transitions.back();		
		curr.erase(curr.begin()+curr.find("A"));
		transitions.push_back(curr);	
	}
	
	
	return transitions;
}
int main(){
	
	string input;
	cout <<"Enter a string=";
	cin >> input;
	int search=input.find("1");
	
	vector<string> left = Leftmost(input,search);
    	vector<string> right = Rightmost(input,search);
	
	cout << "Leftmost Derivation: ";
        for (int i=0;i<left.size();i++)
           if(i!=left.size()-1) cout << left.at(i) << " => ";
		else cout << left.at(i);
	cout << "\nRightmost Derivation: ";
        for (int j=0;j<right.size();j++)
           if(j!=right.size()-1) cout << right.at(j) << " => ";
		else cout << right.at(j);
	
	return 0;
}
