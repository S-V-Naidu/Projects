#Given matrix, make it a square matrix and return the largest sum of the reverse diagonals
def makeSqr(inp,m,n):
    if m>n:
        for i in range(n+1,m):
            for j in range(0,m):
                inp[j][i] = 0
    else:
        for i in range(m+1,n):
            for j in range(0,n):
                inp[i][j]=0
    return inp
   
def findMaxSum(S,m,n):
    if m != n:
        S = makeSqr(S,m,n)
    print(S)
   
#inp = [int(i) for i in input().split()][:n] #Taking input from user with a limit and space seperated
#s = list(map(int,input().split()))  #List input from user with space seperated
m = int(raw_input())
n = int(raw_input())
arr=[]
for i in range(0,m):
    arr[i] = [int(i) for i in input().split()][:n]
findMaxSum(arr,m,n)
