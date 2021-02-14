import time

t1 = time.time()
print("t1: ",t1)
start = int(round(time.time() * 1000))

def partition(arr,l,h):
    pivot = arr[l]
    i = l+1
    j = h
    while 1:
        while i <= j and arr[i] <= pivot:
            i += 1

        while i <= j and arr[j] >= pivot:
            j -= 1

        if i <= j:
            arr[i], arr[j] = arr[j], arr[i]
        else:
            break

    arr[l], arr[j] = arr[j], arr[l]
    return j

def qsort(arr,l,h):
    if l >= h:
        return
    p = partition(arr,l,h)
    qsort(arr, l, p-1)
    qsort(arr, p+1, h)

# arr = [50,23,9,18,61,81,21,82]
# arr = [45,67,34,56,89,90,12,11,8,7,6,5,4,3,2,1]
# arr = [1, 2, 3, 4, 5, 6, 7, 8, 11, 12, 34, 45, 56, 67, 89, 90]
arr = [29,99,27,41,66,28,44,78,87,19,31,76,58,88,83,97,12,21,44]

a = len(arr)
print("\nUnsorted:- ",arr)
qsort(arr,0,a-1)
print("\nSorted:- ",arr)

end = int(round(time.time() * 1000))
print("start time:",start)
print("end time:",end)
print("exe time(ms):",end-start)