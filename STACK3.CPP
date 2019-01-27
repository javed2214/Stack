// Program to Reverse Each Word of a String using Stack

#include<bits/stdc++.h>
using namespace std;

int main(){
	int i=0;
	stack <char> S;
	string str;
	getline(cin, str);
	while(str[i]!='\0'){
		if(str[i]!=' ')
			S.push(str[i]);
		else{
			while(!S.empty()){
				cout<<S.top();
				S.pop();
			}
			cout<<" ";
		}
		i++;
	}
	while(!S.empty()){
		cout<<S.top();
		S.pop();
	}

	return 0; 
}
