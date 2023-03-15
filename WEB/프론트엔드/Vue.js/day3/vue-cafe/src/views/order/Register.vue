<template>
  <div>
    <div @click="moveDetail(menu.id)" v-for="menu in menus" :key="menu.id"> 
    <div class="menu-container">
        <!-- <img :src="setImage(menu.image_src)"> -->
        <div class="menu-image"
        :style="`background-image:url(${setImage(menu.image_src)})`"
        >
      
        </div>
        <div class="menu-info-wrapper">
            <h2 class="menu-name">{{menu.name}}</h2>
            <p class="menu-description">{{menu.description}}</p>
        </div>
    </div>
</div>
  </div>
</template>

<script>
import {api} from "../../utils/api";
export default {

    data(){
        return {
            name:"",
            description:"",
            file:null,
            menus:[],
            data:{}
        }
    },
    methods:{
        async create(){
           // this.$store.commit("SET_TITLE","메뉴 추가하기");
            console.log(this.name);
            console.log(this.description);
            console.log(this.file);
            if(!this.name||!this.description||!this.file){
                alert("빈값이 있습니다. 내용을 먼저 작성해주세요");
                return;
            }
            const result = await api.menus.create(this.name,this.description,this.file);
            //result.data.success가 true인 경우에만 성공적으로 업로드 된것임
            if(result.data.success===true){
                alert(result.data.message);
                //성공했으니까 메세지 띄우고 라우터 이동
                this.$router.push("/admin/menus");
            }else{
                alert(result.data.message);
            }
        },
        setImage(image_src){
            return `http://13.125.243.79:8080/${image_src}`;
        },
        moveDetail(id){
            this.$router.push(`/orders/${id}`)
        }

    },
    async created(){
            //수정모드 일반모드 구분
            //수정모드인 경우는 this.$route.params.id가 존재
                this.$store.commit("SET_TITLE","메뉴 주문하기")
                const result =await api.menus.findAll();
                console.log(result.data);
                this.menus=result.data;
        }
}
</script>

<style>
.menu-container {
  display: flex;
  align-items: center;
  border-bottom: 3px solid black;
}

.menu-info-wrapper {
  margin: 0 auto;
  text-align: center;
}

.menu-name {
  font-size: 25px;
  font-weight: bold;
}

.menu-description {
  padding-top: 10px;
}
.menu-image {
  background-size: cover;
  background-position: center;
  width: 180px;
  height: 180px;
}
</style>