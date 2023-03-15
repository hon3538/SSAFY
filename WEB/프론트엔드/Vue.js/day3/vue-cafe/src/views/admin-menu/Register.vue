<template>
  <div>
    <div class="form-wapper">
        <div>메뉴 이름: <input v-model="name"></div>
        <div>메뉴 설명: <input v-model="description"></div>
        <input @change="fileChange" type="file">
        <div v-if="$route.params.id">
            <!-- 수정모드 -->
            <button @click ="update">메뉴 수정하기</button>
            <button @click="updateImage">이미지 수정하기</button>
        </div>
        <button v-else @click="create">메뉴 추가하기</button>
    </div>
    <div class="image-wrapper" v-if="file">
        <img :src="setURL(file)" width="100%">
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
            file:null
        }
    },
    methods:{
        fileChange(e){
            console.log(e);
            console.log(e.target.files);
            this.file=e.target.files[0];
        },
        setURL(file){ //image file을 선택하면 미리보기 기능처럼 보여줌 
            // 임시 URL
            // 미리보기 만들기
            const imageURL = URL.createObjectURL(file);
            console.log(imageURL);
            return imageURL;
        },
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
        async update() {
      // update;
      const result = await api.menus.update(this.$route.params.id, this.name, this.description);
      console.log(result);
      alert(result.data.message);
      this.$router.push(`/admin/menus/${this.$route.params.id}`)
    },

    async updateImage(){
      const result = await api.menus.updateImage(this.$route.params.id,this.file);
      console.log(result);
      alert(result.data.message);
    }
  

    },
    async created(){
            //수정모드 일반모드 구분
            //수정모드인 경우는 this.$route.params.id가 존재
            if(this.$route.params.id){
                this.$store.commit("SET_TITLE","메뉴 수정하기")
                const result =await api.menus.findOne(this.$route.params.id);
                this.name = result.data.name;
                this.description = result.data.description;
            }else{
                this.$store.commit("SET_TITLE","메뉴 추가하기")
            }
        }
}
</script>

<style>

</style>