//nagative meaning -> false
//undefined, null, 0, ''(empty string), false
console.log(!undefined); //true
console.log(!!undefined); //false

console.log(!null); // true
console.log(!!null); // false

console.log(!''); //true

//positive -> except above
console.log(!"0"); //false
console.log(!!"0"); //true

//destructuring -> extract value from Object, and make it variable or constant

const array =[1,2];
const [one,two]=array;
console.log(one,two);


const abc={
    name:"chicken",
    type:"crunchy"
}

//abc.name abc['name']
// key of object declare

const {name, type}=abc;
console.log(name, type);


//Spread is like jam, 
const square ={
    width:200,
    hegith:200,
}
//Spread of object
const colorSquare ={
    ...square,
    color:'red'
}

//Rpread of array
const catTypeAnimal =['cat','tiger'];
const dogTypeAnimal =['dog','wolf'];
const allTypeAnimal =[...catTypeAnimal,...dogTypeAnimal,'biber'];
console.log(allTypeAnimal);

//Rest of Object
const chicken ={
    stype:"spicy",
    drumstick:2,
    wing:2,
}
const {stype, ...another}=chicken;
console.log(stype);
console.log(anoter);

//Rest of array
const numberArray=[0,1,2,3,4];
const [first, second, ...other] =numberArray;
console.log(first);
console.log(second);
console.log(other);