<template>
  <div>
    <div v-for="list in lists" :key="list.id">{{list.title}}</div>
  </div>
</template>

<script>
import {api} from '../../utils/api'
export default {
    data(){
        return{
            lists:[],
        }
    },
    async created(){
        //가져오고 있다
        this.$store.commit("SET_LOADING",true);
        const result = await api.shoppingMall.findAll();
        this.lists=result.data;
        console.log(result.data);
        this.$store.commit("SET_LOADING",false);
    }
}
</script>

<style>

</style>