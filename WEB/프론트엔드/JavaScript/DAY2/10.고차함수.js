let bucketList =[
    {id:1, text:"coding", done:true},
    {id:2, text:"eating chicken", done:false},
    {id:3, text:"traveling", done:false }
]


// <li>
// eating chicken
// </li>
//making html tag 

//component 
//can handle datas from frontend

// const result = bucketList.reduce((acc,cur)=>{
//     acc= acc+`
//     <li id=${cur.id}>
//         ${cur.text}
//     </li>
//     `
//     return acc;
// },"")
//console.log(result);
//document.querySelector('body').insertAdjacentHTML('beforeend',result);

//practicing1
// ex) name : "euiseon"

// . has excess to only key, name -> cur.name ==="euison"
// [] has excess to variable, "euiseon" -> cur['name']==="euiseon"

// function getValues(key){
//     const result=bucketList.reduce((acc,cur)=>{

//         acc.push(cur[key]);
//         return acc;
//     },[])
//     return result;
// }
// console.log(getValues('id'));
// console.log(getValues('text'));
// console.log(getValues('done'));

//practicing2
// function removeList(id){
//     const result=bucketList.reduce((acc,cur)=>{
//         if(cur.id!=id)
//             acc.push(cur);
//         return acc;
//     },[])
//     bucketList=result;
//     // bucketList=bucketList.filter(i=>i.id!==2);
// }
// removeList(2);
// console.log(bucketList);

function toggle(id){
    const result = bucketList.reduce((acc,cur)=>{
        if(cur.id===id){
            cur.done=!cur.done;
        }
        acc.push(cur);

        return acc;
    },[])
    bucketList=result;
}
toggle(2);
console.log(bucketList);