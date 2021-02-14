import math


def centroid_calc(centroids):
    #creating a list for "classes of centroid" c1,c2,c1,c1...
    class_centroid=[]
    for position in sample:
        class_assign=[]
        for centroid in centroids:      
            class_assign.append(math.sqrt((position[0]-centroid[0])**2+(position[1]-centroid[1])**2))
        class_centroid.append(class_assign.index(min(class_assign)))
    # print(class_centroid)

    #list of "new centroids" and it's "occurance or frequency" & setting to empty
    new_centroid = []
    centroid_occurance=[]
    for i in range(max(class_centroid)+1):
        new_centroid.append([0,0])
        centroid_occurance.append(0)
    # print(new_centroid)
    # print(centroid_occurance)

    #frequency counter
    for clas in class_centroid:
        centroid_occurance[clas] += 1

    
    for (clas,elem) in zip(class_centroid,sample):   
        new_centroid[clas][0] += elem[0]/centroid_occurance[clas]
        new_centroid[clas][1] += elem[1]/centroid_occurance[clas]

    return new_centroid


def load_data():
    return [[2,3],[5,6],[8,7],[1,4],[2,2],[6,7],[3,4],[8,6]]


num = int(input("Enter No. of cluster centroids : "))

sample = load_data()
centroids=[]

j=0
for j in range(num):
        centroids.append(sample[j])


#Creating empty list of "centroids"
while 1:
    
    new_centroid = centroid_calc(centroids)
    # print(new_centroid,"\n")

    if new_centroid == centroids:
        break
    centroids = new_centroid

print(new_centroid)