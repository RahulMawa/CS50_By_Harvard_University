import csv
from sys import argv, exit
from cs50 import SQL

def main():

    if len(argv) < 2:
        exit(1)

    db = SQL("sqlite:///students.db")

    house = argv[1]

    student_dict = db.execute("SELECT first, middle, last, birth FROM students WHERE house = ? ORDER BY last ASC, first ASC", house)

    # print(student_dict)

    # for first, middle, last, birth in student_dict.items():
    #     if middle == None:
    #         print("{} {}, born {}".format(first, last, birth))
    #     else:
    #         print("{} {} {}, born {}".format(first, middle, last, birth))

    for row in student_dict:
        if row["middle"] == None:
            print("{} {}, born {}".format(row['first'], row['last'], row['birth']))
        else:
            print("{} {} {}, born {}".format(row['first'], row['middle'], row['last'], row['birth']))


if __name__ == "__main__":
    main()