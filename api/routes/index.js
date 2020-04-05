const express = require('express');
const router = express.Router();
const path = require('path');
const fs = require('fs');
const url = require('url');


const session = require('express-session');
const passport = require('passport');
const LocalStrategy = require('passport-local').Strategy;

const { createHTML, createRouter ,createdeppRouter,creaeteSubHTML } = require('../createfiletext');

router.get('/', (req, res, next) => {
    console.log('req.user', req.user)
    res.sendfile(path.join(__dirname + '../../../index.html'));
});

router.get('/react',(req,res,next)=>{
    res.sendFile(path.join(__dirname + '../../../public/react.html'))
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
                
const datecommunicationRouter = require('./datecommunication/datecommunication'); 
router.use('/datecommunication', datecommunicationRouter);
                
const operationsystemRouter = require('./operationsystem/operationsystem'); 
router.use('/operationsystem', operationsystemRouter);
                

                
const CcompareRouter = require('./Ccompare/Ccompare'); 
router.use('/Ccompare', CcompareRouter);
                
const typescriptRouter = require('./typescript/typescript'); 
router.use('/typescript', typescriptRouter);
                
const AndroidRouter = require('./Android/Android'); 
router.use('/Android', AndroidRouter);
                
const FrontEndBasicConceptRouter = require('./FrontEndBasicConcept/FrontEndBasicConcept'); 
router.use('/FrontEndBasicConcept', FrontEndBasicConceptRouter);
                
const ReactCollectionRouter = require('./ReactCollection/ReactCollection'); 
router.use('/ReactCollection', ReactCollectionRouter);
                
const NodeBasicCategoryRouter = require('./NodeBasicCategory/NodeBasicCategory'); 
router.use('/NodeBasicCategory', NodeBasicCategoryRouter);
                
const javascriptsyntaxRouter = require('./javascriptsyntax/javascriptsyntax'); 
router.use('/javascriptsyntax', javascriptsyntaxRouter);
                
const schoolLectureRouter = require('./schoolLecture/schoolLecture'); 
router.use('/schoolLecture', schoolLectureRouter);
                
const tutorialsRouter = require('./tutorials/tutorials'); 
router.use('/tutorials', tutorialsRouter);
                