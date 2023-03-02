
const express =require('express');
const { builtinModules } = require('module');
const app=express();
const PORT=8080;

const infos=[
    {
        name:"나나",
        age:12
    },
    {
        name:"유진",
        age:8
    },
    {
        name:"재범",
        age:40
    }
]
app.get("/tests",(req,res)=>{
    return res.json(infos);
})
app.get("/infos/names",(req,res)=>{
    return res.json(infos.map((li)=>{
        return li.name;
    }))
})

app.get("/infos/ages",(req,res)=>{
    return res.json(infos.map(li=>li.age));
})

app.get("/infos/0",(req,res)=>{
    return res.json(infos[0]); //index 0만 리턴
})



app.listen(PORT,()=>{ console.log(`${PORT} 서버 기동중`)});