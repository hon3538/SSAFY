//sum.js와 member.js 모듈을 받아와서 덧셈 출력
const {a,b}=require("./member"); //객체의 멤버들을 비구조화 할당하여 모듈로 가져오기
const sum=require("./sum"); // 함수를 가져오기

console.log(sum(a,b));