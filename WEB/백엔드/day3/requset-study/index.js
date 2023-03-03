//실습 API 만들고 테스트하기, Day3 PDF 표 참고
const express = require("express");
const app=express();
const morgan =require('morgan');
const PORT =8080;
app.use(express.json());
app.use(morgan('dev'));

app.get("/user/:id",(req,res)=>{
    try {
        //:id는 params에 찍히고
    console.log(req.params);
    //?key=value 는 query에 찍힌다.
    console.log(req.query);
    return res.json({getid: true, id:req.params.id, name:req.query.test});
    } catch (error) {
        console.log(error);
        return res.json({getid:false});
    }
    //return res.json({test:"HELLO"});
})
app.post("/user/:id",(req,res)=>{
    try {
        console.log(req.body);
        //const {id,password}=req.body; //로 받아도 됨
        //! null undefined "" 0 -> 부정의 의미
        // if(id&&password){ //id와 password가 제대로 받아졌으면
        //     //제대로된 리턴
        //     return res.json({
        //         singup:true,
        //         id:id,
        //         password
        //     })
        // }else throw new Error("Error 입니다");
        return res.json({signup:true, id:req.body.id, password:req.body.password });
  
    } catch (error) {
        return res.json({signup:false});
    }
})
app.patch("/user/:id",(req,res)=>{
    try {
        console.log(req.body);
        return res.json({update:true, id:req.params.id,name:req.body.name});
    } catch (error) {
        return res.json({update:false});
    }
})
app.delete("/user/:id",(req,res)=>{
    try {
        return res.json({delete:true, id:req.params.id});
    } catch (error) {
        return res.json({delete:false});
    }
})
app.listen(PORT,()=>{console.log(`${PORT} 서버 기동중`)});