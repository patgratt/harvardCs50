from flask import Flask, render_template, request

# makes the current file into a flask application
app = Flask(__name__)

# decorator that defines a route for slash
@app.route("/")


def index():
    # go into the request arguments from the url and get the name
    name = request.args.get("name")
    # print that html file to the user's screen
    return render_template("index.html", name=name)
