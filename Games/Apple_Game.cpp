//Apple Game.[Completed!!!!]
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<vector>

using namespace std;

int main(){
	int n,m;
	cout<<"Enter the size of basket 1:\n";
	cin>>n;
	int b[n];
	for(int i=0;i<n;i++)
		cin>>b[i];
	cout<<"Enter the size of basket 2:\n";
	cin>>m;
	int q[m];
	for(int i=0;i<m;i++)
		cin>>q[i];
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	int count=0,x;
	int a[n][100];
	int num=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<b[i];j++){
			a[i][j]=num;
			num++;
		}
	}
	int g=0;
	for(int k=0;k<m;k++){
		for(int i=0;i<n;i++){
			for(int j=0;j<b[i];j++){
				if(q[k]==a[i][j]){
					count += (i+1);
					g=1;
					break;
				}
			}
			if(g==1){
				g=0;
				break;
			}
		}
	}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////
	cout<<"\nAnswer is: "<<count<<endl;
	
	return 0;
}
