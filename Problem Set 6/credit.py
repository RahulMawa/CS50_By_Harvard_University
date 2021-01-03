import re
from cs50 import get_int

#declaring variables
num = get_int("Number: ")
len_num = len(str(num))
x = num
sum1 = 0
sum2 = 0
twoDigits = 0
sumfinal = sum1 + sum2

temp = 0

#If the card number length is incorrect
if len_num < 13 or len_num > 16:
    print("INVALID")

#Checksum algorithm
for i in range(round(len_num)):
    sum1 = sum1 + (x % 10)
    x = x / 10
    twoDigits = (2 * (x % 10))

    if twoDigits > 9:
        temp = temp + (twoDigits % 10)
        twoDigits /= 10
        temp = temp + twoDigits
        sum2 = sum2 + temp
        temp = 0

    else:
        sum2 = sum2 + twoDigits
        x /= 10

#If checksum is not correct, the number is "INVALID"
if sumfinal % 10 != 0:
    print("INVALID")

#Check for AMEX
if re.search("^34", str(num)) or re.search("^37", str(num)):
    if len_num == 15:
        print("AMEX")

#Check for MasterCard
if re.search("^51", str(num)) or re.search("^52", str(num)) or re.search("^53", str(num)) or re.search("^54", str(num)) or re.search("^55", str(num)):
    if len_num == 16:
        print("MASTERCARD")
        
#Check for VISA
if re.search("^4", str(num)):
    if len_num == 13 or len_num == 16:
        print("VISA")