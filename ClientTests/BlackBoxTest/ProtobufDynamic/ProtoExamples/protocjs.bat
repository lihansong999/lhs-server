IF NOT EXIST "exportjs" MD "exportjs"
IF NOT EXIST "exportjs/protocol" MD "exportjs/protocol"
protoc.exe protocol/*.proto -I=./protocol --js_out=import_style=commonjs,binary:./exportjs/protocol
protoc.exe protocol/actor/*.proto -I=./protocol --js_out=import_style=commonjs,binary:./exportjs/protocol
protoc.exe protocol/club/*.proto -I=./protocol --js_out=import_style=commonjs,binary:./exportjs/protocol
PAUSE