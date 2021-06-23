# importing sockets 
import socket

#declaring port number and ipv4 address
PORT = 5050
SERVERIP = "192.168.43.171"
#creating a socket object with tcpip protocol
server = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
serverhost = (SERVERIP,PORT)

#trying to bind the server to the ip address and port number
try:
    server.bind(serverhost)
    print("server bind succesfully......")
except:
    print("binding failed")


#listening to all requests
print("now listening....")
server.listen()