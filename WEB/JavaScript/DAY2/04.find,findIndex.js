const arr=[1,2,3,4,5];
const inventory=[     //객체 배열
    {name: "A", quantity:1},
    {name: "B", quantity:2},
    {name: "C", quantity:3}
]
//find -> 해당하는 배열의 (첫번째)값을 가져온다. 
const result = arr.find(element=> element>3);

//name이 B인 배열의 값을 가져온다, 해당하는 속성을 가진 객체를 가지고옴
const result2 =inventory.find(li=>li.name==="B");

//findIndex -> 해당하는 index를 가져온다.
const result3= inventory.findIndex(li=>li.name==="B");



//도전! 닭다리를 찾아라
const chicken=[
    {name:"머리", quantity:1},
    {name:"날개", quantity:2},
    {name:"닭다리", quantity:2},
    {name:"닭가슴살", quantity:1},
    {name:"닭발", quantity:2}
]
const legs= chicken.find(i=>i.name==="닭다리");
const legsIndex=chicken.findIndex(i=>i.name==="닭다리");
console.log(`
    ${legs} ${legsIndex}`);

console.log(legs);


