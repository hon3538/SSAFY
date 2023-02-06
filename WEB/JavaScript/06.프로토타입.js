//프로토타입
//class와 유사한 개념
// 객체의 원형인 prototype을 이용해서 복사와 상속이 가능한 객체를 생성
// 해당 프로토타입에는 객체 정의법.. split, substring, indexOf 다 들어있다.

function Chicken(){
    this.information={
        head : "머리",
        leg:"다리",
    }
}

const b=new Chicken();
const c=new Chicken();

//false
console.log(b.information ===c.information);
//참조형이기 때문에 서로 참조하는 메모리가 다르기 때문에 false

//모든 치킨에 전부 head, leg가 있다
//ex indexOf라는 함수를 호출하는데 전부다 새로 메모리에 할당된다?

//프로토타입 활용

function BBQ(){

}
BBQ.prototype.information={
    head:'머리',
    leg:'다리'
}
const bhc=new BBQ();
const bbbq=new BBQ();

//console.dir(bhc)
//조상 객체를 보는 __proto__
const abc=[0,1,2,3,4];
console.log(abc.__proto__); // Array 객체의 프로토타입
console.log(abc.__proto__.__proto__); // 프로토의 프로토
console.log(abc.__proto__.__proto__.__proto__); //->최상위인 Object
//최상위 객체는 Object객체로 모든 객체들의 부모

function abcd(){

}
console.dir(abcd); //함수
console.dir(abcd.__proto__); // 함수의 프로토 타입
console.dir(abcd.__proto__.__proto__); //Object

//자바스트립트 프로토타입이라며?
//class? 뭐임?

//자바스크립트에서 클래스는 프로토타입을 편하게 사용하기 위한 Syntax sugar
//문법적 설탕 -> 편하게 사용하기 위함