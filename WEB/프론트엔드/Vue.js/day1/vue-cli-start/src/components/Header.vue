
<template>
    <div>
        <h1>Header</h1>
        <Search>
            <!-- 여기에 뭐 넣는 것은 동작안함 -->
        </Search>
        <Navigation></Navigation>
    </div>
</template>

<script>
//1. import
//2. components 안에 등록
import Search from "./Search.vue";
import Navigation from "./Navigation.vue";
export default {
    //<template> html 파트가 들어가는 곳. template안에는 딱 하나로만 감싸야한다.
    //<script> -> data, 라이프 사이클 .. 외부로부터 컴포넌트가져오기
    //<style> -> css 정의
    components:{
        Search,
        Navigation
    }
}
</script>

<style>

</style>