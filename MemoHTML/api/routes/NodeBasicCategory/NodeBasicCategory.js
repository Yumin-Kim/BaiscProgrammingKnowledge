
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/NodeBasicCategory/NodeBasicCategory.html'))
    })

    module.exports = router;
    
    const nodeStandardBulidInObjectRouter = require('./nodeStandardBulidInObject');
    router.use('/nodeStandardBulidInObject',nodeStandardBulidInObjectRouter)