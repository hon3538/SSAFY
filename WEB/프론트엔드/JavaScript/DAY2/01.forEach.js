//배열 메소드 Array.함수(콜백함수)
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

//3가지 방식 다 같다


const v=[4,3,5,1,6,5];
v.forEach((value)=>{ //홀수만 출력
    if(value%2===1){
        console.log(value);
    }
})

const array=[-5,3,4,2,-7,-2,7];
const pplus=[];
//const pplus=new Array(); 도 가능
const mminus=[];
array.forEach(i=>{
    if(i<0)
        mminus.push(i);    
    else
        pplus.push(i);
})


