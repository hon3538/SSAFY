const arr=[1,2,3,4,5];

//some 하나의 조건만 만족해도 true 반환
const res1=arr.some(i=> i<0); //false
const res=arr.some(i=> i>4); //true
//arr.some((i)=>{ return i>4;}); 와 같음
//위를 for문으로 만든다면 코드가 길어짐

let flag =true;
for(let i=0;i<arr.length;i++){
    if(arr[i]<0){
        flag=true;
    }else
        flag=false; 
}
//return flag

//every 모든 조건을 만족해야 true 반환
const every1=arr.every(i => i>0); //true
const every2=arr.every(i => i>3); //false


