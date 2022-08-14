from flask import Flask, render_template, request

# makes the current file into a flask application
app = Flask(__name__)

# define a route for slash
@app.route("/")

def index():
    name = request.args.get("name")
    # print that html file to the user's screen
    return render_template("index.html", name=name)
