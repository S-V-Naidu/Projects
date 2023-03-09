#include<bits/stdc++.h>
#include<string.h>
#include<iostream>
#include<conio.h>
#include<vector>

using namespace std;

vector<string> findBooks(vector<string> bookName, vector<string> importantWords, vector<string> initial, int threshold,int N) {

    vector<string> ans;
    int count=0,x=0;
    int g, G = initial.size();
    for(int i=0;i<N;i++){
    	for(int j=0;j<N;j++){
    		string H = importantWords[i][j];
    		for(int k=0;k<G;k++){
    			string I = initial[k];
    			if(strcmp(H,I)){
    				count++;
    				break;
				}
			}
			if(count>=2){
    			ans[x]=bookName[i];
    			x++;
    			for(g=0;g<N;g++){
    				initial[G+g]= importantWords[i][g];
				}
				G += g;	
			}
		}
	}
    return ans;
}

void runTest() {

    //vector<string> bookName = {"book1", "book2", "book3"};
    vector<string> bookName;
    cout<<"\nEnter the book names:\n";
    for(int i=0;i<10;i++)
    	cin>>bookName[i];
    int N = bookName.size();
	//vector<string> importantWords = {"malfroy snape voldemort hagrid", "harry snape azkaban hagrid", "iron_man hulk captain_america"};
    vector<string> importantWords;
    cout<<"\nEnter the important words of each books:\n";
    for(int i=0;i<N;i++){
    	while(getch()!='\r')
    		for(int j=0;j<N;j++){
				cin>>importantWords[i][j];
			}
	}
	//vector<string> initial = {"harry", "azkaban"};
    vector<string> initial;
    cout<<"\nEnter the initial dictonary:\n";
    for(int i=0;i<N;i++)
    	while(getch()!='\r')
    		cin>>initial[i];
	int threshold;
	cout<<"\nEnter the threshold:\n";
	cin>>threshold;

    //vector<string> expected = {"book1", "book2"};
    //vector<string> actual = findBooks(bookName, importantWords, initial, threshold);
    vector<string> result = findBooks(bookName,importantWords,initial,threshold,N);
	for(int j=0;j<result.size();j++)
		cout<<result[j];
}

int main()
{
    runTest();
}
