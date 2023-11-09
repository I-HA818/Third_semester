#include <iostream>
#include <cstring>
#include<vector>
#include <bits/stdc++.h>
using namespace std;
vector<string> output;
bool isOK(string input){
for(int i=0;i<input.size();i++){
	if(input[i]!='0' && input[i]!='1') return false;
}
	return true;
}
bool isPalindrome(string& str) {
    int left = 0;
    int right = str.length() - 1;

    while (left < right) {
        while (left < right && !isalnum(str[left])) {
            left++;
        }
        while (left < right && !isalnum(str[right])) {
            right--;
        }
        if (tolower(str[left]) != tolower(str[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

void CFG(string input){
    int len=input.size();
    string prev;
    string temp;
    string str;
   for(int i=0;i<len/2;i++){
    if(i==0){
    if(input[i]=='0') output.push_back("0P0");
    else  output.push_back("1P1");
    prev=input[i];
    str=prev;
    }

    else {
        reverse(str.begin(), str.end());
        if(input[i]=='0') {
                temp=prev+"0P0"+str;
                output.push_back(temp);
        }
    else  {
        temp=prev+"1P1"+str;
            output.push_back(temp);
    }
     prev+=input[i];
     str=prev;
    }
   }
}
int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    bool ans= isPalindrome(input);
    bool OK=isOK(input);
    if(ans && OK) {
            CFG(input);
             cout<<"P =>";
            for (auto it = output.begin(); it != output.end(); ++it){
                cout<<*it<<" =>";
            }
            cout<<input;
    }
    else cout << "NOT IN THE GRAMMAR";
    return 0;
}
