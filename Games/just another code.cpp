#include<iostream>
using namespace std;
int main(){
	int a[500][500];
	for(int i=0;i<200;i++)
		for(int j=0;j<200;j++)
			a[i][j]=1;
	cout<<&a;
	return 0;
}
