// *DOM 제어
// Document Object Medel : HTML 문서의 구조적 표현 방법으로 Tree 구조로 표현한다.
// -> WEB browser가 HTML 문서를 읽고, DOM Tree를 생성한다.

// children 속성으로 접근 가능
// • document.children[0] : HTML Element
// • document.children[0].children[1] : Body Element
// • document.children[0].children[1].children[0] : <h1>
// • document.children[0].children[1].children[0].textContent : Text

//*DOM으로 특정 노드를 선택하는 방법
// document.querySelector
// document.querySelectorAll

// *split
// let a ="A|B|C";
// let b=a.split('|');

// *용어정리
// 콜백함수 : 1. 다른 코드의 Argument로 함수 이름을 넘겨주는 함수 2. 소스코드의 직접 호출이 아닌, 이벤트로 인해 호출되는 함수
// 이벤트 핸들러 : 이벤트 발생시 호출되는 함수, "콜백 함수" 중 용도를 더 명확하게 나타낸 더 작은 범위의 용어이다.
// 이벤트 리스너 : 이벤트가 발생하는 지 감지하여, 예약된 이벤트 핸들러를 호출해주는 객체

// Math.random() 메서드: 0< <1  사이 소수점 랜덤 값 생성

// *Element 생성
// const div=document.querySeclector('div');
// const btn=document.createElement('button');
// div.append(btn); -> 자식 속성으로 들어가며 마지막에 추가됨.

//*속성 추가하기
//btn.setAttribute("id","BTS");

//*change 와 Key event -> input에서 값이 바뀔 때 발생하는 이벤트, select에서도ㅗ 사용가능.
//const input = document.querySelector('input');
//const div = document.querySelector('div');
//input.addEventListener('change',functionn=>{}); 

//*classList
//classList.add("class name"; -> class 를 추가하며 이미 추가된 속성값이라면, 이를 무시한다.
//classList.remove("class name"); -> 역시 이미 없다면 무시
//classList.toggle("class name");
//classList.contains("class name"); -> 특정 class가 있으면 true, 없으면 false 리턴
//classList.replace(old,new); -> 특정 클래스를 새로운 클래스로 교체

//*CDN : 빠른 해외 웹사이트를 접속하기 위한 기술, 
//xxx.min.js : 가독성을 포기하고, 공백/ 줄바꿈을 제거하여 파일 용량을 줄인 파일-> 변경할 예정이 없는 Library에 사용한다.

// *Parsing
// 종류                          C++                                 JavaScript                           비고
// index 검색                   find                                  indexOf                        a.indexOf(“BBQ”);    -> 있는 경우 시작 index, 없을 경우 -1 리턴 ++ 대소문자 구분 필요
// 구간 자르기                 substr                                  substr                          a.substr(3, 2);     
// 문자열 붙이기               + 연산자                                + 연산자                      let a = "ABC＂ + "BBQ"
// 특정 위치 문자열 추가        insert                                  없음                            직접 구현 필요       -> 문자열을 추가할 index 기준 앞, 뒤 문자열로 쪼개고 a+"추가할 문자열"+b 로 리턴되는 함수를 구현
// 특정 위치 문자열 제거        erase                                   없음                            직접 구현 필요
// replace                      없음                                 replace                    a.replace(/문자열/g, “MC”);
// split                        없음                                   split                          a.split(‘|’);
// 문자열을 숫자로              stoi                                    Number                          Number(“ABC”);
// 숫자를 문자열로            to_string                                 String                          String(“123”)


//*객체 생성방식
//1. 객체 리터럴 방식
//const ssafy = {
//     name: "aaa",
//     study:function(){}
//     coding(){},
// }

//2.생성자 함수에 의한 객체생성
// const ssafy =new Onject();
// ssafy.name="aaa";
// ssafy.study=function(){};

//*객체로 만든 함수 호출 방법 두 가지
//1. ssafy.study(); -> 객체.키값
//2. ssafy['coding'] -> 객체['키값']

//객체는 따로 선언없이 속성을 추가할 수 있다.
// ssafy.new="NEW";

//*prototype -> 조상을 나타내며 활용하면 중복 최소화 가능
//function chicken(){ this.information={...}; }
// const a=new chicken();
// const b=new chinken(); 
// a.information === b.information -> false
//일반 함수의 경우 두 객체가 다른 메모리로 할당됨

//prototype 활용
// function chicken(){}
//chicken.prototype.information={...} -> prototype은 객체의 원형을 의미함, 즉 설계도임..
//즉 위의 a, b는 prototype의 복제품이므로, prototype의 속성을 제어하면 같은 메모리로 사용가능
//근데 굳이..?

//*class
//class Human{
//     constuctor(name){
//         this.name=name;
//     }
// }
// sayName(){
    
// }

// class here extends Human{
//     constructor(name){
//         super(name,skill);
//         this.name=name;
//         this.skill=skill;
//     }
// }

//*this 로 객체 접근할 때 유의사항.. 접근이 안 되는 이슈발생
//clickEvent(){
// this.Element.addEventListener('click',function(e)){ 
//     console.log(e);
//     console.log(this);  this와 e는 가리키는 곳이 같은데 error 뜸
// }
// }

//해결법 두 가지
//clickEvent(){
//  const THIS=this; -> 1. 따로 변수로 선언하여 사용
// this.Element.addEventListener('click',function(e)){ 
//     console.log(e);
//     console.log(THIS);  this와 e는 가리키는 곳이 같은데 error 뜸
// }
// 2. 화살표 함수 쓰면 this가 본인객체가 아닌 본인보다 상위객체를 가리킴
