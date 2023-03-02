const express = require('express');

//백엔드 서버 만들기
const app = express();
const PORT=8080;
const cors = require('cors');
//nodemon index 재가동
app.use(cors());
//get, post, patch, put, delete로 받을 수 있다.

//라우터 개념
//location / -> ~보여줘라 처럼, api/info/ 면 안에있는 내용을 실행해라
//api를 붙이면 html이 아닌 json을 리턴
//localhost = 127.0.0.1 -> 현재 본인의 주소(경로)를 의미
app.get("/api/info",(req,res)=>{
    return res.json({
        name:"zz",
        job:"tutor"
    });
})
//그냥 위에만 쳤을때, localhost:8080 들어가보면 Can not Get 이라고 나온다
//이유는 localhost:8080 을치면 /(root)로 들어가는데 위에선 /api/info 의 경로인
//경우만 세팅해줬다. 따라서 아래처럼 따로 정의해주면 해당 내용을 실행한다.
app.get("/",(req,res)=>{
    return res.json({
        test:"OK"
    })
})
//클라이언트 : 브라우저 -> 백엔드 서버(localhost:8080서버)의 api/info 에 요청

app.listen(PORT,()=>console.log(`${PORT} 서버 가동중`));