//javascript 싱글스레드 기반, 병렬동작 불가능
//하나가 끝나야 다음거 처리 like 한줄서기
//a->b->c->d...
//소스 코드의 흐름은 위에서 아래로, 좌에서 우로 진행된다.
//순서가 보장되며, 위의 코드가 오래 걸리면 아래 코드는 진행되지 않는다.


//비동기 통신 등장
//단점 -> 시점 파악이 어렵다.
//비동기 통신에서 힘들었던 시점 문제를 해결기는 방법 모색
//a->c->d
//b->

console.log('1');

//약 1초후에 콜백함수를 실행
setTimeout(() => {
    console.log('2');
}, 1000);
console.log('3');

//1, 3, 2 출력

//setTimeout 동기식으로 만들기
//1. 무한루프 활용
function sleep(delay) {
    //현재시각
    const start = Date.now();
    const limit = start + delay;
    while (Date.now() < limit) { }

}
console.log("빨래");
sleep(3000);
console.log("설거지");

//*2. 콜백함수 활용
//왜 이렇게 하냐 ? 이유 못봄..
setTimeout(() => {
    console.log("첫번째 일");
    setTimeout(() => {
        console.log("두번째일")
    }, 3000)
}, 5000);
//순서대로 출력

console.log("HI");
setTimeout(() => {
    console.log("First");
    setTimeout(() => {
        console.log("Second");
        setTimeout(() => {
            console.log("Third");
        }, 2000)
    }, 1000)
}, 500)
//근데 계속 이렇게 callback함수가 쌓이면 가독성 떨어지고 시점도 찾기 쉽지않음
