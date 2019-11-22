const mysql = require('mysql');
const db = mysql.createConnection({
    host:'localhost',
    user:'root',
    password:'111111',
    database:'nodejs',
    port:'3306',
})

db.connect();

module.exports = db;
