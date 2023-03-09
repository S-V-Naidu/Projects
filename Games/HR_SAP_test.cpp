//Finding starting index of 'x' in 's'(0 based indexing)
#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int firstOccurrence(string s, string x) {
    int a,count =0;
    int n,m;
    n = s.size();
    m = x.size();
    int j=0;
    for(int i=0;i<n;i++){
        if(count==m){
            break;
        }
        if(x[j]=='*'){
            if(count==0){
                a=i;
            }
            count++;
            j++;
            continue;
        }
        if(x[j]==s[i]){
            if(count==0){
                a=i;
            }
            count++;
            j++;
        }
        else{
            count=0;
            j=0;
        }
    }
    if(count != m){
        return -1;
    }
    else{
        return a;
    }
}

int main(){
	string s,x;
	cin>>s;
	cin>>x;
	int res = firstOccurrence(s,x);
	cout<<"\nResult: "<<res<<endl;
	return 0; 
}
