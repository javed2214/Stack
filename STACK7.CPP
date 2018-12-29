// Infix to Prefix Conversion
#include<bits/stdc++.h>
using namespace std;

int checkOperator(char);
int checkPrecedence(char);

int main(){
	stack <char> S;
	string infix,prefix;
	cout<<"Enter Infix Expression: ";
	cin>>infix;
	reverse(infix.begin(), infix.end());
	S.push('x');
	int i=0;
	while(infix[i]!='\0'){
		char ch=infix[i];
		if(isalpha(ch))
			prefix+=ch;
		else if(checkOperator(ch)){
			while(S.top()!='x' && checkPrecedence(ch)<=checkPrecedence(S.top())){
				char c=S.top();
				S.pop();
				prefix+=c;
			}
			S.push(ch);
		}
		else if(ch=='(')
			S.push(ch);
		else{
			while(S.top()!='x' && S.top()!='('){
				char c=S.top();
				prefix+=c;
				S.pop();
			}
			if(S.top()=='('){
				char c=S.top();
				S.pop();
			}
		}
		i++;
	}
	while(S.top()!='x'){
		char c=S.top();
		prefix+=c;
		S.pop();
	}
	reverse(prefix.begin(), prefix.end());
	cout<<prefix;

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
	if(ch=='+' || ch=='*' || ch=='/' || ch=='-')
		return 1;
	else
		return 0;
}