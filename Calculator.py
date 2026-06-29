import math

print("=" * 40)
print("      ADVANCED CALCULATOR")
print("=" * 40)

while True:

    print("\nChoose Operation")
    print("1. Addition")
    print("2. Subtraction")
    print("3. Multiplication")
    print("4. Division")
    print("5. Power")
    print("6. Square Root")
    print("7. Modulus")
    print("8. Floor Division")
    print("9. Percentage")
    print("10. Exit")

    choice = input("Enter choice: ")

    if choice == "10":
        print("Thank You!")
        break

    if choice == "6":
        num = float(input("Enter number: "))
        print("Answer =", math.sqrt(num))
        continue

    num1 = float(input("Enter first number: "))
    num2 = float(input("Enter second number: "))

    if choice == "1":
        print("Answer =", num1 + num2)

    elif choice == "2":
        print("Answer =", num1 - num2)

    elif choice == "3":
        print("Answer =", num1 * num2)

    elif choice == "4":
        if num2 == 0:
            print("Cannot divide by zero")
        else:
            print("Answer =", num1 / num2)

    elif choice == "5":
        print("Answer =", num1 ** num2)

    elif choice == "7":
        print("Answer =", num1 % num2)

    elif choice == "8":
        print("Answer =", num1 // num2)

    elif choice == "9":
        print("Percentage =", (num1 / num2) * 100)

    else:
        print("Invalid Choice")