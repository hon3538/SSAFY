<template>
  <div>
    ChickenChild {{saltProp}} {{titleProp}}
    <button @click="changeSalt">버튼</button>
  </div>
</template>

<script>
export default {
    props:['saltProp','titleProp'],
    methods:{
        changeSalt(){
            this.$emit('result',20);
        }
    }
}
</script>

<style>

</style>