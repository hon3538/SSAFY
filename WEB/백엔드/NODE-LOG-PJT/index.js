//로그의 레벨 7
//error, warn, info, http, verbose, debug, silly
//error, warn, info, debug 를 주로 쓰는듯
//error -> 에러 기록
//warn -> 에러는 아니지만 유의할 내용
//info -> 내용
//debug ->상세한 데이터들
const express=require('express');
const app =express();
const logger=require('./utils/log');
const morgan=require('morgan');
app.use(morgan('dev'));
const PORT =8080;

//원격 로그 수집 시스템 (elastic stack)
//여러군데 모여있는 로그를 한군데서 조회하고 싶은 경우

app.get("/api/logs",(req,res)=>{
    logger.error("error 메세지");
    logger.warn("warn 메세지");
    logger.info("info 메세지");
    // api/logs 에 들어가면 위 세 메세지는 logs에 저장이 되는데
    // debug는 저장이 안 되어 있음
    // 이유는 winston 셋팅에서 level을 info로 한정했기 때문
    logger.debug("debug 메세지");
    return res.json({
        test:"OK"
    })
})
app.listen(PORT,()=>console.log(`${PORT} 서버 기동중`));