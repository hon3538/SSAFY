//�ߺ� ����
// ����� ����ϴ� ����


//������ ��� ����δ� hp�� 100�̰� run�̶�� ��ų�� �ִ�.
//Hero�� constructor�� ���� ���� ���,

class Hero{
    constructor(hp){
        this.hp=hp;
    }
    walk(){
        console.log("���� ������ �ȱ�");

    }
    run(){
        this.hp=this.hp-10;
    }
}

class Superman extends Hero{
    constructor(hp,mp){
        //�θ� �����ڸ� �����ؼ� ��ü�� �����Ǿ� ���� ���� �� �ִ� ���·� �����.
        //������ ������..�θ� �ʵ�� ��ħ, ���� �������� ��� �� ���� �޾ƾ���
        //�����ڷ� �θ�ü�� �����ϴ� �����̱� ����
        super(hp)
        this.hp=hp;
        this.mp=mp;
    }
    walk(){
        //�θ𿡵� walk�� �ִ�.
        //�θ��� walk�� ���� ����ϰ� �ʹٸ�
        super.walk();
        console.log("�� ������ �޸���");
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