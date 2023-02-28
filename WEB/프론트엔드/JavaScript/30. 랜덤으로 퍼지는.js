// 기능 구현
// 클래스를 구현한다.
// 클래스는 기본적으로 클릭된횟수, 색상, 좌표값, width,height를 가진다.
// 특별 오브젝트 클래스는 버튼 클릭시 추가 이펙트가 있도록 동작을 해보자!!
// 그전에 해당 오브젝트의 좌표위치를 가져오는 방법과
// 그 좌표를 기반으로 움직이는 법을 익혀야 할것 같다.

// 1. 클릭시 랜덤으로 움직인다.
// 2. 일반 버튼은 1번 클릭시 죽고
// 3. 특별 버튼은 2번 클릭시 죽는다

const button = document.querySelector("#button");
const specialButton = document.querySelector("#special-button");
let score = 0;

class RandomObject {
	// 클릭된 횟수
	// 색상
	// 좌표값
	constructor(x, y) {
		console.log("aa");
		this.life = 1;
		this.x = x;
		this.y = y;
		this.element = null;
		this.init();
	}

	setElement() {
		this.element = document.createElement("div");

		// widht랑 heigt는 랜덤값으로한다 최소 30 최대 200
		const size = Math.ceil(Math.random() * 170) + 30;
		console.log(Math.ceil(Math.random() * 170) + 30);
		this.element.classList.add("el");
		this.element.style.width = size + "px";
		this.element.style.height = size + "px";
		this.element.style.position = "absolute";
		this.element.style.left = this.x + "px";
		this.element.style.top = this.y + "px";

		this.element.style.background =
			"linear-gradient(45deg, #ff9a9e 0%, #fad0c4 99%, #fad0c4 100%)";
		this.element.style.borderRadius = "15px";
		this.element.style.boxShadow = "rgba(149, 157, 165, 0.2) 0px 8px 24px";

		document.querySelector(".box").append(this.element);
	}

	setClickEvent() {
		this.element.addEventListener("click", (e) => {
			// 클릭할때마다 life를 감소시킨다
			this.life = this.life - 1;
			console.log(this.life);

			if (this.life < 1) {
				// element 제거하기!
				this.element.remove();
				score = score + 1;
				document.querySelector("span").textContent = score;
			}
		});
	}

	init() {
		this.setElement();

		this.setClickEvent();

		// this.element.addEventListener('click', function(e){
		//     console.log(this.life);
		//     // 화살표로 바꾸자
		// })

		// 여기서 클릭할때마다 class 형태로 추가될수 있도록
	}
}

class SpecialRandomObject extends RandomObject {
	constructor(x, y) {
		super(x, y);
		this.life = 2;
	}

	setElement() {
		super.setElement();
		const direction = Math.round(Math.random() * 360);
		const r1 = Math.round(Math.random() * 255); // Math.random() outputs a numer between 0(inclusive) & 1(exclusive) with around 17 decimal digits.
		const g1 = Math.round(Math.random() * 255); // We take this number and multiply it by 255. This number can never go above 255.
		const b1 = Math.round(Math.random() * 255); // We have a decimal
		const a1 = Math.round(Math.random() * 10) / 10;

		const r2 = Math.round(Math.random() * 255);
		const g2 = Math.round(Math.random() * 255);
		const b2 = Math.round(Math.random() * 255);
		// to add random transparency to the image;
		const a2 = Math.round(Math.random() * 10) / 10;

		//Giving values to the linear gradiant.
		this.element.style.background = `linear-gradient(${direction}deg, rgba(${r1},${g1},${b1},${a1}), rgba(${r2},${g2},${b2},${a2}))`;
	}

	setClickEvent() {
		this.element.addEventListener("click", (e) => {
			// 클릭할때마다 life를 감소시킨다
			this.life = this.life - 1;
			console.log(this.life);

			if (this.life < 1) {
				// element 제거하기!
				this.element.remove();
				score = score + 5;
				document.querySelector("span").textContent = score;
			}
		});
	}
}

// background-image: linear-gradient(45deg, #ff9a9e 0%, #fad0c4 99%, #fad0c4 100%);
// https://webgradients.com/
// https://getcssscan.com/css-box-shadow-examples
// box-shadow: rgba(0, 0, 0, 0.35) 0px 5px 15px;
// box-shadow: rgba(149, 157, 165, 0.2) 0px 8px 24px;
button.addEventListener("click", function () {
	console.log("aa");

	// x y 축을 랜덤으로
	const normal = document.querySelector("#normal");
	if (Number(normal.value) > 50) {
		alert("너무 많은 값을 입력하셨습니다");
		return;
	}

	for (let i = 0; i < Number(normal.value); i++) {
		new RandomObject(
			Math.ceil(Math.random() * 700),
			Math.ceil(Math.random() * 700)
		);
	}
});

specialButton.addEventListener("click", function () {
	const speical = document.querySelector("#special");
	if (Number(speical.value) > 50) {
		alert("너무 많은 값을 입력하셨습니다");
		return;
	}

	for (let i = 0; i < Number(speical.value); i++) {
		new SpecialRandomObject(
			Math.ceil(Math.random() * 700),
			Math.ceil(Math.random() * 700)
		);
	}
});
