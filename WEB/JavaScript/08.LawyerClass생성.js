

class Lawyer{
    constructor(name,age,instruction){
        this.name=name;
        this.age=age;
        this.instruction=instruction;
    }

    sayAbout(){
        console.log(
        `
        �̸�: ${this.name}
        ����: ${this.age}
        �ڱ�Ұ�: ${this.instruction}
        `);
    }
}

const lawyer1=new Lawyer("ȫ�Ǽ�",29,"���� ȫ�Ǽ��̾�");
lawyer1.sayAbout();