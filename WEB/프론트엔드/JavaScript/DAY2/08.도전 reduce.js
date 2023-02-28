const arr =[1,2,3,4,5,6,7,8,9,10];
const res1 = arr.filter(i=>{i%2==0});
const res2 =res1.map(i=>{ i*10});

// const result1=arr.filter(i=>i%2===0).map(i=>i*10);

const res3 = arr.filter(i=>{})

//reduce
const result2=arr.reduce((acc,cur)=>{
    if(cur%2===0){acc.push(cur*10);}

    return acc;
},[])