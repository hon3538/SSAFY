async function setRenderBackground() { //비동기로 Lorem 이미지를 가져옴
    // 그냥 이미지 URL을 body의background img에 넣어줘도 되지만
    // 비동기로 만들어봄 

    // body의 background에 주소를 넣어도 OK
    // 근데 비동기로 넣어주기 위함이다.
    // 일부러 axios 요청으로 이미지를 받아오기

    // 그냥 이렇게 하면 Lorem image data가 크기도 너무크고 수정하기 힘듦
    //blob -> 이미지, 사운드, 비디오 등 멀티미디어 데이터를 다룰 때 사용
    const result = await axios.get("https://picsum.photos/1280/720", {
        responseType: "blob"
    });
    // console.log(result.data);

    //URL.createObjectURL -> 임시 URL을 만든다(페이지 내에서만 유효)
    //받아온 데이터를 임시 URL을 만들어서 그 URL에 body에 넣는다
    const imageURL = URL.createObjectURL(result.data);
    document.querySelector('body').style.backgroundImage = `url("${imageURL}")`;
}

// const setRenderBackground =async ()=>{}, 화살표 함수 방식

//시간 갱신
function timeForm(n) {

    // console.log(n);
    if (n / 10 < 1) {
        return "0" + n;
    } else return n;
}
function setTime() {
    const timer = document.querySelector('.timer');
    setInterval(() => {
        //date함수
        const date = new Date();
        
        // console.log(date);
        // console.log(date.getDate());

        //date.getHours();

        timer.textContent = `${date.getHours()}:${timeForm(date.getMinutes())}:${timeForm(date.getSeconds())}`;
    }, 1000)
}
function getMemo() {
    //localStorage로부터 가져와서 memo에 넣어주는 작업
    const memo = document.querySelector('.memo');
    memo.textContent = localStorage.getItem('todo');
}
function setMemo() {
    const memoInput = document.querySelector('.memo-input');

    memoInput.addEventListener('keyup', function (e) {
        // console.log(e.code);
        //console.log(e.target.value);
        //input 은 value로 가져오고 div text는 textContent로 가져온다.
        //e 는 Event 함수를 가리키고, e.target은 event함수를 넣어준 memoInput(element)을 가리킨다
        //e.code는 이벤트함수에 들어오는 코드이므로 keyup에 대한 code를 리턴해준다.

        if (e.code == "Enter" && e.target.value) { // input에 값이 없으면 null이므로 값이 있을때만 실행한다.
            //메모를 저장
            const memo = document.querySelector('.memo');
            // memo.textContent=e.target.value;

            //메모가 날아가지 않도록 저장
            //백엔드 ->DB에 저장해서 가져오는 작업
            // 브라우저에도 간단한 저장소 개념이 있다. localStorage

            //localstorage 사용법
            //localStorage.setItem('키','넣을값')
            localStorage.setItem('todo', e.target.value);
            //localStorage.getItem('키') -> 값을 가져온다.

            // 개발자도구 -> Application 에서 확인 가능
            // sesstion Storage는 새로고침하면 날아가는 메모리

            //getMomo로 분리
            getMemo();
            e.target.value = "" // enter시에 지움
        }
    })
}
function deleteMemo() {
    //이벤트 위임
    //querySelector('body');

    //document는 DOM에 있는 어떤 속성을 클릭해도 이벤트 발생
    //똑가튼 함수를 수백만개에 addEventListener 가정 -> 속도 저하
    document.addEventListener('click', function (e) {
        console.log(e.target);
        //e.taget.ClassList 가 hello인 경우에 ~ 이벤트 실행
        //textContent에 메모가 적혀있을 때만 지운다.

        //localStorage를 지워야하고, HTML 파트도 지워야한다.
        if (e.target.classList.contains('memo')) {
            localStorage.removeItem('todo');

            e.target.textContent = "";
        }
    })
}
function getPosition(options) {
    //navigator.geolocation -> 일반 callback 함수(promise x)
    //프로미스화
    return new Promise((resolve, reject) => {
        navigator.geolocation.getCurrentPosition(resolve, reject, options);
    })
}
async function getWeather(latitude, longitude) {
    //고정되는 값은 전체 대문자로 표현하기도 함
    //openweatherAPI
    const API_KEY = "d632f5fb4086a8b6f2ebac8445fb1134";

    //위도 경도가 존재할 경우
    if (latitude && longitude) {
        //날씨 API(위도 경도 ver)
        const URL = `http://api.openweathermap.org/data/2.5/forecast?lat=${latitude}&lon=${longitude}&appid=${API_KEY}`
        const result = await axios.get(URL);
        return result;
    }
    //위도 경도가 빈 문자열일 경우
    else {
        //날씨 API 위도 경도 없는 ver
        const city_name = 'Seoul';
        const URL = `http://api.openweathermap.org/data/2.5/forecast?q=${city_name}&appid=${API_KEY}`;
        const result = await axios.get(URL);
        return result;
    }
}
async function renderWeather() {
    //renderWeather에서 getPosition을 호출해서 위도 경도를 받아온다
    let latitude = ''; // 위도
    let longitude = ''; // 경도
    try {
        // getPosition().then(li =>{
        //     console.log(li); 
        //     //이 위도 경도를 날씨 API에 보내야하는데
        //     getWeather().then(data=>{
        //         //이러면 또 길어짐.. async/await 활용
        //     })
        // }).catch(error=>console.log(error))

        const position = await getPosition();
        // console.log(position);
        latitude = position.coords.latitude;
        longitude = position.coords.longitude;
        // console.log(latitude,longitude);
    } catch (error) {
        console.log(error);
    }
    // console.log(longitude,latitude);
    //날씨 요청 위도, 경도를 인자로 전달
    const weatherResponse = await getWeather(latitude, longitude);
    // console.log(weatherResponse.data.list);
    //weatherResponse.data.list
    const weatherData = weatherResponse.data.list;
    return weatherData;
}

//그..8개씩 뽑아서 보여주기 총 data 는 5일치로 8개씩 40개
async function setWeather() {
    //하루 00시~21 시까지 날씨 8구간 보여주고
    //버튼 클릭시 다음날 보여주기
    const data = await renderWeather();
    const modalBody = document.querySelector('.modal-body');
    const dateContent=document.querySelector('.date-wrapper');
    console.log(data);
    let date="2023-02-10";
    
    const today = data.reduce((acc, cur) => {
        // console.log(cur);
        // console.log(cur.dt_txt.indexOf("2023-02-10"));
        if (cur.dt_txt.indexOf(date) == 0) {
            acc.push(cur);
        }
        return acc;
    }, [])
    console.log(modalBody);
    dateContent.textContent=date;
    modalBody.innerHTML = today.map(e => modalComponent(e)).join("");
    //join은 추가되는 element들 사이의 구분자를 설정해줌.. default가 ' 이므로 null로 없애준다.
}

const btn=document.querySelector('.btn-next');
let cnt=-1;
btn.addEventListener('click',function(){
    cnt++;
    
    console.log(setDate(cnt%5));
    
})
function modalComponent(e) {
    console.log(e);
    const time=e.dt_txt.split(" ")[1];
    return `
    <div class="card bg-transparent text-white flex-grow-1 m-2">
  <h5 class="card-header">${time.split(":")[0]}:${time.split(":")[1]}</h5>
  <div class="card-body d-flex">
    <div class="flex-grow-1 d-flex flex-column justify-content-center align-items-center">
    <h5 class="card-title">${e.weather[0].main}</h5>
    <img class="weather-img" src="${matchIcon(e.weather[0].main)}">
    <p class="card-text">${changeToCelsius(e.main.temp)} ˚C</p> 
    </div>
  </div>
</div>
`
    //화씨를 섭씨로 전환
}
const changeToCelsius = (temp) => (temp - 273.15).toFixed(1);
function matchIcon(weatherData) {
    if (weatherData === "Clear") return "./images/039-sun.png";
    if (weatherData === "Clouds") return "./images/001-cloud.png";
    if (weatherData === "Rain") return "./images/003-rainy.png";
    if (weatherData === "Snow") return "./images/006-snowy.png";
    if (weatherData === "Thunderstorm") return "./images/008-storm.png";
    if (weatherData === "Drizzle") return "./images/031-snowflake.png";
    if (weatherData === "Atmosphere") return "./images/033-hurricane.png";
}
function allRender() {

    setRenderBackground();
    //5초마다 해당 콜백함수 반복, 페이지 시작하고 5초뒤부터 안의 내용 반복
    setInterval(() => {
        setRenderBackground();
    }, 5000)
    setTime();
    setMemo();
    getMemo();
    deleteMemo();
    renderWeather();
    setWeather();
    // getTimeWeather();
}
allRender();