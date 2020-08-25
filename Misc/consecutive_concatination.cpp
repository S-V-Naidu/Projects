//Have to arrange 2 arrays into one array where the consecutive elements are not from the same array.
#include<iostream>
#include<conio.h>
#include<string.h>
using namespace std;
int main(){
	int M,N,i,n;
	cin>>M;
	int A[M];
	for(int k=0;k<M;k++)
		cin>>A[k];
	cin>>N;
	int B[N];
	for(int j=0;j<N;j++)
		cin>>B[j];
	int C[M+N];
	if(M==N){
		for(i=0,n=0;i<M+N;i++,n++){
			C[i]=A[n];
			i++;
			C[i]=B[n];
		}
		cout<<"\n";
		cout<<M<<" "<<N<<endl;
		for(int i=0;i<M+N;i++)
			cout<<C[i]<<" ";
	}
	else{
		if(M>N){
			for(i=0,n=0;n<N;i++,n++){
			C[i]=A[n];
			i++;
			C[i]=B[n];
			}
			C[i]=A[n];
			cout<<"\n";
			cout<<N+1<<" "<<N<<endl;
			for(int i=0;i<2*N+1;i++)
				cout<<C[i]<<" ";	
		}
		else{
			for(i=0,n=0;n<M;i++,n++){
			C[i]=B[n];			
			i++;
			C[i]=A[n];
			}
			C[i]=B[n];			
			cout<<"\n";
			cout<<M<<" "<<M+1<<endl;
			for(int i=0;i<2*M+1;i++)
				cout<<C[i]<<" ";	
		}
	}
	return 0;
}
