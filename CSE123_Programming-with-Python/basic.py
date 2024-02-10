# variables and constants
number = 3
string = "Hello, World!"
f_string = f"Hello, World! {number}"
boolean = True
none = None

# type conversion
number_string = str(number)
number_integer = int(number)
number_float = float(number)
number_boolean = bool(number)

# conditional statements
if number == 3:
    print("number is 3")
else: 
    print("number is not 3")

# loops
for i in range(5):
    print(i)

while number < 10:
    print(number)
    number += 1

# functions
def add(a, b):
    return a + b
print(add(3, 4))

# encryption and decryption of a string
# encrypts a string by adding 1 to the ASCII value of each character in the string
def encrypt(string):
    encrypted = ""
    for char in string:
        encrypted += chr(ord(char) + 1)
    return encrypted

def decrypt(string):
    decrypted = ""
    for char in string:
        decrypted += chr(ord(char) - 1)
    return decrypted

encrypted = encrypt("Hello, World!")
print(encrypted)
print(decrypt(encrypted))