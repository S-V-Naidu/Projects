#Huffman decoding for the encoded scring based on the given codes
simp = []
ss=[]
res=[]
def decode(codes, encoded):
    test = ""
    for j in codes:
        simp.append(j.split("\t"))
    for i in range(len(simp)):
        for j in range(len(simp[i])):
            ss.append(simp[i][j])
    #print(ss)
    comp=""
    for i in range(len(encoded)):
        test = test +encoded[i]
        if test in ss:
            comp = comp + ss[ss.index(test)-1]
            test = ""
    #res.append(comp.split("\n"))
    return comp

if __name__ == '__main__':
    codes_count = int(raw_input().strip())
    codes=[]  
    for _ in range(codes_count):
        codes_item = raw_input()
        codes.append(codes_item)
    encoded = raw_input()
    ress = decode(codes,encoded)
    res = ress.split("\\n")
    for i in res:
        print(i)
        
        
