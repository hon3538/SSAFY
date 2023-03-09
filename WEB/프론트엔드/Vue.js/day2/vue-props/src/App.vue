<template>
  <div id="app">
    <FriedChicken v-bind:saltProp="salt" :titleProp="title"></FriedChicken>
  </div>
</template>

<script>
import FriedChicken from "./components/challenge/FriedChicken.vue"
export default {
  components:{
    FriedChicken
  },
  data(){
    return {
      salt:30,
      title:"치킨은 맛있다"
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
