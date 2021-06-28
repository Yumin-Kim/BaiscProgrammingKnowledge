
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/typescript/typescript.html'))
    })

    module.exports = router;
    
    const exerciseTypeScriptRouter = require('./exerciseTypeScript');
    router.use('/exerciseTypeScript',exerciseTypeScriptRouter)