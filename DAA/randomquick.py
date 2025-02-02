import random
import time

t1 = time.time()
print("t1: ",t1)
start = int(round(time.time() * 1000))

def partition(arr,l,h):
    x = random.randint(l,h-1)
    print(x)
    pivot = arr[x]
    i=l
    j=h
    while i<j:
        while arr[i] < pivot:
            i += 1
            #print("i: ",i)
        while arr[j] > pivot:
            j -= 1
            #print("j: ",j)
        if i<j:
            arr[i],arr[j] = arr[j],arr[i]
            #print("i,j swapped")
            #print(arr)
        else:
            arr[j],pivot = pivot,arr[j]
            #print("pivot swapped")
            #print(arr)
    return j

def qsort(arr,l,h):
    #pivot = arr[l]
    if l<h:
        p = partition(arr,l,h)
        qsort(arr,l,p-1)
        qsort(arr,p+1,h)

#arr = [50,23,9,18,61,81,21,82]
# arr = [45,67,34,56,89,90,12,11,8,7,6,5,4,3,2,1]
arr = [1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 34, 45, 56, 67, 89, 90]

a = len(arr)
print("\nUnsorted:- ",arr)
qsort(arr,0,a-1)
print("\nSorted:- ",arr)
end = int(round(time.time() * 1000))
print("start time:",start)
print("end time:",end)
print("exe time(ms):",end-start)
