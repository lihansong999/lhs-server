IF NOT EXIST "exportcpp" MD "exportcpp"
IF NOT EXIST "exportcpp/protocol" MD "exportcpp/protocol"
protoc.exe protocol/*.proto -I=./protocol --cpp_out=./exportcpp/protocol
protoc.exe protocol/actor/*.proto -I=./protocol --cpp_out=./exportcpp/protocol
protoc.exe protocol/club/*.proto -I=./protocol --cpp_out=./exportcpp/protocol
PAUSE
