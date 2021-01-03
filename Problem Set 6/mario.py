from cs50 import get_int

num = 0
while num < 1 or num > 8:
    num = get_int("Height: ")

count = 1
for i in range(num):
    print(" " * (num - count), end="")
    print("#" * i, end="")
    print("#  #", end= "")
    print("#" * i, end="")
    print("")
    count += 1