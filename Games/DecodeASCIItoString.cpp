#include <bits/stdc++.h> 
#include <algorithm> 
#include<iostream>
#include<conio.h>
#include<string>
#include<sstream>
using namespace std; 
  
// Function to print the character sequence 
// for the given ASCII sentence

//Drawback in this code is that, When typing we can't go back and correct any mistakes while typing the string
void asciiToSentence(string str, int len) 
{ 
    reverse(str.begin(), str.end()); //Decrypting the ASCII to it's original form
	cout<<"Decoded ASCII: "<<endl;
	cout<<str<<endl;
	
	int num = 0; 
	string ans="";
    for (int i = 0; i < len; i++) 
	{ 
        // Append the current digit 
        num = num * 10 + (str[i] - '0'); 
  
        // If num is within the required range 
        if (num >= 32 && num <= 122) { 
  
            // Convert num to char 
            char ch = (char)num; 
            //cout << ch; 
  			ans += ch;
            // Reset num to 0 
            num = 0; 
        } 
    } 
    cout<<"\nDecoded string: "<<endl;
    cout<<ans<<endl;
} 
string ASCIISentence(string s) 
{ 
    string e="";
	int l = s.length(); 
	//cout<<"L= "<<l<<endl;
    int convert;
    for (int i = 0; i < l; i++) { 
        convert = s[i];// - NULL; 
        //cout << convert;
		ostringstream strg;
		strg<<convert;
		e +=strg.str();
    }
    return e;
}   
// Driver code 
int main() 
{ 
    string s="";
	cout<<"Enter the sentence:\n";
    char ch;
	while((ch=getch())!='\r'){
		cout<<ch;
		s+=ch;
	}
    
	string str = ASCIISentence(s);
    cout<<"\nASCII form:\n"<<str;
	//string str = "8397105328697105981049711832789710510011732761111181011153210410511532861051001219732723277"; //Sai Vaibhav Naidu Loves his Vidya H M
    
	reverse(str.begin(), str.end()); //Encrypting the ASCII value by reversing it.
	cout<<"\nEncoded ASCII:\n"<<str<<endl;
	
	int len = str.length(); 
    asciiToSentence(str, len); 
  
    return 0; 
} 


/*
//Code in C#:
using System.IO;
using System;
using System.Collections.Generic;
class Program
{    
	static void asciiToSentence(String str, int len) 
    { 
        char[] decode = str.ToCharArray();  
        Array.Reverse(decode); 
        Console.WriteLine("Decoded ASCII value:");
        for(int i=0;i<decode.Length;i++)
            Console.Write(decode[i]);
        int num = 0; 
        string ans="";
        for (int i = 0; i < len; i++) { 
  
            // Append the current digit 
            num = num * 10 + (decode[i] - '0'); 
  
            // If num is within the required range 
            if (num >= 32 && num <= 122) { 
  
                // Convert num to char 
                char ch = (char)num; 
                //Console.Write(ch); 
                ans += ch;
                // Reset num to 0 
                num = 0; 
            } 
        } 
        Console.WriteLine("\n");
        Console.WriteLine("Decoded string value: ");
        Console.WriteLine(ans);
    } 
    public static void Main(string[] args){
        String str = "8397105328697105981049711832789710510011732761111181011153210410511532861051001219732723277"; 
        char[] encode = str.ToCharArray();  
        Array.Reverse(encode); 
        int len = encode.Length;
        String s=""; 
        for(int i=0;i<len;i++)
            s += encode[i];
        asciiToSentence(s, len); 
    }
}
*/
