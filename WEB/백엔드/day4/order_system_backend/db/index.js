//#1 DB 세팅
const mysql = require('mysql2/promise');

const pool = mysql.createPool({
    host : "13.125.243.79",
    user:"ssafy",
    password:"ssafy1234",
    database:"order_schema",
    waitForConnections :true,
    connectionLimit:100,
    queueLimit:0
    
});

module.exports=pool;