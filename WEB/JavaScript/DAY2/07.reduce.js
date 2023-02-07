// map, filter -> array return
// reduce -> can return anything (string, array etc.)
// map, filter also can be made wite reduce

const array = [1, 2, 3, 4, 5];

// reduce without vs with 'initial value' of acc

//mainly with initial

//acc is accumulator
//put values in acc
//cur is current value

// if you skip initial value
// the first(index==1) cur value is put into acc
// const result = array.reduce((acc,cur)=>{
//     console.log(cur);
//     //console.log(acc);
// })

// //initial value
// //array ok, string ok, object ok...
// const result2=array.reduce((acc,cur)=>{
//     console.log(cur);
// },[])

//example for accumulator
const sum = array.reduce((acc, cur) => {
    console.log(acc);
    return acc + cur; // this return value get in acc
}, 0)

//only put values picked
const filteredArray = array.reduce((arr, cur) => {
    if (cur === 2) {
        //to use array function
        //set init value
        acc.push(cur);
    }
    return acc;
}, [])

const arr = [1, 2, 3, 4, 5];

//map using reduce
const arr_result1 = arr.reduce((acc, cur) => {
    const data = cur * cur;
    acc.push(data);
    return acc;
}, [])

//filter using reduce
const arr_reduce2 = arr.reduce((acc, cur) => {
    if (cur > 2) {
        acc.push(cur);
    }
    return acc;
}, [])

//making like DAT
//get repeat count
const p = ["as", "sd", "sd", "wer"];
const pRes = p.reduce((acc, cur) => {
    //if right
    if (acc[cur]) {
        acc[cur] = acc[cur] + 1;
    } else {
        //init value
        arr[cur] = 1;
    }
    return acc;
}, [])

// const increment = (input) => input + 1;
// const decrement = (input) => input -1;
// const squared = input => input* input;
// const half = input => input/2;

// const initValue = 1;
// const pipeLine = [increment, decrement, increment, increment, decrement, squared, squared, half, increment];
// const result = pipeLine.reduce((acc, cur) => cur(acc), initValue);
// console.log(result);

//challenge! utilizing reduce
//odd, even count
const arr2 = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13];
const res = arr2.reduce((acc, cur) => {
    const val = cur % 2;
    if (acc[val]) { //if no, return null
        //no even values, so init with 1
        acc[val] += 1;
    } else {
        acc[val] = 1;
    }
    return acc;
}, [])




