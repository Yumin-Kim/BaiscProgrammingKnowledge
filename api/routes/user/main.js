const express = require('express');
const router = express.Router();
const path = require('path');

function cookieParse(request){
    const cookie = request.headers.cookie;
    return cookie.split(';').reduce((pre,cur,idx,arr)=>{
        let ele = cur.split('=');
        pre[ele[0].trim()] = ele[1];
        return pre;
    },{}) 
}

router.get('/',(req,res,next)=>{
    if(!req.headers.cookie){
        res.sendfile(path.join(__dirname+'../../../public/main.html'));    
    }else{
        console.log('찾음')
        const {color,background,fontSize} = cookieParse(req);
        console.log(color,background,fontSize);
        res.render('cookie',{color,background,fontSize});
    }
});

router.get('/ajax',(req,res,next)=>{
    res.json({
        title:'AJAX GET 방식으로 준거야!!',
    })
})

router.patch('/patch',(req,res)=>{
    const { title } = req.body
    const data={
        result:'AJAX PATCH 성공!!',
        title
    }
    res.json(data);
})

router.post('/cookie',(req,res,next)=>{
        const { color,background,fontSize } = req.body
        for(let i = 0 ; i < Object.keys(req.body).length ; i ++){
            res.cookie(Object.keys(req.body)[i],Object.values(req.body)[i]);
        }
        res.render('cookie',{color,background,fontSize});
})

module.exports = router;