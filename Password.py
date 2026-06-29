import random
import string

print("=" * 40)
print("PASSWORD GENERATOR")
print("=" * 40)

length = int(input("Enter password length: "))

characters = string.ascii_letters + string.digits + string.punctuation

password = ""

for i in range(length):
    password += random.choice(characters)

print("\nGenerated Password:")
print(password)

strength = 0

if any(c.islower() for c in password):
    strength += 1

if any(c.isupper() for c in password):
    strength += 1

if any(c.isdigit() for c in password):
    strength += 1

if any(c in string.punctuation for c in password):
    strength += 1

if length >= 12:
    strength += 1

print()

if strength == 5:
    print("Strength : Very Strong")

elif strength >= 4:
    print("Strength : Strong")

elif strength >= 3:
    print("Strength : Medium")

else:
    print("Strength : Weak")