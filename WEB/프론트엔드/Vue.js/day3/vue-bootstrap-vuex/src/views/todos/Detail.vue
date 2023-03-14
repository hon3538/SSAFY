<template>
  <div>
    <div>제목 : {{data.title}}</div>
  </div>
</template>

<script>
import {api} from '../../utils/api';
export default {
    data(){
        return {
            data:{}
        }
    },
    async created(){
        //로딩 활성화 
        this.$store.commit("SET_LOADING",true);
        //this.$route.params.id
        const result = await api.jsonplaceholder.findOne(this.$route.params.id);
        console.log(result);
        this.data=result.data;
        this.$store.commit("SET_LOADING",false);
    }
}
</script>

<style>

</style>