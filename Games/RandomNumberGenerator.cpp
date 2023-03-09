#include<iostream>
#include<sstream> 
#include<string.h>
using namespace std;

int main(){
	double x = 0.3;
	double r=3.67;
	string s;
	int count=0;
	for(int i=1;i>=0;i++){
		if(count==10){
			cout<<s<<endl;
			s="";
			//count=0;
		}
		x = r*x*(1-x);
		int c = x*1000;
		stringstream ss;  
  		ss<<c;
		string u;  
  		ss>>u;  
		s +=u;
		count++;
		//cout<<i<<". "<<c<<endl;
		cout<<c;
	}
	return 0;
}
