//상수는 영문 대문자 snake case를 사용한다
SYMBOLIC_CONSTANTS; 

//생성자는 대문자 camel case
class ConstructorName{

}

//변수, 함수에는 camel case
let dog;
const dogs =[];

//정규표현식은 'r'로 시작
const rDesc=/.*/;

// 함수
function getPropertyName(){

}

//이벤트 핸들러는 'on' 으로 시작
const onClick()=>{};

//반환 값이 볼린인 함수는 'is'로 시작
let isAvailable =false;

//Private 변수명은 '_'로 시작한다
let _privateVariableName;

//값이 변하지 않는 상수는 const, 값이 변하는 변수는 let으로 선언한다
//const 를 let보다 위에 선언한다 (가동성이 좋아짐)
const len =this._array.length;
const len2 =this._array2.length;
let i=0;
let j=0;

//const 와 let은 사용시점에 선언 및 할당을 한다

//키워드, 연산자와 다른 코드 사이에 공백이 있어야한다.
var value;
if(value==1) // x

if (value == 1) { //o
    value = (a + b);
}
