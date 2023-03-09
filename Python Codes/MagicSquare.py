#program to check whether a given matrix is magic matrix or not Returns true if mat[][] is magic square, else returns false.
def isMagicSquare( mat) :
  n = len(mat)
  # sumd1 and sumd2 are the sum of the two diagonals
  sumd1=0
  sumd2=0
  for i in range(n):
    # (i, i) is the diagonal from top-left -> bottom-right
    # (i, n - i - 1) is the diagonal from top-right -> bottom-left
    sumd1+=mat[i][i]
    sumd2+=mat[i][n-i-1]
    # if the two diagonal sums are unequal then it is not a magic square
  if not(sumd1==sumd2):
    return False
  for i in range(n):
    #sumr is rowsum and sumc is colsum
    sumr=0
    sumc=0
    for j in range(n):
      sumr+=mat[i][j]
      sumc+=mat[j][i]
    if not(sumr==sumc==sumd1):
      return False
    #if all the conditions are satisfied then it is a magic square
  return True
     
'''
 8 3 4
 1 5 9     #an ideal magic square
 6 7 2
'''   
            
     
# Driver Code
mat = [ [ 2, 1, 8 ],
        [ 5, 3, 8 ],
        [ 9, 4, 6 ] ]
     
if (isMagicSquare(mat)) :
    print( "Magic Square")
else :
    print( "Not a magic Square")