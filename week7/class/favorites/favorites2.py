import csv

from cs50 import SQL

# open the favorites.db file
db = SQL("sqlite:///favorites.db")

# ask user for a title they want to search for
title = input("Title: ").strip()

# select the count of people from the favorites table where the title they typed in is like whatever the user has just typed in
# store the result in a variable called counter
rows = db.execute("SELECT COUNT(*) AS counter FROM favorites WHERE title LIKE ?", title)

# grab the first row
row = rows[0]
print(row["counter"])