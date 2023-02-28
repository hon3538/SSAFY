

class Lawyer{
    constructor(name,age,instruction){
        this.name=name;
        this.age=age;
        this.instruction=instruction;
    }

    sayAbout(){
        console.log(
        `
        이름: ${this.name}
        나이: ${this.age}
        자기소개: ${this.instruction}
        `);
    }
}

const lawyer1=new Lawyer("홍의선",29,"나는 홍의선이야");
lawyer1.sayAbout();