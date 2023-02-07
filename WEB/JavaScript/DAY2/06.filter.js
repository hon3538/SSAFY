const array =[3,5,4,2,];

//its useful to get values in specific condition
const filteredArray = array.filter(data =>data >3);

//Challenge! utilizing filter
const bucketList=[
    {
        id:1,
        text:"Body-profile",
        done:false,
    },
    {
        id:2,
        text: "eating chicken",
        done: true,
    },
    {
        id:3,
        text:"getin SSAFY",
        done:true,
    }
]

//get Objects with done:false
const arr=bucketList.filter(i=>i.done===false);
console.log(arr);