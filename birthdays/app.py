import os

from cs50 import SQL
from flask import Flask, flash, jsonify, redirect, render_template, request, session

# Configure application
app = Flask(__name__)

# Ensure templates are auto-reloaded
app.config["TEMPLATES_AUTO_RELOAD"] = True

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///birthdays.db")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":

        name = request.form.get("name")
        month = request.form.get("month")
        day = request.form.get("day")

        if name and month and day:
            db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)


        else:
            birthdays = db.execute("SELECT * FROM birthdays")
            return render_template("index.html", birthdays=birthdays)
        return redirect("/")



    else:

        @app.route("/", methods=["GET", "POST"])
        def index():
            if request.method == "POST":
                # Get data from the form
                name = request.form.get("name")
                month = request.form.get("month")
                day = request.form.get("day")

        # Insert into database if all fields are provided
                if name and month and day:
                    db.execute("INSERT INTO birthdays (name, month, day) VALUES (?, ?, ?)", name, month, day)

                return redirect("/")

    else:
        # Get all entries from the database
        birthdays = db.execute("SELECT * FROM birthdays")
        return render_template("index.html", birthdays=birthdays)


        return render_template("index.html")


