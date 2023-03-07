// 과거에는 mysql1을 사용했는데 비동기 사용하려면 2사용(개편된 버전임)
const express =require('express');
const app = express();
const PORT=8080;
//const pool =require("./db/index.js") index.js 는 생략 가능
const pool=require("./db");
//api/menus에 오면
//db에 있는 menus를 조회해서 가져오기
app.get("/api/menus",async(req,res)=>{
    const data=await pool.query("SELECT * FROM menus where menu_id=1");

    return res.json(data[0]);
})
app.listen(PORT,()=>console.log(`${PORT} 서버가동중`));