import axios from 'axios'

const request = axios.create({
    baseURL:"https://fakestoreapi.com"
})

export const api={
    shoppingMall:{
        findAll:()=> request.get('/products'),
        findOne:()=> request.get('products/:id')
    }
}