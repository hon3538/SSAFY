//중복 제거
// 상속을 사용하는 이유


//세상의 모든 히어로는 hp가 100이고 run이라는 스킬이 있다.
//Hero에 constructor에 값을 넣을 경우,

class Hero{
    constructor(hp){
        this.hp=hp;
    }
    walk(){
        console.log("조금 빠르게 걷기");

    }
    run(){
        this.hp=this.hp-10;
    }
}

class Superman extends Hero{
    constructor(hp,mp){
        //부모 생성자를 실행해서 객체가 생성되어 값을 넣을 수 있는 상태로 만든다.
        //없으면 에러남..부모 필드와 겹침, 값이 여러개일 경우 한 번에 받아야함
        //생성자로 부모객체를 생성하는 행위이기 때문
        super(hp)
        this.hp=hp;
        this.mp=mp;
    }
    walk(){
        //부모에도 walk가 있다.
        //부모의 walk로 같이 사용하고 싶다면
        super.walk();
        console.log("더 빠르게 달리기");
    }
    fly(){
        console.log("fly");
        console.log(this.hp);
        console.log(this.mp);
    }

}

const superman =new Superman(1000,100);
superman.run();
superman.fly();