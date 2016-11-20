from flask import render_template
from app import app
import requests

@app.route('/')
@app.route('/index')
def index():
    pacients = requests.get('http://localhost:8080/api/paciente').json()
    user = {'nickname': 'Miguel'}  # fake user
    # posts = [  # fake array of posts
    #     { 
    #         'author': {'nickname': 'John'}, 
    #         'body': 'Beautiful day in Portland!' 
    #     },
    #     { 
    #         'author': {'nickname': 'Susan'}, 
    #         'body': 'The Avengers movie was so cool!' 
    #     }
    # ]
    return render_template("index.html",
                           title='Home',
                           user=user,
                           pacients=pacients)