const arr=[1,2,3,4,5];
const inventory=[     //��ü �迭
    {name: "A", quantity:1},
    {name: "B", quantity:2},
    {name: "C", quantity:3}
]
//find -> �ش��ϴ� �迭�� (ù��°)���� �����´�. 
const result = arr.find(element=> element>3);

//name�� B�� �迭�� ���� �����´�, �ش��ϴ� �Ӽ��� ���� ��ü�� �������
const result2 =inventory.find(li=>li.name==="B");

//findIndex -> �ش��ϴ� index�� �����´�.
const result3= inventory.findIndex(li=>li.name==="B");



//����! �ߴٸ��� ã�ƶ�
const chicken=[
    {name:"�Ӹ�", quantity:1},
    {name:"����", quantity:2},
    {name:"�ߴٸ�", quantity:2},
    {name:"�߰�����", quantity:1},
    {name:"�߹�", quantity:2}
]
const legs= chicken.find(i=>i.name==="�ߴٸ�");
const legsIndex=chicken.findIndex(i=>i.name==="�ߴٸ�");
console.log(`
    ${legs} ${legsIndex}`);

console.log(legs);


