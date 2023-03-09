<template>
  <div>
    FriedChicken {{saltProp}} {{titleProp}}
    <ChickenChild :saltProp="saltProp" :titleProp="titleProp"
    @result="last"></ChickenChild>
  </div>
</template>

<script>
import ChickenChild from "./ChickenChild.vue"
export default {
    components:{
        ChickenChild
    },
    props:['saltProp','titleProp'],
    methods:{
        last(salt){
            this.$emit('result',salt)
        }
    }
}
</script>

<style>

</style>