# -*- coding: utf-8 -*-
"""
Created on Fri Apr 17 19:33:43 2020

@author: saich
"""
def calculate(n1, n2):
    N1 = len(n1)
    N2 = len(n2)
    N = N1+N2
    A =['F','L','A','M','E','S']
    D ={'F':'Friends','L':'Lovers','A':'Affection','M':'Marriage','E':'Enemies','S':'Siblings'}
    a=[]
    b=[]
    for i in range(0,N1):
        k=n1[i]
        if k in a:
            N-=1
            continue
        c=0
        a.append(n1[i])
        for j in range(0,N2):
            if (n1[i]==n2[j]):
                if c==0:
                    N-=1
                    c+=1
                N-=1
            b.append(n2[j])
        if n1[i] not in b:
            a.remove(n1[i])
    #print(N)
    #N+=1
    predict(D,A,N)
             
def predict(D,A,N):
    B=[]
    if (N==len(A) or N%len(A)==0):
        n=len(A)
    else:
        n = N%(len(A))
    #print(n)
    #A.remove(A[N-1])
    if n==0:
        v=n+1
        b=n
    else:
        v=n
        b=n-1
    for i in range(len(A)):
        if v>len(A)-1:
            v=len(A)-v
        if v==b:
            break
        B.append(A[v])
        v+=1
    ##B.remove(B[c])
    #print(B)
    if(len(B)==2):
        n = N%2
        if n==1:
            print(D[B[1]])
        else:
            print(D[B[0]])
    else:
        predict(D,B,N)
    
    
n1 = raw_input("Enter your name: \n")
n2 = raw_input("Enter your crush's name: \n")
print('\nResult: ')
n1 = n1.upper()
n2 = n2.upper()
n1 = n1.replace(" ","")
n2 = n2.replace(" ","")
print(n1+" and "+n2+" are....")
calculate(n1,n2)
