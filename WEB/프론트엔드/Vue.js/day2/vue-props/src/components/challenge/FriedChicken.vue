<template>
  <div> 
    <ChickenChild :salt="saltProp" :title="titleProp"></ChickenChild>
  </div>
</template>

<script>
import ChickenChild from "./ChickenChild.vue"
export default {
    components:{
        ChickenChild
    },
    props:['saltProp','titleProp']
}
</script>

<style>

</style>