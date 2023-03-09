<template>
  <div id="app">
    <nav>
      <!-- a태그로 이동하면 깜빡임 발생
        router-link는 내부적으로 이동하기 때문에 깜빡임 x
       -->
      <router-link to="/">Home</router-link> |
      <router-link to="/Main">Main</router-link> |
      <router-link to="/about">About</router-link> |
      <router-link to="/Board">Board</router-link>
      <!-- methods 로 이동 -->
      <button v-on:click="moveToRouter">게시판 이동</button>
    </nav>
    <router-view/>
  </div>
</template>
<script>
  export default{
    methods:{
      moveToRouter(){
        //라우터이동
        this.$router.push("/Board");
      }
    }
  }
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
