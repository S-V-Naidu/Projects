#include <iostream>
#include<cstdlib>
#include<string>
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string S, int *i, int j) {
	int e=0;
	int t= *i;
up:	if(t<j){
		*i=t;
		for(int k = j; k >= *i; k--) {
			if(*i<=j){
				if(S[*i]==S[k]){
					e=1;
					*i++;
				}
				else{
					e=0;
					t++;
					goto up;	
				}
			}
		}
	}
	else{
		e=0;
	}
	if(e==1) {
		return true;
	} else {
		return false;
	}
}
void solve(string S, int n) {
	int a[n];
	int t=0;
	for(int i=0; i<n; i++) {
		if(isPalindrome(S,&t,i)) {
			a[i]=i-t+1;
		} else {
			a[i]=1;
		}
		t=0;
	}
	for(int i=0;i<n;i++)
		cout<<a[i]<<"\t";

}
int main() {
	string S;
	int n;
	cout<<"Enter a string: ";
	cin>>S;
	n = S.size();
	solve(S, n);
	return 0;
}
