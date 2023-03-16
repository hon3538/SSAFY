<template>
<div>
  <router-link to="/orders/register">
</router-link>
<div v-for="order in orders" :key="order.id"> 
    <div class="order-container">
      <div># {{order.id}} </div>
        <div class="order-info-wrapper">
            <h2 class="order-name">{{order.name}}</h2>
            <p class="order-description">{{order.description}}</p>
        </div>
        <div>
          <div>수량 : {{order.quantity}}</div>
          <button @click="Delete(order.id)" style="color:white; background-color:red">delete</button>
        </div>
          
    </div>
</div>
</div>
</template>

<script>
import {api} from "../../utils/api"

export default {
    data(){
      return {
        orders:[]
      }  
    },
    async created(){
        this.$store.commit("SET_TITLE","전체 주문 목록");
        const result = await api.orders.findAll();
        this.orders=result.data;
        console.log(result.data);
    },
    methods:{
        setImage(image_src){
            //console.log(image_src);
            return `http://13.125.243.79:8080/${image_src}`;
        },
        moveDetail(id){
            this.$router.push(`/orders/${id}`)
        },
        async Delete(id){
           const result = await api.orders.delete(id);
           this.$router.go(0);
           console.log(result);
        }
    }
}
</script>

<style>
.order-container {
  display: flex;
  align-items: center;
  border-bottom: 3px solid black;
  padding:0 20px;
}

.order-info-wrapper {
  margin: 0 auto;
  text-align: center;
}

.order-name {
  font-size: 25px;
  font-weight: bold;
}

.order-description {
  padding-top: 10px;
}
.order-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
</style>