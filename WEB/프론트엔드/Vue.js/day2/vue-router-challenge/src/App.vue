<template>
  <div id="app">
    <nav>
      <router-link to="/">Home</router-link> |
      <router-link to="/about">About</router-link>
    </nav>
    <div>
    <h1>라우터를 이동하는 방법</h1>
    <div v-for="li in arr" :key=li>
        <button v-on:click="setRouter(li)">라우터 {{li}}로 이동</button>
    </div>
    </div>

  </div>
</template>
<script>
export default {
    data(){
        return {
            arr:[1,2,3,4,5],
        }
    },
    methods:{
        setRouter(li){
            this.$router.push(`/Todo/${li}`);
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
