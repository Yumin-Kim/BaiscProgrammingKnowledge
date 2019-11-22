const textHTML = (title, description) =>
    `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>${ title}</title>
    <script src="../js/ajax.js" ></script>
</head>
<body>
    <h1><a href="/">${ title}</a></h1>
    <h2> ${ description} </h2> 
    <h3>세부 카테고리를 추가 해주세요!!</h3>
    <form>
        <p>
        Sub Category : <input type="text" placeholder="title" name="subcategory"  >
        </p>
        <p>
        Sub Description : <input type="text" placeholder="description" name="subdescription" >
        </p>
        <p>
            <input type="submit" >
        </p>
    </form>
    <ul class="subCategory">
    </ul>
</body>
</html>
`;

const subtext = (title,description,url) =>{
    return `
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <meta http-equiv="X-UA-Compatible" content="ie=edge">
    <title>${title}</title>
</head>
<body>
    <h1><a href="/${url}">${title}</a></h1>
    <h2> ${description} </h2> 
        
</body>
</html>
    `;
}

const textrouter = (title) => {
    return `
    const express = require('express');
    const router = express.Router();
    const path = require('path');

    router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/${title}/${title}.html'))
    })

    module.exports = router;
    `;
}

const deepRouter = (title,url) =>{
    return `
const express = require('express');
const router = express.Router();
const path = require('path');

router.get('/',(req,res,next)=>{
    res.sendfile(path.join(__dirname+'../../../../public/${url}/${title}.html'))
})

module.exports = router;
    `;
}

module.exports = {
    createHTML(title, description) {
        return textHTML(title, description);
    },
    createRouter(title){
        return textrouter(title);
    },
    creaeteSubHTML(title,description,url){
        return subtext(title,description,url);
    },
    createdeppRouter(title,url){
        return deepRouter(title,url);
    }
};