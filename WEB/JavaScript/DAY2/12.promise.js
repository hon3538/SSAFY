//new Promise(/*executor �Լ� */)

//new Promise ��ü�� ���� �������� pending ���°� ��
new Promise((resolve,reject)=>{

}) // -> pending

//pending ���¿��� resolve �Լ��� �����ϸ� fullfilled(����)���°� �ȴ�.
new Promise((resolve,reject)=>{
    resolve(); //fullfilled���·� ����
})

//pending ���¿��� reject �Լ��� �����ϸ� rejected ���°� �ȴ�.
new Promise((resolve,reject)=>{
    reject(); // rejected ���·� ����
}) 

//setTimeout -> Promise �������� �����
//promiseȭ �����
function promiseSetTimeout(){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve(1);
        },1000);
    })
}

// //promise ������ resolve data �� ��� then���� �ް�
// //reject data�� catch���� �޴´�.
// promiseSetTimeout().then(data=>{
//     console.log(data);
// }) // resolve�� �ִ� ���ڰ��� �����

// //reject
// function promiseSetTimeout(){
//     return new Promise((resolve,reject)=>{
//         setTimeout(()=>{
//             //resolve(1);
//             reject("��û�� �źεǾ����ϴ�");
//         },1000);
//     })
// }
// promiseSetTimeout().then(data=>{
//     console.log(data);
// }).catch(error=>{
//     console.log(error);
// })

//���ι̽� ü��
promiseSetTimeout().then(data=>{
    console.log(data);
    return data+1;
}).then(data=>{
    console.log(data);
    return data+1;
})
//then �� ��� �ٿ������� chain
