import string
import random
import copy

alpha_ori = list(string.ascii_letters)
print(alpha_ori)
alpha_ci = copy.copy(alpha_ori)
random.shuffle(alpha_ci)
print(alpha_ci)
chara = list(string.punctuation)
while(1):
    ch = int(input("1. Encrypt\n2. Decrypt\n"))
    msg = ""
    emsg = ""
    if(ch == 1):
        msg = input("Enter Message: ")
        for char in msg:
            if(char == " "):
                emsg += " "
            if(char in chara):
                emsg += ""
            for j in range(len(alpha_ori)):
                if(char == alpha_ori[j]):
                    emsg += str(alpha_ci[j])
        print("Encoded message: ",emsg)

    elif(ch == 2):
        emsg = input("\nEnter encrypted message: ")
        for char in emsg:
            if(char == " "):
                msg += " "
            for j in range(len(alpha_ci)):
                if(char == alpha_ci[j]):
                    msg += str(alpha_ori[j])
        print("Decoded message:",msg)
    else:
        print("Enter valid input")
