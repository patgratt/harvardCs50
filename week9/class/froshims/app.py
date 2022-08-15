from flask import Flask, render_template, request

# makes the current file into a flask application
app = Flask(__name__)

# define a route for slash (homepage)
@app.route("/")
def index():
    # render (print) that html file to the user's screen
    return render_template("index.html")

# by default routes only support get, so have to specify post
@app.route("/register", methods=['POST'])
def register():

    sports = ["Basketball", "Soccer", "Ultimate Frisbee"]
    # Validate submission
    # if the name value is false (they didn't input anything or didn't choose a sport
    if not request.form.get("name") or request.form.get("sport") not in sports:
        return render_template("failure.html")

    # cofirm registration if they filled out the form correctly
    return render_template("success.html")