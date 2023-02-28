const ssafy={
    speed:90,
    run(){
        //자기 객체 내부의 값을 참조할 때 사용
        //화살표함수를 사용하면 다르게 동작
        console.log(this);
        this.speed-=5;
    },

    //화살표함수의 this는 유의하자
    run2: ()=>console.log(this),

    showSpeed(){
        console.log(this.speed);
    },

    
    //캐릭터
    //각자의 HP, MP, 공격력

}
ssafy.name="임베디드";