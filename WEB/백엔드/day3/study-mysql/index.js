const express = require("express");
const app = express();
const pool = require("./db/index");
const cors = require("cors");
//app.use 는 전역으로 적용 -> 모든 요청마다 적용
app.use(cors());

const morgan = require('morgan');
app.use(morgan('dev'));

//body에 데이터를 받아오기 위해서는 셋팅이 하나 꼭 필요하다
//json형식의 데이터를 받아오기 위해 필요한 셋팅 -> 이게 빠지면 body의 데이털르 받아올 수 없다
app.use(express.json());

const PORT = 8080;
//jony schema 에 menus 테이블의 정보를 가져와서 

//GET /api/menus
//DB연결할때 -> async/await사용, DB 행동이 비동기기 때문에
//localhost:8080/api/menus 접속해보기
app.get("/api/menus", async (req, res) => {
    try {
        const data = await pool.query("select * from menus");
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json(error);
    }
    //return res.json({"TEST":"OK",TYPE:"GET"}); //요청 잘 받는지 test 용
});
//id 1~10까지 다보고 싶은데 /api/menus/1, /api/menus/2 ..이렇게할 수 없기때문에
//:id로 가변적으로 받아온다
app.get("/api/menus/:id",async(req,res)=>{
    //:로 들어오는 값은
    // console.log(req.params);
    // console.log(req.params.id);
    console.log(req.query);
    try {
       
        const data=await pool.query("select * from menus where menu_id = ?", [req.params.id]);
        return res.json(data[0]);
    } catch (error) {
        console.log(error);
        return res.json(error);
    }
    //return res.json({test:"OK"});
})
//POST /api/menus
app.post("/api/menus", async (req, res) => {
    console.log(req.body);
    //body 안에 menu_name, menu_description을 DB에 쿼리로 날리면 끝
    try {
        //첫번째 방식, ? 부분들은 변수로 넣을 수 있다.
        const data = await pool.query(`INSERT INTO menus ( menu_name, menu_description)
                VALUES(?,?)`, [req.body.menu_name, req.body.menu_description]);
        //body안의 값들을 집어서어서 날린다.
        return res.json(data);

        //두번째 방식 -> 별로 가독성 안 좋아서 첫번째 방식 추천
        // const data = await pool.query(`
        //     INSERT INTO menus (menu_name, menu_description)
        //     VALUES
        //     ("${req.body.menu_name}","${req.body.menu_description}")
        // `);
        // return res.json(data);
    } catch (error) {
        console.log(error);
        return res.json(error);
    }

    // return res.json({"TEST":"OK",TYPE:"GET"});
});


app.listen(PORT, () => { console.log(`${PORT} 서버 기동중`) });