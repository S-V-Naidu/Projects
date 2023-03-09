#find the occurance of the given item in the query
def solve(X, arr, query_values):
    x = []
    for i in range(len(query_values)):
        count = 0
        for j in range(len(arr)):
            if arr[j] == X:
                count+=1
            if count == query_values[i]:
                x.append(j+1)
                break
            elif j == (len(arr)-1):
                x.append(-1)
    return x

x = int(raw_input("Enter the item to be searched: "))
arr_count = int(raw_input("Enter the size of the array: "))
arr = []
for i in range(arr_count):
    arr.append(int(raw_input()))
#arr = raw_input().split()
query_count = int(raw_input("Enter the size of the array: "))
query_values = []
for i in range(query_count):
    query_values.append(int(raw_input()))
#queue_values = raw_input().split()

print(solve(x,arr,query_values))