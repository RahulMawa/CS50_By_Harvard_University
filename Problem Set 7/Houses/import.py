import csv
from sys import argv, exit
from cs50 import SQL

def main():

    if len(argv) < 2:
        exit(1)

    # create new database
    open("students.db", "w").close()
    db = SQL("sqlite:///students.db")

    #create students table
    db.execute("""
                CREATE TABLE students
                (id INTEGER PRIMARY KEY AUTOINCREMENT,
                first VARCHAR(255),
                middle VARCHAR(255),
                last VARCHAR(255),
                house VARCHAR(10),
                birth INTEGER)
                """)

    with open (argv[1], "r") as students:
        reader = csv.DictReader(students)

        for row in reader:
            name = row["name"].split(" ")

            first_name = name[0]
            last_name = name[-1]

            if len(name) > 2:
                middle_name = name[1]
            else:
                middle_name = None

            house = row["house"]
            birth = row["birth"]

            print(f"{first_name} {middle_name} {last_name} {house} {birth}")

            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ? ,?)",
            first_name, middle_name, last_name, house, birth)

if __name__ == "__main__":
    main()