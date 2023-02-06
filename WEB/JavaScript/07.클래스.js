//class 선언시 첫글자는 대문자

class Human{
    //초기값 설정
    constructor(name){ //name은 초기값
        this.HP=1000;
        this.name=name;
    }

    sayMyHP(){
        console.log(`
        HP: ${this.HP}`
        );
    }
    sayMyName(){
        console.log(`Name: ${this.name}`);
    }
}
const human1 = new Human();
const human2 = new Human("홍의선");
human2.sayMyName();
