//class ����� ù���ڴ� �빮��

class Human{
    //�ʱⰪ ����
    constructor(name){ //name�� �ʱⰪ
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
const human2 = new Human("ȫ�Ǽ�");
human2.sayMyName();
