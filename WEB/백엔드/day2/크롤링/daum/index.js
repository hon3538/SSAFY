const puppeteer=require('puppeteer');

const main= async()=>{
    // 브라우저 생성
    const browser=await puppeteer.launch({
        headless:true
    });
    //브라우저에 페이지 생성
    const page = await browser.newPage();
    await page.goto("https://news.daum.net/digital#1");
    //브라우저 데이터 가져오기
    const data= await page.evaluate(()=>{
        const articles=document.querySelectorAll('.tit_g>a');
        const result = Array.from(articles).map(li=>li.textContent);
        return result;
    });
    console.log(data);
}
main();