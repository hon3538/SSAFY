//winston -> node의 대표적인 로그 라이브러리
//winston-daily-rotate-file ->로그 관리 라이브러리
const winston =require('winston');
const {format} = winston;
//winston.format.combine
const {combine} =format;

require('winston-daily-rotate-file');
const transport = new winston.transports.DailyRotateFile({
    level:'info', //level이 info까지므로 debug는 저장하지 않음
    //저장할 파일이름
    filename:"./logs/%DATE%.log",
    //날짜 형식
    dataPattern: "YYYY-MM-DD-HH",
    zipppedArchive:true,
    //파일의 최대 크기
    maxSize:"20m",
    //보관할 최대 로그 수
    maxFiles:"1d"
})

const logger = winston.createLogger({
    transports:[transport]
})
module.exports=logger;
