//Have to rotate a string with the given number of times.(Still incomplete)
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
void la(char* P,int X){
	int N = sizeof(P);
	if(X>N){
		cout<<P;
		exit(0);
	}
	string k;
	int count = 0;
	for(int i=0;i<N-1;i++){
		k[i] = P[i];
		count++;
	}
	cout<<count<<endl;
	while(X!=0){
		char temp = k[0];
		int i;
		for(i=0;i<N-2;i++)
			k[i] = k[i+1];
		k[i+1] = temp;
		X--;
	}
	for(int i=0;i<N;i++)
	cout<<k[i];
}
int main(){
	int n;
	cin>>n;
	char p[100];
	cin>>p;
	char *P = p;
	la(P,n);
	return 0;
}
