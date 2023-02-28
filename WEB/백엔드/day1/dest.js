// 객체의 비구조화 할당 복습

const friends ={
    name1 :"철수",
    name2 :"영희",
    run : (word)=> console.log(word,"가자"),
}

// //friends.name1 접근
// const {name1,name2,run}=friends;
// //const {name1:name1,name2:name2,run:run}=friends 와 같음
// console.log(name1);
// console.log(name2);
// run("하하");

//module.exports =내보낼 내용
module.exports = friends;