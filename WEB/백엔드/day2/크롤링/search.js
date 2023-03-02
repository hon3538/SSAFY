const puppeteer=require('puppeteer');

const main=async()=>{
    const browser = await puppeteer.launch({
        headless:false
    })
    const page= await browser.newPage();
    await page.goto("https://www.google.com/");
    await page.evaluate(()=>{
        //input 창 찾아서 버튼 클릭
        document.querySelector('.gLFyf').value="치킨";
        document.querySelector('.gNO89b').click();

    })
    //클릭을 하자마자 끝나고 스크린샷을 찍으니 넘어가기전에 실행
    //이동된 페이지니까 스크린샷을 찍는다.
    //waitForSelector 을 응용해서 대기후 스크린샷을 찍는다.
    await page.waitForSelector(".GLcBOb");
    await page.screenshot({path:"치킨.jpg",fullPage:true});
}
main();