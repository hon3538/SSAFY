//�ߺ� ����
// ����� ����ϴ� ����


//������ ��� ����δ� hp�� 100�̰� run�̶�� ��ų�� �ִ�.
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