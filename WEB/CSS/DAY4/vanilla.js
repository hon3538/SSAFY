// 순수 javaScript를 vanilla.js 라고 부름(jQuery Library사용없이)

//.ht console로 찍기
const hi=document.querySelector('.hi');
console.log(hi);

//버튼 클릭시 alert("Hello") 출력
const button=document.querySelector("button");
button.addEventListener('click',function(){
    alert("Hello");
})
// body의 background를 gray로 바꾼다.
const body=document.querySelector('body');
body.style.backgroundColor="gray";