import Vue from 'vue'
import App from './App.vue'
import router from './router'
//import router from './router/index'
//index가 원래 있는데 생략되어 있다.
import store from './store'

Vue.config.productionTip = false

new Vue({
  //router:router -> key와 value가 같기 때문에 아래와 같이 생략하였다.
  router,
  store,
  render: h => h(App)
}).$mount('#app')
