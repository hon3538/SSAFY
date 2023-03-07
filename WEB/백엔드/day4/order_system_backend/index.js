//#2 express 세팅 
const express =require('express');
const app=express();
const pool=require('./db');
const PORT =8080;
//body data 받아오기
app.use(express.json());

//정적파일 서비스
app.use('/public', express.static('public'));


//cors
const cors =require('cors');
app.use(cors());
//morgan
const morgan = require('morgan');
app.use(morgan('dev'));
//multer
const path=require('path'); // node 내장 라이브러리
const multer=require('multer');
const upload = multer({
    storage : multer.diskStorage({
        //업로드시 폴더 위치
        destination: (req,file,done)=>{
            done(null,"public/")
        },
        //업로드할 경우 파일이름 형식
        filename:(req,file,done)=>{
            //파일이름 + 현재시간 + 확장자
            //hello.jpg ->hello234126216.jpg
            //해당 파일에 확장자만 가져온다
            const ext=path.extname(file.originalname);
            //확장자를 제외한 파일이름
            const fileNameExeptExt = path.basename(file.originalname,ext);
            //저장할 파일 이름 형식
            const saveFileName = fileNameExeptExt+Date.now()+ext;
            done(null,saveFileName);
        }
    })
})

//전체 메뉴 조회
app.get("/api/menus",async (req,res)=>{
    try {
        const data = await pool.query("select * from menus");
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message: "전체 메뉴 목록 조회에 실패하였습니다."
        })
    }
})
//하나 조회
app.get("/api/menus/:id",async (req,res)=>{
    try {
        console.log(req.params); //json(key:value)로 받음
        const id =req.params.id;
        //const data = await pool.query("select * from menus");
        const data = await pool.query("select * from menus WHERE id =?",[id]);
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message: "메뉴 조회에 실패했습니다."
        })
    }
})
//메뉴 등록
app.post('/api/menus',upload.single('origin'),async (req,res)=>{
    try {
        console.log(req.file);
        const file_path=req.file.path;
        console.log(req.body);
        const {name,description}=req.body;
        const data=await pool.query(`
            INSERT INTO menus (name,description,image_src) VALUES (?,?,?)
        `,[name,description,file_path]);

        return res.json({
            succese:true,
            message:"메뉴 등록에 성공하였습니다."
        })
    } catch (error) {
        console.log(error);
        return res.json({
            succese:false,
            message:"메뉴 등록에 실패하였습니다."
        })
    }
})
//patch /api/menus/:id -> name, description
app.patch('/api/menus/:id',async (req,res)=>{
    try {
        //req.params :id
        const data =await pool.query(`
        UPDATE menus SET name = ?, description= ? WHERE id =?
        `,[req.body.name,req.body.description,req.params.id]);
        //req.body
        
        return res.json({
            success:true,
            message:"메뉴 수정에 성공하였습니다."
        })
    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message:"메뉴 수정에 실패했습니다."
        })
    }
})
//파일업로드는 무조건 post
//post 이미지 변경 /api/menus/:id/image
app.post('/api/menus/:id/image',upload.single('origin'),async (req,res)=>{
    try {
        console.log(req.file);
        const file_path=req.file.path;
        console.log(req.body);
        // const {name,description}=req.body;
        const data=await pool.query(`
            UPDATE menus SET image_src=? WHERE id=?
        `,[file_path,req.params.id]);

        return res.json({
            succese:true,
            message:"메뉴 수정에 성공하였습니다."
        })
    } catch (error) {
        console.log(error);
        return res.json({
            succese:false,
            message:"메뉴 수정에 실패하였습니다."
        })
    }
})
//delete
app.delete('/api/menus/:id',async (req,res)=>{
    try {
        const data= pool.query(`
            DELETE from menus where id=?
        `,[req.params.id]);
        return res.json({
            success: true,
            message:"메뉴 삭제에 성공하였습니다."
        })

    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message:"메뉴 삭제에 실패하였습니다."
        })
    }
})

//orders
//GET
app.get('/api/orders',async (req,res)=>{
    try {
        //menus_id 를 가져와서 데이터 조회
        //quantity, request_detail -> orders 테이블
        //name, description -> menus 테이블
        //id는 중복이라서 a.id라고 명시
        const data=await pool.query(`
            SELECT a.id, quantity, request_detail,name, description
            from orders as a
            INNER JOIN menus as b
            ON a.menus_id = b.id
            ORDER BY a.id DESC
        `)
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json({
            succese:false,
            message:"주문 전체 조회를 실패하였습니다."
        })
    }
})
//GET 하나만 조회
app.get('/api/orders/:id',async (req,res)=>{
    try {
        const data =await pool.query(`
        SELECT orders.id, quantity, request_detail,name,description
        from orders INNER JOIN menus 
        ON orders.menus_id=menus.id
        WHERE orders.menus_id=?
        `,[req.params.id]);
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message:"주문 조회에 실패하였습니다."
        })
    }
})
//POST
app.post('/api/orders',async (req,res)=>{
    try {
        //menus_id를 넣을 경우
        //외래키이기 때문에 menus 테이블에 존재하는 id를 넣어야 한다.
        const data=await pool.query(`
        INSERT INTO orders (quantity, request_detail,menus_id)
        VALUES (?,?,?)
        `,[req.body.quantity,req.body.request_detail,req.body.menus_id]);
        return res.json({
            success:true,
            message:"주문에 성공하였습니다."
        })
    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message:"주문에 실패하였습니다."
        })
    }
})
//PATCH 주문내역 수정
app.patch('/api/orders/:id',async (req,res)=>{
    try {
        const data =await pool.query(`
            UPDATE orders SET menus_id=?, request_detail=?, quantity=?
            where id=? 
        `,[req.body.menus_id,req.body.request_detail,req.body.quantity,req.params.id]);
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message:"주문 내역 수정에 실패하였습니다."   
        })
    }
})
//DELETE
app.delete('/api/orders/:id',async (req,res)=>{
    try {
        const data= pool.query(`
            DELETE from orders where id=?
        `,[req.params.id]);
        return res.json({
            success: true,
            message:"주문 삭제에 성공하였습니다."
        })

    } catch (error) {
        console.log(error);
        return res.json({
            success:false,
            message:"주문 삭제에 실패하였습니다."
        })
    }
})
app.listen(PORT,()=>console.log(`${PORT} 서버 기동중`));