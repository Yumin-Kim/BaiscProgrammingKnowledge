const express = require('express');
const router = express.Router();
const webpackRouter = require('./Webpack');
const reduxRouter = require('./Redux');
const path = require('path');

router.use('/Webpack',webpackRouter);
router.use('/Redux',reduxRouter);

router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/react.html'))
});

module.exports = router;