// Infix to Postfix Conversion
#include<bits/stdc++.h>
using namespace std;

int checkPrecedence(char);
int checkOperator(char);

int main(){
	stack <char> S;
	int i=0;
	string str, post;
	cout<<"Enter Infix Expression: ";
	cin>>str;
	S.push('x');

	while(str[i]!='\0'){
		char ch=str[i];
		if(isalpha(ch))
			post+=ch;
		else if(ch=='(')
			S.push(ch);
		else if(ch==')'){
			while(S.top()!='x' && S.top()!='('){
				char c=S.top();
				post+=c;
				S.pop();
			}
			if(S.top()=='('){
				char c=S.top();
				S.pop();
			}
		}
		else{								// Operator
			while(S.top()!='x' && checkPrecedence(ch) <= checkPrecedence(S.top())){
				char c=S.top();
				S.pop();
				post+=c;
			}
			S.push(ch);
		}
		i++;
	}
	while(S.top()!='x'){
		char c=S.top();
		S.pop();
		post+=c;
	}
	cout<<post;
	return 0;
}
int checkPrecedence(char ch){
	if(ch=='*' || ch=='/')
		return 2;
	else if(ch=='+' || ch=='-')
		return 1;
	else
		return 0;
}
int checkOperator(char ch){
	if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
		return 1;
	else
		return 0;
}