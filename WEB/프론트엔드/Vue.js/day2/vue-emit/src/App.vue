<template>
  <div id="app">
    <!-- <Child :myAgeProp="myAge" :myNameProp="myName"
    @lastEmit="last"></Child> -->

    <FriedChicken :saltProp="salt" :titleProp="title"
    @result="lastEmit"></FriedChicken>
  </div>
</template>
<script>
// import Child from "./components/Chlid.vue"
import FriedChicken from "./components/challenge/FriedChicken.vue"
export default{
  components:{
    FriedChicken,
  },
  data(){
    return {
      // myAge:30,
      // myName:"의선",
      salt:30,
      title:"치킨은 맛있다"
    }
  },
  methods:{
    last(age){
      //자식에서 변경한 값을 emit으로 전달전달해서 
      //App에서 원본데이터를 한번에 바꿔준다.
      this.myAge=age;
    },
    lastEmit(salt){
      this.salt=salt;
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
