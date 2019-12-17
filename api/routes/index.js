const express = require('express');
const router = express.Router();
const path = require('path');
const db = require('../db');
const fs = require('fs');
const url = require('url');

const mainRouter = require('./user/main');
const joinRouter = require('./user/join');
const signRouter = require('./user/sign');
const updateRouter = require('./user/update');
const reactRouter = require('./react/react');

const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

const { createHTML, createRouter ,createdeppRouter,creaeteSubHTML } = require('../createfiletext');

router.get('/', (req, res, next) => {
    console.log('req.user', req.user)
    res.sendfile(path.join(__dirname + '../../../index.html'));
});

router.post('/', (req, res, next) => {
    const { title, description } = req.body;
    const savesdir = path.join(__dirname + `../../../public/${req.body.title}`);
    const htmlfile = path.join(__dirname + `../../../public/${req.body.title}/${req.body.title}.html`);
    const routerdir = path.join(__dirname + `/${req.body.title}`);
    const routerfile = path.join(__dirname + `/${req.body.title}/${req.body.title}.js`);
    const filedir = path.join(__dirname + '../../category/main.txt');
    let data;
    if (Object.keys(req.body).length === 0) {
        fs.readFile(filedir, 'utf-8', (err, data) => {
            data = {
                result: data.split(','),
                mkdir: false,
            }
            res.json(data);
        });
    } else {
        if (fs.existsSync(savesdir)) {
            console.log('파일있어여');
            let data = {
                result: '해당 카테고리의 파일,폴더가 있습니다 ',
                mkdir: true
            }
            res.json(data);
        } else {
            fs.appendFile(path.join(__dirname+'/index.js'),`
const ${title}Router = require('./${title}/${title}'); 
router.use('/${title}', ${title}Router);
                `,(err)=>{
                    console.log('실행',err);
                })
            fs.mkdirSync(savesdir);
            fs.mkdirSync(routerdir);
            data = [title, description];
            fs.writeFile(htmlfile, createHTML(title, description), (err2) => {
                if (err2) throw err2;
            })
            fs.writeFile(routerfile,createRouter(title), (err3) => {
                if (err3) throw err3;
                
            })
            fs.appendFile(filedir, `${data},`, 'utf-8', (err) => {
                if (err) throw err;
                fs.readFile(filedir, 'utf-8', (err1, data) => {
                    if (err1) throw err1;
                    data = {
                        result: data.split(','),
                        mkdir: false,
                    }
                    res.json(data);
                });
            });
        }
    }
})

router.use('/main', mainRouter);
router.use('/join', joinRouter);
router.use('/sign', signRouter);
router.use('/update', updateRouter);
router.use('/react', reactRouter);

passport.serializeUser(function (user, done) {
    console.log('serializeUser')
    done(null, user.id);
});

passport.deserializeUser(function (id, done) {
    db.query('select * from nodejsusers where id=?', [id], (err, row) => {
        done(err, row[0]);
    })
});

passport.use('local', new LocalStrategy({
    usernameField: 'email',
    passwordField: 'password',
    passReqToCallback: true,
}, (req, email, password, done) => {
    db.query('select * from nodejsusers where email=?', [email], (err, rows) => {
        if (err) throw err;
        if (rows[0]) {
            if (rows[0].email === email) {
                if (rows[0].pw === password) {
                    console.log('찾음')
                    return done(null, rows[0]);
                } else {
                    console.log('pw identify')
                    return done(null, false, { message: 'pw를 확인해주세요' })
                }
            } else {
                console.log('email identify');
                return done(null, false, { message: 'pw를 확인해주세요' })
            }
        } else {
            console.log('please join');
            return done(null, false, { message: '회원가입이 필요합니다' })
        }
    })
}))

router.post('/subpage/',(req,res,next)=>{
    const { url } = req.body;
    const subText = path.join(__dirname+`../../category/${url}.txt`)
    console.log(subText)
    
    if(fs.existsSync(subText)){
        if(Object.keys(req.body).length >1  ){
            // 클릭시 추가 로직
            const { title, description } = req.body;
            const data = [title , description ];
            const subjsurl = path.join(__dirname+`/${url}/${title}.js`);
            const subhtmlurl = path.join(__dirname+`../../../public/${url}/${title}.html`);
            console.log(subjsurl)
            fs.appendFile(subText,`${data},`,(err1)=>{
                if(err1) throw err1;
                fs.readFile(subText,'utf-8',(err,data)=>{
                    if(err) throw err;
                    fs.writeFile(subhtmlurl,creaeteSubHTML(title,description,url),(err2)=>{
                        if(err2) throw err2;
                    })
                    fs.writeFile(subjsurl,createdeppRouter(title,url),(err3)=>{
                        if(err3) throw err3;
                    } );
                    fs.appendFile(path.join(__dirname+`/${url}/${url}.js`),`
    const ${title}Router = require('./${title}');
    router.use('/${title}',${title}Router)`,(err4)=>{
                        if(err4) throw err4;
                    })
                    const resData = {
                        result:data.split(','),
                        mkdir:false,
                    }
                    res.json(resData);
                })
            })
        }else{
            // 새로고침후 로직
            fs.readFile(subText,'utf-8',(err,data)=>{
                if(err) throw err;
                const resdata={ 
                    result:data.split(','),
                    mkdir:false,
                };
                res.json(resdata);            
            })
        }    
    }else{
    fs.writeFile(subText,'',()=>{});
    }
})

module.exports = router;
///// 사용자가 추가한 라우팅
                
const GitRouter = require('./Git/Git'); 
router.use('/Git', GitRouter);
                
const LinuxRouter = require('./Linux/Linux'); 
router.use('/Linux', LinuxRouter);
                
const MysqlRouter = require('./Mysql/Mysql'); 
router.use('/Mysql', MysqlRouter);
                
const computerRouter = require('./computer/computer'); 
router.use('/computer', computerRouter);
                
const cLanguageRouter = require('./cLanguage/cLanguage'); 
router.use('/cLanguage', cLanguageRouter);
                
const javaRouter = require('./java/java'); 
router.use('/java', javaRouter);
                