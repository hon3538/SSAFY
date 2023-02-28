// querySelector는 해당 조건에 만족하는 맨 첫번째를 가져온다
// querySelectorAll은 해당 조건에 만족하는 전부를 배열형태로 가져온다.(유사배열)
// const thumbs= document.querySelectorAll(".thumb-image>img");->thumb-image 클래스의 img 다가져옴
// const a=document.querySelectionAll("div") -> div 다 가져옴 ㅋ

// for(let i=0;i<thumbs.length;i++){
//     console.log(thumbs[i]);
// }
// console.log(thumbs[0]);

//도전 영화정보 수집하기
//1. 차트에 표시된 모든 영화 제목을 array로 저장한다.
//2. 모든 영화 제목들을 * 로 모자이크 처리한다.
//3. 모든 영화의 예매율을 30% 올려준다.(split)

const names=document.querySelectorAll(".title");
for(let i=0;i<names.length;i++){
    names[i].textContent="*";
}

const bookRates=document.querySelectorAll(".percent>span");
for(let i=0;i<bookRates.length;i++){
    let pcnt= bookRates[i].textContent.split("%")[0];
    bookRates[i].textContent=Number(pcnt)+30+"%";
}