<template>
  <div>
    GrandChild
    {{myAge}} {{myName}}
    <button @click="changeAge">나이변경</button>
  </div>
</template>

<script>
export default {
    props:['myAge','myName'],
    methods:{
        changeAge(){
            //자식에서 그냥 바꾸면 부모와 데이터의 불일치가 일어남
            //emit을 사용해서 부모에 값을 전달해야함
            //this.myAge=30000;
            //this.$emit("넘길 키값", 값들...,...,..,..)
            this.$emit("emitTest",30000);
            //부모로 넘기면 부모는 v-on:emitTest 즉, @emitTest 로 받는다.
        }
    }
}
</script>

<style>

</style>