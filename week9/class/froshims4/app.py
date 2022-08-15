from flask import Flask, render_template, request, redirect
from cs50 import SQL

# makes the current file into a flask application
app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = [
        "Basketball",
        "Soccer", 
        "Ultimate Frisbee", 
        "Football"
        ]

# define a route for slash (homepage)
@app.route("/")
def index():
    # render (print) that html file to the user's screen
    return render_template("index.html", sports=SPORTS)

# by default routes only support get, so have to specify post
@app.route("/register", methods=['POST'])
def register():

    # Validate name
    name = request.form.get("name")
    # if the name value is false (they didn't input anything)
    if not name:
        return render_template("error.html", message="Missing name")
    
    # Validate sport
    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing sport")
    if sport not in SPORTS:
        return render_template("error.html", message="Invalid Sport")

    # Remember registrant
    db.execute("INSERT INTO registrants (name, sport) VALUES(?, ?)", name, sport)

    # confirm registration if they filled out the form correctly
    return redirect("/registrants")

@app.route("/registrants")
def registrants():
    registrants = db.execute("SELECT * FROM registrants")
    return render_template("registrants.html", registrants=registrants)