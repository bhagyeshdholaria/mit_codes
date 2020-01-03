
def validate(arr,row,col):
    for i in range(col):
        if arr[row][i]==1:
            return False
    
    for i,j in zip(range(row,-1,-1),
                   range(col,-1,-1)):
        if arr[i][j] == 1:
            return False
    
    for i,j in zip(range(row,4),range(col,-1,-1)):
        if arr[i][j] == 1:
            return False
    
    return True

def solve(arr,col):

    if col>=4:
        return True
    
    for i in range(4):
        if validate(arr,i,col):
            arr[i][col] = 1
            if solve(arr,col+1) == True:
                return True
            arr[i][col] = 0
    return False

def startsolve():
    arr = [[0 for _ in range(4)] for _ in range(4)]
    print(arr)
    
    if solve(arr, 0) == False: 
        print ("Solution does not exist") 
        return False
  
    for i in arr:
        print(i)
    return True

startsolve()
