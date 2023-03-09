<template>
  <div>
    <h1>라우터를 이동하는 방법</h1>
    <div v-for="li in arr" :key=li>
        <button v-on:click="setRouter">라우터 {{li}}로 이동</button>
    </div>
  </div>
</template>

<script>
export default {
    data(){
        return {
            arr:[1,2,3,4,5],
        }
    },
    methods:{
        setRouter(){
            this.$router.push(`/Todo/${li}`);
        }
    }
}
</script>

<style>

</style>