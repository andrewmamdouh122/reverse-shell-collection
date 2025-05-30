# x64
GOOS=windows GOARCH=amd64 go build -o reversex64.exe reverse.go

# x86
GOOS=windows GOARCH=386 go build -o reversex86.exe reverse.go

