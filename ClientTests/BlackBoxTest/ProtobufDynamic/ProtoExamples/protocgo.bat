IF NOT EXIST "exportgo" MD "exportgo"
protoc.exe protocol/*.proto -I=./protocol --go_out=./exportgo
protoc.exe protocol/actor/*.proto -I=./protocol --go_out=./exportgo
protoc.exe protocol/club/*.proto -I=./protocol --go_out=./exportgo
pause