const pool = require('./pool');
const bcrypt = require('bcrypt');


function User() {
};

User.prototype = {
    // Find the user data by id or username.
    find: function (user = null, callback) {
        // if the user variable is defind
        if (user) {
            // if user = number return field = id, if user = string return field = username.
            var field = Number.isInteger(user) ? 'id' : 'username';
        }
        // prepare the sql query
        let sql = `SELECT * FROM users WHERE ${field} = ?`;


        pool.query(sql, user, function (err, result) {
            if (err) throw err

            if (result.length) {
                callback(result[0]);
            } else {
                callback(null);
            }
        });
    },

    // This function will insert data into the database. (create a new user)
    // body is an object
    create: function (body, callback) {

        var pwd = body.password;
        // Hash the password before insert it into the database.
        body.password = bcrypt.hashSync(pwd, 10);

        // this array will contain the values of the fields.
        var bind = [];
        // loop in the attributes of the object and push the values into the bind array.
        for (prop in body) {
            bind.push(body[prop]);
        }
        // prepare the sql query
        let sql = `INSERT INTO users(username, email, password) VALUES (?, ?, ?)`;
        // call the query give it the sql string and the values (bind array)
        pool.query(sql, bind, function (err, result) {
            if (err) throw err;
            // return the last inserted id. if there is no error
            callback(result.insertId);
        });
    },

    login: function (username, password, callback) {
        // find the user data by his username.
        this.find(username, function (user) {
            // if there is a user by this username.
            if (user) {
                // now we check his password.
                if (bcrypt.compareSync(password, user.password)) {
                    // return his data.
                    callback(user);
                    return;
                }
            }
            // if the username/password is wrong then return null.
            callback(null);
        });

    },

    create_table: function (newUserID) {
        //const sqlSelectID = `SELECT id FROM users`;
        //let newUserID = '';

        // pool.query(sqlSelectID, function (err, result) {
        //if (err) console.log(err);
        //newUserID = result[result.length - 1].id.toString();
        console.log(newUserID);
        newUserID = 'user' + newUserID;
        //emotion_dict = {0: "Angry", 1: "Disgust", 2: "Fear", 3: "Happy", 4: "Sad", 5: "Surprise", 6: "Neutral"}
        const sqlCreateTable = `create table ${newUserID}(
                                    id int auto_increment,
                                    date datetime not null,
                                    pixels blob not null,
                                    angry double, disgust double ,fear double ,happy double, sad double, surprise double, neutral double, 
                                    PRIMARY KEY (id))`;
        pool.query(sqlCreateTable, function (err, result) {
            if (err) console.log(err);
            else console.log("Таблица создана");
        });
        //});


    },

    get_emotion: function (user, callback) {
        //const sqlSelectID = `SELECT id FROM users`;
        //let newUserID = '';

       // pool.query(sqlSelectID, function (err, result) {
            //if (err) console.log(err);
            //newUserID = result[result.length - 1].id.toString();
            const userId = user.id;
            let tableName = 'user' + userId.toString();
            const sqlSelectEmotions = `SELECT * FROM ${tableName}`;

            pool.query(sqlSelectEmotions, function (err, result) {
                if (err) console.log(err);
                if (result) {
                    callback(result);


                } else {
                    callback(null);

                }
            })
       // });
    }


}

module.exports = User;
