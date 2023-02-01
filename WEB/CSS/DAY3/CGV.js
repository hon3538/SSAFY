console.log("TEST");

    const Movie_name=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > a > strong");
    const Book_rate=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > div > strong>span");
    const Date=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-contents > span.txt-info > strong");
    console.log("제목 "+Movie_name.textContent);
    console.log("예매율 "+Book_rate.textContent);
    // console.log("개봉일 "+Date.textContent.split("\n")[1]);
    //trim()앞뒤 공백을 제거
     console.log("개봉일 "+Date.textContent.trim());
    
    // const forDate=Date.textContent;
    // const arr=forDate.split("\n");
    // console.log(arr[1]);
    
    const Movie_name2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > a > strong");
    const Book_rate2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > div > strong > span");
    const Date2=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(2) > div.box-contents > span.txt-info > strong");
    Movie_name2.textContent="삼겹살과 그대라면";
    Book_rate2.textContent="18.6%";
    Date2.textContent=" 1985.07.07 개봉 ";

    const image1=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a > span > img");
    const image3=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a > span > img");
    const temp=image1.src;
    image1.src=image3.src;
    image3.src=temp;

    const URL1=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(1) > div.box-image > a");
    const URL3=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-image > a");
    console.log(URL1);
    console.log(URL3.href);
    console.log(URL1.href);
    URL3.href=URL1.href;
    
    const Movie_name3=document.querySelector("#contents > div.wrap-movie-chart > div.sect-movie-chart > ol:nth-child(2) > li:nth-child(3) > div.box-contents > a > strong");
    Movie_name3.textContent=Movie_name.textContent;

    //QuerySelectAll 은 하나의 정보가 아닌, 모든 정보를 List로 가져오는 방법
    // 모든 이미지를 가져와보자

    // let allTest=document.querySelectorAll(".thumb-image");
    // for(let i=0;i<allTest.length;i++){
    //     console.log(allTest[i].innerHTML);
    // }
    