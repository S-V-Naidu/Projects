
def selectStock(saving, currentvalue, futurevalue):
    y=[]
    for i in range(len(currentvalue)):
        c = futurevalue[i] - currentvalue[i]
        y.append(c)

    y = y.sort(reverse=True)
    print(type(y))
    print(y)
    sum=0
    if y is not None:
        for i in range(len(y)):
            if y[i]<=0:
                continue
            if(sum<saving and currentvalue[i]<=saving):
                sum += currentvalue[currentvalue.index(y[i])]
    
    return sum


saving = int(raw_input("Enter the savings:"))
length = int(raw_input("Enter the lenght:"))
print("Enter the current values: ")
currentvalue=[]
futurevalue=[]
i=length
while i!=0:
    currentvalue.append(int(raw_input()))
    i = i-1
    
print("Enter the future values: ")
i=length
while i!=0:
    futurevalue.append(int(raw_input()))
    i = i-1
    
print(selectStock(saving,currentvalue,futurevalue))