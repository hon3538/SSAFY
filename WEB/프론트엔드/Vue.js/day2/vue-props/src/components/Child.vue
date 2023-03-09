<template>
  <div>
    Child
    {{myNameProp}} {{myAgeProp}}
    <!-- : 과 vi-bind: 이 같다, : 이 없다면 그냥 문자열을 넘긴다
      -->
    <GrandChild name="Child" :Age="myAgeProp"></GrandChild>
  </div>
</template>

<script>
import GrandChild from './GrandChild.vue';
export default {

    components:{
        GrandChild
    },
    //부모로부터 데이터를 넘겨 받아서 등록하기
    props: ["myNameProp","myAgeProp"]
}
</script>

<style>

</style>