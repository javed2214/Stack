// Postfix to Infix Conversion
#include<bits/stdc++.h>
using namespace std;

int isOperator(string);

int main(){
	stack <string> S;
	string postfix, infix;
	cout<<"Enter Postfix Expression: ";
	cin>>postfix;
	int i=0;
	while(postfix[i]!='\0'){
		string ch(1,postfix[i]);
		if(isOperator(ch)){
			string s1,s2;
			s1=S.top();
			S.pop();
			s2=S.top();
			S.pop();
			infix="("+s2+ch+s1+")";
			S.push(infix);
		}
		else
			S.push(ch);
		i++;
	}
	cout<<S.top();
	return 0;
}
int isOperator(string ch){
	if(ch=="+" || ch=="-" || ch=="*" || ch=="/")
		return 1;
	else
		return 0;
}