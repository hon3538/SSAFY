//������Ÿ��
//class�� ������ ����
// ��ü�� ������ prototype�� �̿��ؼ� ����� ����� ������ ��ü�� ����
// �ش� ������Ÿ�Կ��� ��ü ���ǹ�.. split, substring, indexOf �� ����ִ�.

function Chicken(){
    this.information={
        head : "�Ӹ�",
        leg:"�ٸ�",
    }
}

const b=new Chicken();
const c=new Chicken();

//false
console.log(b.information ===c.information);
//�������̱� ������ ���� �����ϴ� �޸𸮰� �ٸ��� ������ false

//��� ġŲ�� ���� head, leg�� �ִ�
//ex indexOf��� �Լ��� ȣ���ϴµ� ���δ� ���� �޸𸮿� �Ҵ�ȴ�?

//������Ÿ�� Ȱ��

function BBQ(){

}
BBQ.prototype.information={
    head:'�Ӹ�',
    leg:'�ٸ�'
}
const bhc=new BBQ();
const bbbq=new BBQ();

//console.dir(bhc)
//���� ��ü�� ���� __proto__
const abc=[0,1,2,3,4];
console.log(abc.__proto__); // Array ��ü�� ������Ÿ��
console.log(abc.__proto__.__proto__); // �������� ������
console.log(abc.__proto__.__proto__.__proto__); //->�ֻ����� Object
//�ֻ��� ��ü�� Object��ü�� ��� ��ü���� �θ�

function abcd(){

}
console.dir(abcd); //�Լ�
console.dir(abcd.__proto__); // �Լ��� ������ Ÿ��
console.dir(abcd.__proto__.__proto__); //Object

//�ڹٽ�Ʈ��Ʈ ������Ÿ���̶��?
//class? ����?

//�ڹٽ�ũ��Ʈ���� Ŭ������ ������Ÿ���� ���ϰ� ����ϱ� ���� Syntax sugar
//������ ���� -> ���ϰ� ����ϱ� ����