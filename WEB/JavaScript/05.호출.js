const ssafy={
    speed:90,
    run(){
        //�ڱ� ��ü ������ ���� ������ �� ���
        //ȭ��ǥ�Լ��� ����ϸ� �ٸ��� ����
        console.log(this);
        this.speed-=5;
    },

    //ȭ��ǥ�Լ��� this�� ��������
    run2: ()=>console.log(this),

    showSpeed(){
        console.log(this.speed);
    },

    
    //ĳ����
    //������ HP, MP, ���ݷ�

}
ssafy.name="�Ӻ����";