function palindrome(str) {
    const len = str.length;
    let ret=true;
    for(let i=0;i<len/2;i++){
        if(str.charAt(i)!=str.charAt(len-i-1)){
            ret=false;
            break;
        }
    }
    console.log(ret);
  }
  
  // 출력
  // palindrome('level') => true
  // palindrome('hi') => false