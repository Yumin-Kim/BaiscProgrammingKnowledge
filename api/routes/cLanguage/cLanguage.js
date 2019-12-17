
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/cLanguage/cLanguage.html'))
    })

    module.exports = router;

    const CconceptRouter = require('./Cconcept');
    router.use('/Cconcept',CconceptRouter)
    const ccompileRouter = require('./ccompile');
    router.use('/ccompile',ccompileRouter)