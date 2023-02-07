const myTime =(time,ingrediant)=>{
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve(ingrediant);
        },time)
    })
}

async function sing(){
    let one =await myTime(100,"참깨빵위에 ");
    console.log(one);
    one =await myTime(150,one+"순쇠고기");
    console.log(one);
    one =await myTime(180,"패티");
    console.log(one)
    one =await myTime(200,"두장");
    console.log(one);
    one =await myTime(250,"특별한");
    console.log(one);
    one =await myTime(270,"소스");
    console.log(one);
    one =await myTime(300,"양상추");
    console.log(one);
    one =await myTime(350,"치킨");
    console.log(one);
    one=await myTime(375,"피클");
    console.log(one);
    one=await myTime(400,"양파까지~ ");
    console.log(one);
    two=await myTime(500,"뚜루뚜뚜뚜~");
    console.log(two);
}
//1초후에 참깨빵위에
//2초 후에 순쇠고기 패티 두장
//3초후에 특별한 소스 양상추
//4초후에 치즈 피클 양파까지~