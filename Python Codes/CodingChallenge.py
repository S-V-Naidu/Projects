#Segregate all even values in one side and odd values in the end
def segregateEvenOdd(arr):
    left,right = 0,len(arr)-1
    while left < right:
        while (arr[left]%2==0 and left < right):
            left += 1
 
        while (arr[right]%2 == 1 and left < right):
            right -= 1
 
        if (left < right):
              arr[left],arr[right] = arr[right],arr[left]
              left += 1
              right = right-1
 
 
# Driver function to test above function
arr = [73, 4, 63, 23, 65]
segregateEvenOdd(arr)
print ("Array after segregation "),
for i in range(0,len(arr)):
    print arr[i],