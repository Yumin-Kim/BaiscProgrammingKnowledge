
const express = require('express');
const router = express.Router();
const path = require('path');

router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/ReactCollection/Nextjs.html'))
})

module.exports = router;
    