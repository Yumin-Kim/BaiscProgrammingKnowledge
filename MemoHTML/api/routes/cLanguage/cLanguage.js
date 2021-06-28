
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
    const pointerRouter = require('./pointer');
    router.use('/pointer',pointerRouter)
    const typedefRouter = require('./typedef');
    router.use('/typedef',typedefRouter)
    const clangcontextRouter = require('./clangcontext');
    router.use('/clangcontext',clangcontextRouter)
    const clangdatastructRouter = require('./clangdatastruct');
    router.use('/clangdatastruct',clangdatastructRouter)
   