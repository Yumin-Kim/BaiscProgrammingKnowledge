const express = require('express');
const morgan = require('morgan');
const indexRouter = require('./api/routes');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;
const session = require('express-session');
const flash = require('connect-flash');
const FileStore = require('session-file-store')(session);

const app = express();

app.use(morgan('dev'));
app.use(express.json());
app.use(express.urlencoded({extended:false}));

app.set('views',__dirname +'/views');
app.set('view engine','ejs');
app.use(express.static('public'));
// ///////////////////////////////////////////

app.use(session({
    secret:'keyborad cat',
    resave:false,
    saveUninitialized:true,
}));

app.use(passport.initialize());
app.use(passport.session());
app.use(flash());

// ///////////////////////////////////////////


app.use('/',indexRouter);
app.use((req,res,next)=>{
    const error = new Error('Not found');
    error.status = 404;
    next(error);
});
app.use((error,req,res,next)=>{
    res.status(error.status || 500);
    res.json({
        error:{
            message:error.message
        }
    })
})
module.exports = app;