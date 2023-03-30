//ifdef 과 동일하게 사용 가능하다.
//defined를 쓰면 &&, ||, ==, !=, >, < 등 연산기호 사용가능

#define BBQ 30

#if defined BBQ > 50
AAA;
#else
BBB;
#endif

#define KFC 0

#if defined BBQ && defined KFC
AAA;
#else
BBB;
#endif

#define DEBUG
#define RELEASE

#define CAMERA //카메라 모듈이 존재한다는 뜻
#define GPS //GPS 모듈이 존재한다는 뜻

//DEBUG 모드일때만 메세지 출력
//근데 이것말고도 방법은 다양함..
#if defined(CAMERA)&&defined(DEBUG)
찰칵찰칵;
#endif

#if defined(GPS)&&defined(DEBUG)
위치위치;
#endif