// promisechain 

function promiseSetTimeout(){
    return new Promise((resolve,reject)=>{
        setTimeout(()=>{
            resolve("");
        },3000)
    })
}

promiseSetTimeout().then(data=>{
    return data+"����������";
}).then(data=>{
    console.log(data);
    return data+"������ ��Ƽ 2��";
}).then(data=>{
    console.log(data);
    return data+"Ư���� �ҽ� �����";
}).then(data=>{
    console.log(data);
    return data+"ġ�� ��Ŭ ���ı���";
})

//������ 3�ʴ����� �����°� �ƴ϶� 3�ʵڿ� �� ����
// promiseSetTimeout().then(data=>{
//     promiseSetTimeout().then(data=>{
//         ...
//     })
// })