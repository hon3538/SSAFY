//DB
const mysql=require('mysql2/promise');
const pool = mysql.createPool({
    //AWS HOST
    host:"13.125.243.79",
    //mysql username
    user:"ssafy",
    //mysql password
    password:"ssafy1234",
    //db 및 스키마 이름 (mysql db = schema)
    database : "jony",
    waitForConnections: true,
    connectionLimit:10,
    queueLimit:0
});

module.exports =pool;