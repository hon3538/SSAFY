//토글버튼
const toggleButton =document.querySelector('.toggle-button');
// 배경
const bodyBackground=document.querySelector('body');
// header-nav
const headerNav=document.querySelector('.header-nav-list-wrapper');
// bookmark-wrapper
const bookmarkWrapper=document.querySelector('bookmark-wrapper');
// search-input
const searchInput=document.querySelector('#search-input');
// img-icon-wrapper
// s붙여주고
// qeurySelectorAll로 변경
const imgIconWrappers=document.querySelectorAll('.img-icon-wrapper');
// bookmark-text
const bookmarkTexts=document.querySelectorAll('.bookmark-text');

toggleButton.addEventListener('click',function(){
    // 클릭
    // 다크모드로 전환되는 상태
    // 일반모드 -> 다크모드라고 텍스트 변경을 해줘야 한다.
    
    toggleButton.textContent="다크 모드";
    // if(toggleButton.textContent==="다크 모드"){
    //     toggleButton.textContent="일반 모드";
    // }else{
    //     toggleButton.textContent="다크 모드";
    // }
    
    toggleButton.classList.toggle('toggle-button-darkmode')
    bodyBackground.classList.toggle('body-background-darkmode');
    headerNav.classList.toggle('text-darkmode');
    for(let i=0;i<imgIconWrappers.length;i++){
        imgIconWrappers[i].classList.toggle('img-icon-wrpper-darkmord');
    }
    for(let i=0;i<bookmarkTexts;i++){
        bookmarkTexts[i].classList.toggle('text-darkmode');
    }
    if(toggleButton.classList.contains('toggle-button-darkmode')){
        toggleButton.textContent="일반 모드";
    }
})

searchInput.addEventListener('keyup',function(getElementById){
    //e.code 어떤 키를 입력했는지 알수 있게 해줌
    // enter를 입력했을때 ㅡ거로 검색을 진행할 예정
    if(e.code==="Enter"){
        // 검색어가 존재하는 경우에만 이동
        // if(e.target.value==="")
        if(!e.target.value){
            alert("검색어를 입력하지 않으셨습니다");
            return;
        }
    }
    // 이동하기

    const googleSearch="https://www.google.com/search?q=";
    // location.href=googleSearch+e.target.value;

    // 새창으로 열기
    // window.open
    // <a href="" target="_blank">새창으로 열기</a>
    window.open(goolgeSearch+e.target.value,"_blank")
})