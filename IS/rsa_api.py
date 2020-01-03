import rsa

sender = input("Enter Sender's Name: ")
receiver = input("Enter Receiver's Name: ")

(sender_pub,sender_pri) = rsa.newkeys(512)
#print(sender_pub,sender_pri)
(receiver_pub,receiver_pri) = rsa.newkeys(512)
#print(receiver_pub,receiver_pri)

msg = input("message to be sent: ")
msg = msg.encode('utf8')

emsg = rsa.encrypt(msg,receiver_pub)

#print("Encrypted message: ", emsg)

retrived_msg = rsa.decrypt(emsg,receiver_pri)

print("\n\nmessage from",sender,": ",retrived_msg.decode('utf8'))