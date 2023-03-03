const mysql = require("mysql2/promise") // promise 형식으로 받아와야 async/await 사용 수월해짐

//DB 연결정보(connection) setting

const pool = mysql.createPool({
    //AWS HOST
    host :"13.125.243.79",
    //mysql username
    user:"ssafy",
    //mysql password
    password :"ssafy1234",
    //db 및 스키마 이름 (mysql db = schema)
    database : "jony",
    waitForConnections: true,
    connectionLimit:10,
    queueLimit:0
});
//module.exports = {pool}; -> 받아올 떄 const {pool} = require(./db/index.js) ;
module.exports = pool; //-> 받아올 때 const pool(다른 변수가능) = require("./db/index.js");
