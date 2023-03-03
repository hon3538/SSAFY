const express =require("express");
const app = express();

const PORT=8080;
const multer =require("multer");
const upload =multer({
    //저장경로 설정
    storage:multer.diskStorage({
        //public 경로에 저장
        destination:(req,file,done)=>{
            done(null,"public/")
        },
        //저장할 파일 이름
        filename:(req,file,done)=>{
            done(null,file.originalname)
        }
    }),
    //limits:{fileSize: 5*1024*1024},
});

const cors =require("cors");
app.use(cors());

const morgan = require("morgan");
app.use(morgan("dev"));
app.use(express.json());

//정적 서비스
// /public 라우터로 오게되면 public static 폴더를 보여준다
app.use("/static", express.static("public"));

//file 업로드는 무조건 POST
// 미들웨어란 ? 
// 아래 내용을 수행하기 전에 무조건 ap.use를 거쳐간다.
//전역적용 app.use 부분 적용
// /api/file로 요청이 오면 콜백함수를 실행하기 전에 upload.single('flie')을 먼저 거친다는 의미
// client 의 form data에서 key 값이 upload.single('key') 안에 있는 값이랑 맞춰줘야함
app.post("/api/file",upload.single('file'),(req,res)=>{
    console.log(req.files);
    console.log(req.file);
    return res.json({test:"OK"});
})


app.listen(PORT,()=>console.log(`${PORT} 서버 기동중`));

