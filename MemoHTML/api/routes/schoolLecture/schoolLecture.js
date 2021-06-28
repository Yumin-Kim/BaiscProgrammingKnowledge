
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/schoolLecture/schoolLecture.html'))
    })

    module.exports = router;
    
    const DataStructRouter = require('./DataStruct');
    router.use('/DataStruct',DataStructRouter)
    const jspSeveletRouter = require('./jspSevelet');
    router.use('/jspSevelet',jspSeveletRouter)
    const AndroidRouter = require('./Android');
    router.use('/Android',AndroidRouter)
    const DataBaseRouter = require('./DataBase');
    router.use('/DataBase',DataBaseRouter)