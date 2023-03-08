<template>
  <div id="app">
    <!-- App.vue에 컴포넌트를 가져와서 넣기를 해볼 예정  
      Header라는 컴포넌트를 만들어서 넣을 예정
    -->
    <Header></Header>
    <Main></Main>
    <!-- <Search></Search> -->

    <!-- <nav>
      <router-link to="/">Home</router-link> |
      <router-link to="/about">About</router-link>
    </nav>
    <h1>ㅋㅋㅋㅋ</h1>-->
    <!-- App.vue 최상위 -->
    <!-- router/index.js 에 있는 내용들을 보여준다. -->
    <!-- <router-view/>  -->
  </div>
</template>
<script>
//import 변수 from "위치"
//컴포넌트 가져오기
//1. import로 가져오기
//2. components:{} 안에 등록하기
import Header from "./components/Header.vue";
import Main from "./components/Main.vue";
//import Search from "./components/Search.vue"
export default ({
  components:{
    //Header:Header
    Header,
    Main
    //Search
  }
})
</script>

<style>
#app {
  font-family: Avenir, Helvetica, Arial, sans-serif;
  -webkit-font-smoothing: antialiased;
  -moz-osx-font-smoothing: grayscale;
  text-align: center;
  color: #2c3e50;
}

nav {
  padding: 30px;
}

nav a {
  font-weight: bold;
  color: #2c3e50;
}

nav a.router-link-exact-active {
  color: #42b983;
}
</style>
