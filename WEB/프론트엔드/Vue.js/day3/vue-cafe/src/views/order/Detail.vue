<template>
  <div>
    <div class="form-wapper">
      <div><h2>{{data.name}}</h2></div>
      <div>{{data.description}}</div>
      <div class="image-wrapper">
        <img :src="setImage(data.image_src)" width="100%">
      </div>
        <div> 주문 수량: <input v-model="quantity"></div>
        <button  @click="create">주문목록에 추가하기</button>
    </div>
  </div>
</template>

<script>
import {api} from "../../utils/api";
export default {

    data(){
        return {
            id:"",
            quantity:"",
            description:"",
            data:{}
        }
    },
    methods:{
        async create(){
           // this.$store.commit("SET_TITLE","메뉴 추가하기");
            console.log(this.data.id);
            console.log(this.data.quantity);
            console.log(this.data.description);
            if(!this.quantity){
                alert("빈값이 있습니다. 내용을 먼저 작성해주세요");
                return;
            }
            const result = await api.orders.create(this.data.id,this.quantity,this.data.description);
            //result.data.success가 true인 경우에만 성공적으로 업로드 된것임
            if(result.data.success===true){
                alert(result.data.message);
                //성공했으니까 메세지 띄우고 라우터 이동
                this.$router.push("/orders/register");
            }else{
                alert(result.data.message);
            }
        },
    setImage(image_src){
            //console.log(image_src);
            return `http://13.125.243.79:8080/${image_src}`;
    },
    },
    async created(){
            //수정모드 일반모드 구분
            //수정모드인 경우는 this.$route.params.id가 존재
            const result =await api.menus.findOne(this.$route.params.id);
            console.log(result.data[0]);
            this.data=result.data[0];
            this.$store.commit("SET_TITLE","메뉴 주문하기");
            
    }
}
</script>

<style>

</style>