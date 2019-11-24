
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/Linux/Linux.html'))
    })

    module.exports = router;
    
    const UNIXRouter = require('./UNIX');
    router.use('/UNIX',UNIXRouter)
