/*
변화를 다 저장하지말고 변화를 기록만 해두는 식으로 메모리 관리를 할 수 있다
timeline 별로 기록
timeline 은 최대 11만개

timeLog 에 따라서
전체 timeLog 함수 -> index : timeline, value : {update index, update value}
각 index의 마지막 변화의 timeline 기록 배열
각 index의 이전 변화의 timeline을 기록 배열

copy는 깊은 복사이면 change log {-1,-1}
prevChange[timeline]=lastChange[address[Src]];
lastChange[address[Dest]]=timeline;


*/