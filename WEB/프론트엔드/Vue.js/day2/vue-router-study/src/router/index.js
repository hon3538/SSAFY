import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'
import MainView from '../views/MainView.vue'
import BoardView from '../views/BoardView.vue'
import AboutView from '../views/AboutView.vue'
import UserDetail from '../views/user/Detail.vue'
import UserList from '../views/user/List.vue'
Vue.use(VueRouter)

const routes = [
  {
    path: '/',
    name: 'home',
    component: HomeView
    // '/'에 오면 component인 HomeView 를 보여주겠다.
  },
  {
    path: '/about',
    name: 'about',
    // route level code-splitting
    // this generates a separate chunk (about.[hash].js) for this route
    // which is lazy-loaded when the route is visited.
    component: () => import(/* webpackChunkName: "about" */ '../views/AboutView.vue')
    //비슷하다. /about에 오면 ../views/AboutView.vue를 보여주겠다
  },
  {
    path:'/board',
    name:'board',
    component:()=>import('../views/BoardView.vue')
  },
  {
    path:'/main',
    name:'main',
    component:()=>import('../views/MainView.vue')
  },
  {
    path:'/user',
    name:'userList',
    component:UserList
  },
  {
    path:'/user/:id',
    name:'userDetail',
    component:UserDetail
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
