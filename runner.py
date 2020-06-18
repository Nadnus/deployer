import subprocess
import json
from flask import Flask 
from flask import jsonify
from flask_cors import CORS


app = Flask(__name__)
CORS(app)
@app.route("/")
def loader():
    mylist = ["./a.out", "dick", "lous"]
    subprocess.run(mylist)
    with open("data.json") as json_file:
        data = json.load(json_file)
        return jsonify(data)
if __name__ == "__main__":
    app.run()
