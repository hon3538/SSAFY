<template>
    <div>
        <!-- template안에는 크게 하나의 tag 만 들어간다 
            component라는 것이 원래 하나의 구성요소를 의미하기 때문에
            그 의미를 해치므로 태그를 여러개 만드는 것을 막아놨다.
        -->
        <h1>HEADER</h1>
        <Search></Search>
    </div>
</template>
<script>
//template -> HTML 형식의 태그가 들어간다
    //script -> 데이터 설정..methods.. 외부 컴포넌트 가져오기
    //style -> css 설정
import Search from "./Search";
export default {

    components:{
        Search
    }
}
</script>

<style>

</style>