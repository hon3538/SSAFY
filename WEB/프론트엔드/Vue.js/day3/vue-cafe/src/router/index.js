import Vue from 'vue'
import VueRouter from 'vue-router'
import HomeView from '../views/HomeView.vue'

import AdminMenuMain from '../views/admin-menu/Main.vue'
import AdminMenuList from '../views/admin-menu/List.vue'
import AdminMenuDetail from '../views/admin-menu/Detail.vue'
import AdminMenuRegister from '../views/admin-menu/Register.vue'

Vue.use(VueRouter)

const routes = [
  //order

  //Admin
  {
    path:'/admin/home',
    component:AdminMenuMain
  },
  {
    path:'/admin/menus',
    component:AdminMenuList
  },
  {
    path:'/admin/menus/register',
    component:AdminMenuRegister
  },
  {
    path:'/admin/menus/:id',
    component:AdminMenuDetail
  },
  {
    //수정할때
    path:'/admin/menus/register/:id',
    component:AdminMenuRegister
  },
]

const router = new VueRouter({
  mode: 'history',
  base: process.env.BASE_URL,
  routes
})

export default router
