<template>
  <div>
    Child
    <div>이름: {{$store.state.name}}</div>
    <div>나이: {{$store.state.age}}</div>
    <grandChild></grandChild>
  </div>
</template>

<script>
import grandChild from './grandChild.vue';
export default {
    components:{
        grandChild,
    }
}
</script>

<style>

</style>