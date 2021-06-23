# libraray to make the user interface
from tkinter import *
# librarey to conncet to sockets
import socket
import threading

def buildconncetion():
    port = 5050
    serverip = socket.gethostbyname(socket.gethostname())
    addr = (serverip,port)
    client = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    client.connect(addr)


def sendPackets(packets):
    pass


def userinterface():
    # main user inter face to send packets 
    window = Tk()
    window.geometry("500x500")
    pakettext = Label(window,text = "message to send")
    pakettext.place(relx = 0.2, rely= 0.2)
    # to take to number of packets to send
    paketnumber = Entry(window)
    paketnumber.place(relx=0.5, rely=0.2)
    window.mainloop()



if __name__ == "__main__":

    buildconncetion()
    # userinterface()