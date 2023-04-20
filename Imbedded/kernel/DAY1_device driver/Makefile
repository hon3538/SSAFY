KERNEL_HEADERS=/lib/modules/$(shell uname -r)/build
# /usr/src 커널 헤더, 소스코드 경로
# 현재 시스템에 설치된 커널에 대한 디렉토리
# /lib/module/커널버전/build

obj-m := hi.o

# -C 옵션 : 해당 디렉토리로 이동해서 make를 수행
# M=$(PWD) : 결과물이 현재 디렉토리에 생성된다
# 현재 경로가 ~/test/ 이며 Makefile에서 make 할 때
# /lib/modules/[커널버전]/build/ 에 있는 Makefile을 참조해서 make 하겠다!
# make 결과물은 현재 경로인 ~/test/ 에 생성

go:
	make -C $(KERNEL_HEADERS) M=$(PWD) modules

clean:
	make -C $(KERNEL_HEADERS) M=$(PWD clean) 