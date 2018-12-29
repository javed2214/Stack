// Reverse a String using Stack
#include<bits/stdc++.h>
using namespace std;

int main(){
	stack <char> S;
	string str;
	int i=0;
	getline(cin, str);
	while(str[i]!='\0'){
		S.push(str[i]);
		i++;
	}
	while(!S.empty()){
		cout<<S.top();
		S.pop();
	}
	return 0;
}