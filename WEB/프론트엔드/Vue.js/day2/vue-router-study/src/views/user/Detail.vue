<template>
    <div>
        {{$route.params.id}}번 디테일입니다.
    </div>
</template>

<script>
export default {
    created(){
        //this.$router.push
        //$router 는 라우터 기능이 들어가있고
        console.log(this.$router);
        //$route는 라우터 정보가 들어가있다
        console.log(this.$route);
        console.log(this.$route.params.id);
        console.log(this.$route.query['page']);
        //frontend user/7
        //this.$route.params.id -> 그대로 axios 달아서 보낸다

        //backend /api/user/7
        
    }
}
</script>

<style>

</style>