
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/ReactCollection/ReactCollection.html'))
    })

    module.exports = router;
    
    const ClassRouter = require('./Class');
    router.use('/Class',ClassRouter)
    const hooksRouter = require('./hooks');
    router.use('/hooks',hooksRouter)
    const NextjsRouter = require('./Nextjs');
    router.use('/Nextjs',NextjsRouter)
    const ReduxRouter = require('./Redux');
    router.use('/Redux',ReduxRouter)
    const webpackRouter = require('./webpack');
    router.use('/webpack',webpackRouter)
    const babelRouter = require('./babel');
    router.use('/babel',babelRouter)