
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/javascriptsyntax/javascriptsyntax.html'))
    })

    module.exports = router;
    
    const basicJsRouter = require('./basicJs');
    router.use('/basicJs',basicJsRouter)
    const javscriptobjectRouter = require('./javscriptobject');
    router.use('/javscriptobject',javscriptobjectRouter)
    const javascriptContextRouter = require('./javascriptContext');
    router.use('/javascriptContext',javascriptContextRouter)
    const BigObjectRouter = require('./BigObject');
    router.use('/BigObject',BigObjectRouter)