const arr=[1,2,3,4,5];

//some �ϳ��� ���Ǹ� �����ص� true ��ȯ
const res1=arr.some(i=> i<0); //false
const res=arr.some(i=> i>4); //true
//arr.some((i)=>{ return i>4;}); �� ����
//���� for������ ����ٸ� �ڵ尡 �����

let flag =true;
for(let i=0;i<arr.length;i++){
    if(arr[i]<0){
        flag=true;
    }else
        flag=false; 
}
//return flag

//every ��� ������ �����ؾ� true ��ȯ
const every1=arr.every(i => i>0); //true
const every2=arr.every(i => i>3); //false


