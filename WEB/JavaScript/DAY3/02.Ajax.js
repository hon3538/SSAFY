// 과거는 무조건 data 갱신시 깜빡임 발생-> 새로고침으로 data 갱신하기 때문

// *server side 에서 그리는 방식
// JSP(자바 서버 페이지) -> 옛날방식 
// JAVA + html 형식 -> 브라우저는 java 해석 능력이 없음
// -> 그래서 server에서 이 JAVA 형식을 읽어서 HTML로 만들어서 리턴
// -> 이과정에서 새로고침이 일어남

// *client side 에서 갱신 -> AJAX(Asynchronous JavaScript and XML)
// 새로고침없이 변한 부분만 data를 불러와서 update
// megabox
// 데이터를 비동기 요청 -> 그걸 그리는것
// 데이터가 비어있으면 로딩 -> 데이터가 들어오면 로딩끄고 데이터 그리기

