// promise object를 손쉽게 사용하기 위한 -> async/await

function eat() {
    return new Promise((resolve, reject) => {
        setTimeout(function () {
            resolve("먹어");
        }, 2000)
    });
}

//이러면 또 무한히 많아짐
// eat().then짐
//     //또다른 요청
//     eat().then(()=>{

//     })
// }
async function wait() {
    console.log("기다려!!")

    //await를 수행할때까지 대기 ->동기처럼 동작
    const data = await eat();
    console.log(data);
    console.log("잘했어!!");
}
wait();

// async/await에서 .catch 대신 사용하는 것
async function wait() {
    try {
        console.log("기다려!!")

        //await를 수행할때까지 대기 ->동기처럼 동작
        const data = await eat();
        console.log(data);
        console.log("잘했어!!");
        //reject가 잡힌다.
    }catch(error){
        console.log(error);
    }
}