const express = require('express');
const router = express.Router();
const path = require('path');
const db = require('../../db');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

router.get('/', (req, res, next) => {
    res.sendfile(path.join(__dirname + '../../../../public/join.html'));
});

router.post('/form', (req, res, next) => {
    const { email , name , password } = req.body;
    const data = {email,name,pw:password}
    db.query('insert into nodejsusers set ?',data,(err,result)=>{
        if(err){
            res.redirect('/join');
        }
        else{
            res.redirect('/');
        }
    })
})





module.exports = router;