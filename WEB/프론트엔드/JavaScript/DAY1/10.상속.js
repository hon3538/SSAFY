//중복 제거
// 상속을 사용하는 이유


//세상의 모든 히어로는 hp가 100이고 run이라는 스킬이 있다.
class Hero{
    constructor(){
        this.hp=100;
    }
    run(){
        this.hp=this.hp-10;
    }
}

class Superman extends Hero{
    fly(){
        console.log("fly");
        console.log(this.hp);
    }

}

const superman =new Superman();
superman.run();
superman.fly();