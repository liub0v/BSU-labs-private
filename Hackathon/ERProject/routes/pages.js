const express = require('express');
const User = require('../core/user');
const request = require('request');
const router = express.Router();

// create an object from the class User in the file core/user.js
const user = new User();

// Get the index page
router.get('/', (req, res, next) => {
    let user = req.session.user;

    // If there is a session named user that means the use is logged in. so we redirect him to home page by using /home route below
    if (user) {
        res.redirect('/home');
        return;
    }
    // IF not we just send the index page.
    res.render('index', {opp: req.session.opp, title: "My application"});
})

// Get home page
router.get('/home', (req, res, next) => {
    let user = req.session.user;

    if (user) {
        //let id =user.getId();
        res.render('home', {opp: req.session.opp, id: user.id});
        return;
    }
    res.redirect('/');
});

// Post login data
router.post('/login', (req, res, next) => {
    // The data sent from the user are stored in the req.body object.
    // call our login function and it will return the result(the user data).
    user.login(req.body.username, req.body.password, function (result) {
        if (result) {
            // Store the user data in a session.
            req.session.user = result;
            req.session.opp = 1;
            // redirect the user to the home page.
            res.redirect('/home');
        } else {
            // if the login function returns null send this error message back to the user.
            res.send('Username/Password incorrect!');
        }
    })

});


// Post register data
router.post('/register', (req, res, next) => {
    // prepare an object containing all user inputs.
    let userInput = {
        username: req.body.username,
        email: req.body.email,
        password: req.body.password
    };
    // call create function. to create a new user. if there is no error this function will return it's id.
    user.create(userInput, function (lastId) {
        // if the creation of the user goes well we should get an integer (id of the inserted user)
        if (lastId) {
            // Get the user data by it's id. and store it in a session.
            user.find(lastId, function (result) {
                req.session.user = result;
                req.session.opp = 0;
                res.redirect('/home');
            });
            user.create_table(lastId)

        } else {
            console.log('Error creating a new user ...');
        }
    });

});


// Get loggout page
router.get('/logout', (req, res, next) => {
    // Check if the session is exist
    if (req.session.user) {
        // destroy the session and redirect the user to the index page.
        req.session.destroy(function () {
            res.redirect('/');
        });
    }
});

router.get('/camera', (req, res, next) => {
    if (req.session.user) {
        res.render('camera');
    }
})
router.post('/signin-form', (req, res, next) => {
    req.session.opp = 2;
    res.redirect('/');
})
router.post('/login-form', (req, res, next) => {
    req.session.opp = 3;
    res.redirect('/');
})
router.get('/emotion', (req, res, next) => {
    let currentUser = req.session.user;


    /*  angry: 0,
     disgust: 0,
     fear: 0,
     happy: 0,
     sad: 0,
     surprise: 0,
     neutral: 0,*/

    let information = [];

    user.get_emotion(currentUser, function (result) {

        if (result && currentUser) {
            for (let i = 0; i < result.length; i++) {
                let emotion0 = {
                    name: 'angry',
                    value: 0
                }
                let emotion1 = {
                    name: 'disgust',
                    value: 0
                }
                let emotion2 = {
                    name: 'fear',
                    value: 0
                }
                let emotion3 = {
                    name: 'happy',
                    value: 0
                }
                let emotion4 = {
                    name: ' sad',
                    value: 0
                }
                let emotion5 = {
                    name: 'surprise',
                    value: 0
                }

                let operation = {
                    id: 0,
                    date: 0,
                    max: 0,
                    emotions: [],
                    toString: function () {
                        return 'id:' + this.id + ',date-' + this.date + ',max:' + this.max +
                            ',' + this.emotions;
                    }

                }
                for (let j = 0; j < 7; j++) {
                    let emotion = {
                        name: '',
                        value: 0,
                        toString: function () {
                            return 'name:' + this.name + ',value:' + this.value;

                        }
                    }
                    operation.emotions.push(emotion);
                }
                // operation.emotions.push(emotion0,emotion1,emotion2,emotion3,emotion4,emotion5,emotion6);
                operation.id = result[i].id.toString();
                let data = result[i].date.toString().split(' ');
                operation.date = data[1] + " " + data[2] + " " + data[3] + " " + data[4];
                operation.emotions[0].value = result[i].angry;
                operation.emotions[0].name = 'angry';
                operation.emotions[1].value = result[i].disgust;
                operation.emotions[1].name = 'disgust';
                operation.emotions[2].value = result[i].fear;
                operation.emotions[2].name = 'fear';
                operation.emotions[3].value = result[i].happy;
                operation.emotions[3].name = 'happy';
                operation.emotions[4].value = result[i].sad;
                operation.emotions[4].name = 'sad';
                operation.emotions[5].value = result[i].surprise
                operation.emotions[5].name = 'surprise';
                operation.emotions[6].value = result[i].neutral;
                operation.emotions[6].name = 'neutral';
               /* operation.emotions[0].value = Math.random() * (0.3 -0.01) + 0.1;
                operation.emotions[1].value = Math.random() * (0.01 -0.001) + 0.001;
                operation.emotions[2].value = Math.random() * (0.1 -0.001) + 0.001;
                operation.emotions[3].value = Math.random() * (0.2 -0.1) + 0.1;
                operation.emotions[4].value = Math.random() * (0.3 -0.1) + 0.1;
                operation.emotions[5].value = Math.random() * (0.1 -0.01) + 0.1;
                operation.emotions[6].value = Math.random() * (0.5 -0.4) + 0.1;*/


                let maxIndex = operation.emotions.reduce((acc, curr, i) => operation.emotions[acc].value > curr.value ? acc : i, 0);
                operation.max = operation.emotions[maxIndex].name;
                //console.log(operation)
                information.push(operation);

            }
            //emotions.angry[result.length-1]=result[result.length-1].angry.toString();
            res.render('home', {opp: 1, information: information, id: currentUser.id})

        }
        //res.redirect('/home');

    })

})
router.post('/sendData', (req, res, next) => {

    /* const formData = {
         my_field: 'my_value',
     };
     request.post({url:'http://localhost:5000', formData: formData}, function optionalCallback(err, httpResponse, body) {
         if (err) {
             return console.error('upload failed:', err);
         }
         console.log('Upload successful!  Server responded with:');
     });*/
    request({
            uri: 'http://localhost:5000/',
            body: JSON.stringify({value: "information"}),
            method: 'POST',
            headers: {
                'Content-Type': 'application/json'
            }
        },
        function (error, response, body) {
            if (error) {
                return console.error('upload failed:', error);
            }
            console.log('Upload successful!  Server responded with:');
        })
    res.redirect('/home');
})
module.exports = router;
