// Prefix to Infix Conversion
/*
Algorithm for Prefix to Infix:
Read String in reverse order
If operand, Push it into Stack
If the symbol is an operator, then pop two operands from the Stack
Create a string by concatenating the two operands and the operator between them.
string = (operand1 + operator + operand2)
And push the resultant string back to Stack
Repeat the above steps until end of Prefix expression.
*/
#include<bits/stdc++.h>
using namespace std;

int isOperator(string);

int main(){
	stack <string> S;
	string prefix, infix;
	cout<<"Enter Prefix Expression: ";
	cin>>prefix;
	int i=prefix.length()-1;
	while(i>=0){
		string ch(1,prefix[i]);  // char to string conversion
		if(isOperator(ch)){
			string s1,s2;
			s1=S.top();
			S.pop();
			s2=S.top();
			S.pop();
			infix="("+s1+ch+s2+")";
			S.push(infix);
		}
		else
			S.push(ch);
		i--;
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