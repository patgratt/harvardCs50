from flask import Flask, render_template, request

# makes the current file into a flask application
app = Flask(__name__)

# define a route for slash (homepage)
# this a decorator that modifies this route function
@app.route("/")
def index():
    # render (print) that html file to the user's screen
    return render_template("index.html")

# define route for /greet
@app.route("/greet")
def greet():
    name = request.args.get("name")
    return render_template("greet.html", name=name)