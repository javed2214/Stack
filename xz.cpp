
/*---------------------------
    Author : Javed Ansari
    Date   : 18 May 2019    
-----------------------------*/

// https://codeforces.com/problemset/problem/723/B

#include<bits/stdc++.h>
#include<cstring>
#include<stdio.h>
using namespace std;
#define MOD1 1000000007
#define MOD2 1000000009
#define DB(x) cout<<#x<<"="<<x<<"\n";
#define DB2(x,y) cout<<#x<<"="<<x<<"  "<<#y<<"="<<y<<"\n";
#define FASTREAD ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define SORT(a) sort(a.begin(),a.end())
#define TEST(t) ll t; cin>>t; while(t--)
#define PI 2*acos(0.0)
#define endl cout<<"\n";
#define SS cout<<"*";
#define REPLACE(str,start,count,new_str) str.replace(start,count,new_str)
#define COUNT(str,ch) count(str.begin(),str.end(),ch)
#define ERASE(str,index) str.erase(str.begin()+index)
#define MAXA(a,n) *max_element(a,a+n)
#define MINA(a,n) *min_element(a,a+n)
#define REV(v) reverse(v.begin(),v.end())
#define SUM(v) accumulate(v.begin(),v.end(),0)
#define MAXV(v) *max_element(v.begin(),v.end())
#define MINV(v) *min_element(v.begin(),v.end())
#define ll long long int
#define ld long double
#define SIZE 100000001
#define INF 0x7fffffff


void SOLVE_QUESTION(){	

	ll n,p;
	cin>>n;
	string str,s,s2;
	cin>>str;
	ll mx=0,flag=0;

	stack <string> S1,S2;

	for(int i=0;i<str.length();i++){
		char ch=str[i];
		if(isalpha(ch) and flag==0)
			s+=ch;
		else if(ch=='_' and flag==0){
			if(s.length()>0)
				S1.push(s);
			s.clear();
		}
		else if(ch=='('){
			if(s.length()>0)
				S1.push(s);
			s.clear();
			flag=1;
		}
		else if(ch==')'){
			flag=0;
			if(s2.length()>0)
				S2.push(s2);
			s2.clear();
		}
		else if(flag==1 and isalpha(ch)) s2+=ch;
		else if(flag==1 and ch=='_'){
			if(s2.length()>0)
				S2.push(s2);
			s2.clear();
		}
	}
	if(s.length()>0) S1.push(s);

	while(!S1.empty()){
		s=S1.top();
		// DB(s)
		S1.pop();
		p=s.length();
		mx=max(mx,p);
	}
	cout<<mx<<" "<<S2.size();

	return;
}


int main(void){

	FASTREAD;
	SOLVE_QUESTION();

	return 0;
}