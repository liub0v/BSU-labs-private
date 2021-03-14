from flask import Flask
from flask import request
from network import printhello
app = Flask(__name__)


@app.route("/")
def hello():
    return printhello("start")


# @app.route("/")
# def abcd():
#     if request.method == 'GET':
#         return "NICE!"


@app.route('/', methods=['POST'])
def upload():
    if request.method == 'POST':
        content = request.json
        print(content['value']) #это работает!
        #data = request.files['file']
        #print(data)
        return "hello"
#       f = function(data)
#       return f

#req = request.post("192.168.100.45:3000", data = f)

if __name__ == "__main__":
    app.debug = True
    app.run(host="localhost", port=5000)
