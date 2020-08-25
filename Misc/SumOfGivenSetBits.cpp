//Given n bit digit with 'set' number of bits set. Find the sum of all the digits with given 'set' bits set.
#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
#include <cstdlib>
#include <ctime>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

using namespace std;

int countSetBits(int n, int set){
	int count, sum=0;
	int N = pow(2,n);
	for(int i=0;i<N;i++){
		int a=i;
		count = 0;
		while(a){
			count += a & 1;
			a >>=1;
		}
		if(count==set){
			sum += i;
		}
	}
	return sum;
}
int main(){
	int n,set;
	int result;
	cin>>n>>set;
	result = countSetBits(n,set);
	cout<<"\n"<<result;
	return 0;	
}
