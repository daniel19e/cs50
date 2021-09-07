import sys
user_input = input("Enter a credit card number: ")

if not len(user_input) in [13, 15, 16]:
    print("INVALID")
    sys.exit()


# implement Lunh Algorithm
x = int(user_input)
sum1 = 0
sum2 = 0
totalSum = 0
while True:
    # get every other digit starting from last
    rem1 = x % 10
    x = int(x / 10)
    sum1 = sum1 + rem1

    # get second to last digit
    rem2 = x % 10
    x = int(x / 10)

    # double digits and add to sum
    rem2 = rem2 * 2
    dig1 = rem2 % 10
    dig2 = int(rem2 / 10)
    sum2 = sum2 + dig1 + dig2
    if x <= 0:
        break

totalSum = sum1 + sum2

# check if last digit of sum equals 0
if totalSum % 10 != 0:
    print("INVALID")
    sys.exit()


# check for starting digits
first_two = int(user_input[0:2])
first_digits = int(user_input)

if first_two == 37 or first_two == 34:
    print("AMEX")
elif first_two > 50 and first_two <= 55:
    print("MASTERCARD")
elif first_two // 10 == 4:
    print("VISA")
else:
    print("INVALID")
