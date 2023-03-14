import axios from 'axios';

//request 로 요청하게 되면 기본적으로 앞에 baseURL이 들어간채로 시작
const request =axios.create({
    baseURL:"https://jsonplaceholder.typicode.com"
})

export const api={
    jsonplaceholder:{
        findAll:() => request.get("/todos"),
        findOne:(id)=>request.get(`/todos/${id}`)
    }
}
