def abc(arr, len):
    count = 0
    for i in range(len):
        if arr[i] % 2 != 0:
            if i != len - 1:
                count += 1
                if count > 1:
                    arr[i] = -1

                print("odd", arr)

            if i == len - 1 and count > 1:
                arr.remove(arr[i])
                arr.append(count + 1)

        elif arr[i] % 2 == 0:
            if count == 1:
                # arr.remove(-1)
                # arr.insert((i-1),1)
                count = 0

            if count > 1:
                arr[i - 1] = count
                print("even", arr)
                count = 0
    print(arr)

    while -1 in arr:
        arr.remove(-1)

    print(arr)


arr = []
while 1:
    a = int(input())
    if a >= 0:
        arr.append(a)
    else:
        break
print(len(arr))
abc(arr, len(arr))
