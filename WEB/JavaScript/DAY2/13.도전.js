// promisechain 

function promiseSetTimeout(){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("");
        },3000)
    })
}

promiseSetTimeout().then(data=>{
    return data+"참깨빵위에";
}).then(data=>{
    console.log(data);
    return data+"순쇠고기 패티 2장";
}).then(data=>{
    console.log(data);
    return data+"특별한 소스 양상추";
}).then(data=>{
    console.log(data);
    return data+"치즈 피클 양파까지";
})

//문제는 3초단위로 나오는게 아니라 3초뒤에 한 번에
// promiseSetTimeout().then(data=>{
//     promiseSetTimeout().then(data=>{
//         ...
//     })
// })