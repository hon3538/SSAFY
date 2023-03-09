<template>
  <div>
    Child
    {{myAgeProp}} {{myNameProp}}
    <GrandChild 
    :myAge="myAgeProp" 
    :myName="myNameProp"
    @emitTest="test"></GrandChild>
  </div>
</template>

<script>
import GrandChild from "./GrandChild.vue"
export default {
    components:{
        GrandChild,
    },
    props:['myAgeProp','myNameProp'],
    methods:{
        test(age){
            this.$emit("lastEmit",age);
        }
    }
}
</script>

<style>

</style>