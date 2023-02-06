class Person{
    constructor(name,hp){
        this.name=name;
        this.hp=hp;
    }
    hello(){
        console.log(this.name);
    }
}

class Avengers extends Person{
    constructor(name,hp,power,skill){
        super(name, hp);
        this.name=name;
        this.hp=hp;
        this.power=power;
        this.skill=skill;
    }
    
    information(){
        console.log(`
        �̸�: ${this.name}
        hp: ${this.hp}
        skill: ${this.skill}
        `);
    }

    fly(){
        console.log("������");
    }
}

const iornman = new Avengers();