# n = 4

# def is_safe(result, row, col):
#     global n
#     if 1 in result[row] or 1 in map(lambda x: x[col], result[:row]) or \
#             1 in map(lambda x: result[x[0]][x[1]], zip(range(row - 1, -1, -1), range(col - 1, -1, -1))) or \
#             1 in map(lambda x: result[x[0]][x[1]], zip(range(row - 1, -1, -1), range(col + 1, n))):
#         return False
#     return True

# def _solve(row, result):
#     global n
#     for col in range(n):
#         if is_safe(result, row, col):
#             result[row][col] = 1
#             if row + 1 < n:
#                 if _solve(row + 1, result):
#                     return True
#                 result[row][col] = 0
#             else:
#                 return True
#     return False

# def solve(result):
#     _solve(0, result)
#     return result

# if __name__ == '__main__':
#     n = int(input("Enter number of queens : "))
#     res = [[0 for _ in range(n)] for _ in range(n)]
#     print(*solve(res), sep='\n')


global N 
N = 4
  
def printSolution(board): 
    for i in range(N): 
        for j in range(N): 
            print (board[i][j], end = " ") 
        print() 

def isSafe(board, row, col): 
  
    # Check this row on left side 
    for i in range(col): 
        if board[row][i] == 1: 
            return False
  
    # Check upper diagonal on left side 
    for i, j in zip(range(row, -1, -1),  
                    range(col, -1, -1)): 
        if board[i][j] == 1: 
            return False
  
    # Check lower diagonal on left side 
    for i, j in zip(range(row, N, 1),  
                    range(col, -1, -1)): 
        if board[i][j] == 1: 
            return False
  
    return True
  
def solveNQUtil(board, col): 
      
    if col >= N: 
        return True

    for i in range(N): 
  
        if isSafe(board, i, col): 
            board[i][col] = 1

            if solveNQUtil(board, col + 1) == True: 
                return True

            board[i][col] = 0
  
    return False
 
def solveNQ(): 
    board = [ [0, 0, 0, 0], 
              [0, 0, 0, 0], 
              [0, 0, 0, 0], 
              [0, 0, 0, 0] ] 
  
    if solveNQUtil(board, 0) == False: 
        print ("Solution does not exist") 
        return False
  
    printSolution(board) 
    return True
  
# Driver Code 
solveNQ() 