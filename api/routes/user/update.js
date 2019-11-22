const express = require('express');
const router = express.Router();
const db = require('../../db');
const passport = require('passport');
const path = require('path');

router.get('/',(req,res,next)=>{
    if(req.user){
        res.sendfile(path.join(__dirname+'../../../../public/update.html'));
    }
    else{
        res.redirect('/');
    }
})

router.get('/ajax',(req,res,next)=>{
    res.json(req.user)
})

module.exports = router;
