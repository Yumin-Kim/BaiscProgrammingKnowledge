const express = require('express');
const router = express.Router();
const session = require('express-session');
const db = require('../../db');
const path = require('path');
const passport = require('passport');
const flash = require('connect-flash');

router.get('/', (req, res, next) => {
    let msg = req.flash('error');
    if(msg.length){
        res.render('sign',{
            msg:msg[0],
        })
    }
    res.sendfile(path.join(__dirname + '../../../../public/sign.html'));
})
router.post('/signup',passport.authenticate('local',{
    successRedirect:'/',
    failureRedirect:'/sign',
    failureFlash:true,
}))

// router.post('/signup',(req,res,next)=>{
//     (passport.authenticate('local-join',(err,user,info)=>{
//         console.log('err',err);
//         console.log('user',user);
//         console.log('info',info);
//     }))(req,res,next);
// })

// app.get('/login', function(req, res, next) {
//     passport.authenticate('local', function(err, user, info) {
//       if (err) { return next(err); }
//       if (!user) { return res.redirect('/login'); }
//       req.logIn(user, function(err) {
//         if (err) { return next(err); }
//         return res.redirect('/users/' + user.username);
//       });
//     })(req, res, next);
//   });


module.exports = router;