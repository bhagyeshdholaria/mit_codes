import random
import sys
sys.setrecursionlimit(10**5)

def gcd(a,b):
    if(a==0 or b==0):
        return 0
    if(a==b):
        return a
    if(a > b):
        return gcd(a-b,b)
    return gcd(a,b-a)

def coprime(a,b):
    if(gcd(a,b)==1):
        return 1
    else:
        return 0

def modinverse(a,m):
    a = a%m
    for i in range(1,m):
        if((a*i)%m == 1):
            return i
    return 1

print("Enter your prime numbers between 1 and 100")
prime1= int(input("Enter 1st prime number:"))
prime2= int(input("Enter 2nd prime number:"))

e_values=[]
emsg=""
rev_msg=""
e=0
d=0

n = prime1*prime2
phi_n = (prime1-1)*(prime2-1)
print("phim_n:",phi_n)

for i in range(phi_n):
    if(coprime(i,phi_n)==1):
        e_values.append(i)

while e==d:
    e = random.choice(e_values) 
    d = modinverse(e,phi_n)

pub_key = [n,e]
pri_key = [n,d]
print("Public key:",pub_key,"\nPrivate key:",pri_key)
#print(e_values)
msg = input("Enter message:")

for j in msg:
    #print(ord(j))
    ja = ord(j)
    c = "%0d"%(((ja**e)%n) % 26)
    print(c)
    if c==0:
        c= str(26)
    emsg +=c


print("encrypted message: ",emsg)

for k in range(0,len(emsg)-1,2):
    
    de = int(emsg[k:k+2])
    ch = chr(96+ (((de**d)%n)%26))
    if ch==0:
        ch = chr(96+26)
    rev_msg += ch

print("decrypted message: ",rev_msg)


