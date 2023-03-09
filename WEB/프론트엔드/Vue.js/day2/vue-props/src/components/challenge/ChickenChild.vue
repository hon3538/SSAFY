<template>
  <div>
    <div v-if="flag">
        {{salt}} {{title}}
    </div>
    <button @click="dodo">
        클릭
    </button>
  </div>
</template>

<script>
export default {
    props:['salt','title'],
    data(){
        return{
            flag:false,
        }
    },
    methods:{
        dodo(){
            this.flag=true;
        }
    }
}
</script>

<style>

</style>