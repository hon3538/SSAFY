<template>
  <div>
    <!-- startDate -->
    <div>
        시작일:<input type="date" v-model="startDate">
    </div>
    <!-- endDate -->
    <div>
        종료일:<input type="date" v-model="endDate">
    </div>
    <!-- timeUnit -->
    <select v-model="timeUnit">
        <option value="date">일간</option>
        <option value="week">주간</option>
        <option value="month">월간</option>
    </select>

    <!-- keywordGroups -->
    <!-- 그룹안에 각자 groupName, keywords가 필요하다 -->
    <!-- 1차로 팀명을 만들고 그안에 groupName, keywords 정리 -->
    <div>
        그룹명:<input v-model="userInputGroupName">
        <button @click="tempGroupAdd">추가</button>

        {{tempGroupName}}
    </div>
    <div>
        키워드 : <input v-model="userInputKeyword">
        <button @click="tempKeywordAdd">추가</button>

        <div>
            추가된 키워드
            <div v-for="temp in tempKeywords" :key="temp">
                {{temp}}
            </div>
        </div>
    </div>
    <div>
        <button @click="makeGroup">그룹 확정</button>

    </div>
    <div>
        확정된 그룹
        <div v-for="keywordGroup in keywordGroups" :key=keywordGroup>
            <div>그룹이름 : {{keywordGroup.groupName}}</div>
            <div>그룹 키워드 : {{keywordGroup.keywords}}</div>
        </div>
    </div>
    <div>
        <button @click="submitForm">제출하기</button>
    </div>
  </div>
</template>

<script>
//ctrl+space {}안에 비구조 할당 자동완성 기능
import {dataLap} from "../utils/api";
export default {
    data(){
        return{
            startDate:"",
            endDate:"",
            timeUnit:"",
            keywordGroups:[],
            userInputGroupName:"",
            userInputKeyword:"",
            tempGroupName:"",
            tempKeywords:[]
        }
    },
    methods:{
        //{groupName:"치킨", keywords:['BBQ','BHC']}
        tempGroupAdd(){
            this.tempGroupName=this.userInputGroupName;
        },
        tempKeywordAdd(){
            //this
            this.tempKeywords.push(this.userInputKeyword);
        },
        makeGroup(){
            this.keywordGroups.push({
                groupName:this.tempGroupName,
                keywords:this.tempKeywords,
            })
            this.tempGroupName="";
            this.tempKeywords=[];
            this.userInputGroupName="";
            this.userInputKeyword="";
        },
        async submitForm(){
            //api 요청을 보낸다 POST 요청
            const result =await dataLap.post({
                startDate:this.startDate,
                endDate:this.endDate,
                timeUnit:this.timeUnit,
                keywordGroups:this.keywordGroups
            });
            console.log(result);
            this.$store.dispatch("generateChartData");
        }
    }
}
</script>

<style>

</style>