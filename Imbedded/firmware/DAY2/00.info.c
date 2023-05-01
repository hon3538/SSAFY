// st.com 에서 nucleo f103rb 의 schemetic을 켜논다
// CubeIDE(STM 보드용 IDE)를 키고 프로젝트를 만든다

// 스케메틱을 참고하며 자신이 사용할 핀을 인터럽트 설정하고
// 풀업 설정해준다
// 그다음 NVIC enable을 해준다 

// generator 옵션에 코드 생성을 체크하고 생성한다.
// stm32f1xx_it.c 에 들어가면 IRQ HANDLER가 있는데 ctrl 클릭으로 안으로 들어간다
// 그 안에 있는 callback함수가 weak로 되어 있는데 이것을 재정의하여
// 동작을 설정한다.

// callback 함수의 매개변수 핀이 내가 설정한 것과 같은지 확인한다.

void EXTI15_10_IRQHandler(void)
{
  HAL_GPIO_EXTI_IRQHandler(USER_SWITCH_Pin);
}

//it.c 에서 찾아서 복붙하고 재정의
void HAL_GPIO_EXTI_Callback(uint16_t GPIO_Pin)
{
  if(GPIO_Pin == USER_SWITCH_Pin){ //같은지 확인
  //토클핀은 drivers에서 gpio.c 에서 함수 찾아서 복붙

    HAL_GPIO_TogglePin(LD2_GPIO_Port, GPIO_PIN_5); //define 된 핀 참고(내가 킬 led 핀)
  }
}
//main.h 에 핀들이 정의되어있는 것을 복붙
#define USER_SWITCH_Pin GPIO_PIN_13
#define USER_SWITCH_GPIO_Port GPIOC
#define USER_SWITCH_EXTI_IRQn EXTI15_10_IRQn
#define LD2_Pin GPIO_PIN_5
#define LD2_GPIO_Port GPIOA

//callback함수 안에 delay를 사용하면 실행이 안 된다.
//cubeIDE 의 NVIC 를 보면 systick(clock을 가져오는?) 함수의 우선순위는 15인데
//외부 interrupt 의 우선순위는 0으로 되어있다..
//따라서 외부 interrupt의 우선순위를 낮춰주고 systick을 높여주면 가능하다.

//EXTI (External Interrupt) 는 핀마다 할당되지 않고 핀을 그룹화 해서 관리한다.
//GPIOX num 은 모두 같은 그룹이다. (ex. GPIOA 10 == GPIOB 10)
//같은 그룹끼리는 단 하나만 interrupt 핀으로 설정 가능하다.

//ISR Handling 함수는 하나만 존재하고
//각 interrupt는 
//if(GPIO_Pin == USER_SWITCH_Pin)
//이렇게 확인하여 각 핀맘다 callback함수 동작을 다르게 한다.

//interrupt는 rising edge / falling edge를 설정할 수 있다
//pull up / pull down 에 따라 영향 받는다

// rising, pull up 이면 -> 눌렀다 뗄 때 interrupt
// rising, pull down 이면 -> 눌렀을 때 interrupt
// falling, pull up 이면 -> 눌렀을 때 interrupt
// falling, pull down 이면 -> 눌렀다 뗄 때 interrupt