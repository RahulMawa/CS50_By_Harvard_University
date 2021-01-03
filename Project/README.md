----------------------------------------------------
GENERAL DETAILS ABOUT THE BLOG WEBSITE:

This is a Company Blog Website where users can create and log in to accounts. Since I am obsessed with pet dogs, I name this website the 'PUPPY COMPANY BLOG'.
They can update the information on their account pages, and to add some personal touch to it, the users can also upload their profile picture.

Through these accounts they will be able to create, update and delete their blogs.
The users also can read the blogs written by other accounts, but can not update or delete other's blogs.

----------------------------------------------------
ABOUT THE LANGUAGES USED:

All this will be written in the following languages / frameworks: HTML, CSS, JS, Python, Flask, Django, JinJa, and SQL-Alchemy.

-----------------------------------------------------
ABOUT HOW THE WEBSITE IS ORGANISED - FROM A DEVELOPER'S STANDPOINT:

DATABASE:
The db relational model basically centres around two tables. 
First for the User Information, and second for the Blog Information.
Both are connected through a relationship of connecting Blog-Id to the User-Id who wrote them.

User Table stores following attributes: User-Id, Profile Picture, Email, Username, Password, Posts
Blog Table stores following attributes: Blog-Id, User-Id, Date, Title, Text (The blog itself)

CODE:
'APP.py' is the file that has to be run. 
The Forms that are responsible for the StringFields and SubmitButtons through which data is entered by the user all under the 'Forms' files.
The views that are responsible for connecting the blueprints and calling the forms and coding some functions are all under the 'Views' files.
There are dunder init.py files in every directory, the reason being this way when running app.py, the python file knows which all directories to import code from. The dunder init.py files are mostly all empty (other than the one which is in the outermost folder, that is responsible for configuring the SQL-Alchemy db)
The models are responsible for designing the database models, and are all under the 'models' files.

Templates folder holds all the html templates. Here is where all the details and the design (look-wise) of the website are coded.
Static folder holds all of the css and js files, which support the html files.
