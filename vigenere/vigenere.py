# Tạo key dựa trên len của key và len của mess
def generateKey(string, key):
	key = list(key)
	if len(string) == len(key):
		return(key)
	else:
		for i in range(len(string) -
					len(key)):
			key.append(key[i % len(key)])
	return("" . join(key))
	
# Trả về văn bản đã được mã hóa
def cipherText(string, key):
	cipher_text = []
	for i in range(len(string)):
		x = (ord(string[i]) +
			ord(key[i])) % 26
		x += ord('A')
		cipher_text.append(chr(x))
	return("" . join(cipher_text))
	
# Giải mã văn bản đã được mã hóa
def originalText(cipher_text, key):
	orig_text = []
	for i in range(len(cipher_text)):
		x = (ord(cipher_text[i]) -
			ord(key[i]) + 26) % 26
		x += ord('A')
		orig_text.append(chr(x))
	return("" . join(orig_text))
	

if __name__ == "__main__":
	#Mã hóa
    string = input("Nhập văn bản:")
    keyword = input("Nhập khóa:")
    key = generateKey(string, keyword)
    cipher_text = cipherText(string,key)
    print("Văn bản đã được mã hóa :", cipher_text)
    print("----------------------")
    #Giải mã
    cipher_text = input("Nhập văn bản đã được mã hóa:")
    keyword = input("Nhập khóa:")
    key = generateKey(string, keyword)
    print("Văn bản gốc:",originalText(cipher_text, key))

