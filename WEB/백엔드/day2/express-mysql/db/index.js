const mysql = require("mysql2/promise");

const pool = mysql.createPool({
    //AWS IP
    host:"13.125.243.79",
    //mysql 유저이름
    user:"ssafy",
    //비밀번호
    password:"ssafy1234",
    //db 및 스키마 이름
    database:"jony",
    waitForConnections:10,
    connectionLimit:10,
    queueLimit:0,
})
module.exports=pool;