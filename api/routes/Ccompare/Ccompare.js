
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/Ccompare/Ccompare.html'))
    })

    module.exports = router;
    
    const javacompareRouter = require('./javacompare');
    router.use('/javacompare',javacompareRouter)
    const javascriptcompareRouter = require('./javascriptcompare');
    router.use('/javascriptcompare',javascriptcompareRouter)