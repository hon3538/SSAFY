//�迭 �޼ҵ� Array.�Լ�(�ݹ��Լ�)
// addEventListener('click',function(){})

// Array.forEach

const arr=[1,2,3,4];

arr.forEach((value)=>{
    console.log(value);
})

const test = (value) =>{
    console.log(value);
}
arr.forEach(test);

for(let i=0;i<arr.length;i++){
    console.log(arr[i]);
}

//3���� ��� �� ����


const v=[4,3,5,1,6,5];
v.forEach((value)=>{ //Ȧ���� ���
    if(value%2===1){
        console.log(value);
    }
})

const array=[-5,3,4,2,-7,-2,7];
const pplus=[];
//const pplus=new Array(); �� ����
const mminus=[];
array.forEach(i=>{
    if(i<0)
        mminus.push(i);    
    else
        pplus.push(i);
})


