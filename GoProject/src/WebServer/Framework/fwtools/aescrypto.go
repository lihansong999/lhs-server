package fwtools

import (
	"bytes"
	"crypto/aes"
	"crypto/cipher"
)

func pkcs5Padding(data *[]byte, blockSize int) {
	padding := blockSize - len(*data)%blockSize
	padText := bytes.Repeat([]byte{byte(padding)}, padding)
	*data = append(*data, padText...)
}

func pkcs5Trimming(data *[]byte) {
	padding := (*data)[len(*data)-1]
	*data = (*data)[:len((*data))-int(padding)]
}

// AESEncrypt AES加密 cbc模式 pkcs5padding
func AESEncrypt(key []byte, iv []byte, data *[]byte) error {
	block, err := aes.NewCipher(key)
	if err != nil {
		return err
	}
	pkcs5Padding(data, block.BlockSize())
	blockMode := cipher.NewCBCEncrypter(block, iv)
	blockMode.CryptBlocks(*data, *data)
	return nil
}

// AESDecrypt AES解密 cbc模式 pkcs5padding
func AESDecrypt(key []byte, iv []byte, data *[]byte) error {
	block, err := aes.NewCipher(key)
	if err != nil {
		return err
	}
	blockMode := cipher.NewCBCDecrypter(block, iv)
	blockMode.CryptBlocks(*data, *data)
	pkcs5Trimming(data)
	return nil
}
