//new Promise(/*executor 함수 */)

//new Promise 객체를 만든 순간부터 pending 상태가 됨
new Promise((resolve,reject)=>{

}) // -> pending

//pending 상태에서 resolve 함수를 실행하면 fullfilled(이행)상태가 된다.
new Promise((resolve,reject)=>{
    resolve(); //fullfilled상태로 변경
})

//pending 상태에서 reject 함수를 실행하면 rejected 상태가 된다.
new Promise((resolve,reject)=>{
    reject(); // rejected 상태로 변경
}) 

//setTimeout -> Promise 형식으로 만들기
//promise화 라고함
function promiseSetTimeout(){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve(1);
        },1000);
    })
}

// //promise 형식은 resolve data 의 경우 then에서 받고
// //reject data는 catch에서 받는다.
// promiseSetTimeout().then(data=>{
//     console.log(data);
// }) // resolve에 있는 인자값을 출력함

// //reject
// function promiseSetTimeout(){
//     return new Promise((resolve,reject)=>{
//         setTimeout(()=>{
//             //resolve(1);
//             reject("요청이 거부되었습니다");
//         },1000);
//     })
// }
// promiseSetTimeout().then(data=>{
//     console.log(data);
// }).catch(error=>{
//     console.log(error);
// })

//프로미스 체인
promiseSetTimeout().then(data=>{
    console.log(data);
    return data+1;
}).then(data=>{
    console.log(data);
    return data+1;
})
//then 을 계속 붙여나가서 chain
