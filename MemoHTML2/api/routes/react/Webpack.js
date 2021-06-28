const express = require('express');
const router = express.Router();
const path = require('path');
console.log('asd')
router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/React/Webpack.html'))
})

module.exports = router;