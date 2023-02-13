// 시험범위 이전 자바스크립트 내용 + 이번주 자바스크립트 

// JS는 웹을 동적으로 만듦
// JS Runtime - node.js 또는 브라우저

// ECMA Script
// ==두개 vs ===세개

// var, let, const 호이스팅

// 함수 선언식과 표현식

// const 로 선언된 배열의 엘리먼트, 객체의 프로퍼티는 수정 가능

// # 이벤트와 돔조작
// DOM 접근할 땐 document
// querySelector, querySelectorAll
// * querySelector 뿐만 아니라, getElementById, getElementsByClassname 도 있다.
// * 인라인 이벤트 ex) <button onclick="sayHi()">
//   - 추천되는 방식 아님
//   - querySelector 로 DOM 가져와서 addEventListener 메서드 사용하는 방법이 표준
// classList
// keyup, keydown

// # 파싱
// 콜백함수 정의
// * slice, splice
// forEach, map, filter, reduce
//   - for, while 에 비해서 장점 => 원래 있던 배열 보존
// indexOf, concat, push, split

// # 기타
// * 이벤트 버블링 캡쳐링 위임 https://joshua1988.github.io/web-development/javascript/event-propagation-delegation/ 참조
// * HTTP Request Method: GET POST PUT PATCH DELETE
// min.js
// json: 서버와 클라이언트 간 전송되는 데이터 표준

// const info={
//     name:10,
//     family:{
//     "하이":"으응",
//     "띠띠":"또또",
//     "따따":"땅땅"}
// };
// console.log(info.family["띠띠"]);