def ksp(warr,parr,m):
    pw=[]
    final=[0]*len(warr)
    p=0

    for i in range(len(warr)):    #n      
        pw.append(parr[i]/warr[i])#n     

    while m!=0:#n
        k = pw.index(max(pw))
        if warr[k] <= m:
            m -= warr[k]
            final[k] = 1
            p += parr[k]
            pw[k] = -1
        
        else:
            final[k] = m / warr[k]
            p += m*pw[k]
            m = 0
            pw[k] = -1

    print("\nmax profit:",p)
    print("Elements Selection:",final)


while 1:
    try:
        warr = list(map(int,input("Enter weights seperated by a space:").split()))
        parr = list(map(int,input("Enter Profits seperated by a space:").split()))
        if len(warr) != len(parr):
            print("\n***Enter equal no of profits and weights***\n")
            continue
        m= int(input("Enter knapsack capacity:"))
    except:
        print("\n***Enter valid values***\n")
        continue

    ksp(warr,parr,m)