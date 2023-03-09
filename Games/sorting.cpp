#include <iostream>
#include<bits/stdc++.h>
#include <math.h>
#include<string.h>
using namespace std;
int main(){
	unsigned long int a[10];
	int i;
	a[0]=1;
	a[1]=1;
	for(i=2;i<10;i++){
		a[i]=a[i-1]+a[i-2];
	}
	for(i=0;i<10;i++){
		cout<<endl<<a[i];
	}
   	return 0;
}
