//WAS
const express=require('express');
const app=express();

const pool = require('./DB/index');

const PORT=8080;

app.get('/api/drinks/1',async(req,res)=>{
    try {
        //const data=await pool.query(`SELECT * FROM menus where menu_id=1`);
        const data=await pool.query(`SELECT * FROM menus`);
        console.log(data[0].reduce((acc,cur)=>{
            if(cur.menu_id===1)
                acc.push(cur);
            return acc;
        }),{});
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return error;
    }
})
app.listen(PORT,()=>console.log(`${PORT} 서버 기동중`));