import Vue from 'vue'
import Vuex from 'vuex'

Vue.use(Vuex)

export default new Vuex.Store({
  state: {
    title:"SSAFY-CAFE",
    DOMAIN:"http://localhost:8080",
  },
  getters: {
  },
  mutations: {
    SET_TITLE(state,data){
      state.title=data;
    }
  },
  actions: {
  },
  modules: {
  }
})
