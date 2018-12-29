// Prefix to Postfix Conversion

#include<bits/stdc++.h>
using namespace std;

int isOperator(string);

int main(){
	stack <string> S;
	string prefix, postfix;
	cout<<"Enter Prefix Expression: ";
	cin>>prefix;
	int i=prefix.length()-1;
	while(i>=0){
		string ch(1,prefix[i]);
		if(isOperator(ch)){
			string s1,s2;
			s1=S.top();
			S.pop();
			s2=S.top();
			S.pop();
			postfix=s1+s2+ch;
			S.push(postfix);
		}
		else
			S.push(ch);
		i--;
	}
	cout<<"Postfix: "<<S.top();
	return 0;
}
int isOperator(string ch){
	if(ch=="+"||ch=="-"||ch=="*"||ch=="/")
		return 1;
	else
		return 0;
}
