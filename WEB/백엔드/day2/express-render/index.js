const express = require('express');
const app = express();
const PORT=8080;

//index.html 보여주기
app.get("/",(req,res)=>{
    //현재 기기에서 작동중인 서버의 경로
    return res.sendFile(__dirname+"/views/index.html");
})

//login.html 보여주기
app.get("/login",(req,res)=>{
    return res.sendFile(__dirname+"/views/login.html");
})
//whoami.html 보여주기
app.get("/whoami",(req,res)=>{
    return res.sendFile(__dirname+"/views/login.html");
})
app.listen(PORT,()=>{ console.log(`${PORT} 서버 기동중`)});