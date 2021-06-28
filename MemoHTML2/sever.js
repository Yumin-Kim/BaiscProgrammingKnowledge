const http = require('http');
const app = require('./app');
const port = process.env.PORT || 8000;

const sever = http.createServer(app);

sever.listen(port);