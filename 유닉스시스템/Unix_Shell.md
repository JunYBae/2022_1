### 유닉스 기본 명령어

## pathname 지정
```
pathname
/up/pr1 (디렉토리)  => 절대 pathname
./b/f1 or b/f1     => 상대 pathname
```

## 명령어
```
$ ls -l abc
$ = 프롬프트
ls = 명령어
-l = 옵션
abc = 파라미터
```

## 기타 명령어
```
whoami 자신에 대한 정보
who am i 자신에 대한 상세한 정보
id 자신의 아이디
date 날짜, 시간 출력
cal 2022 2022년 달력출력 (cal 만 치면 현재 달만 출력)
clear 화면을 깨끗이 지우고 커서 첫째 행
whereis gcc 명령어 위치 알려줌
```

### 주요 명령어

## ls
```
ls 
-F 파일의 유형을 나타냄
("@" 심볼릭 링크파일, "/" 디렉토리, "(별표)" 실행파일)

-R 하위 디렉토리 있을경우 끝까지 출력

-l 파일 상세정보 출력

-a 숨겨진 파일 출력
```

## cd
```
cd [디렉토리이름]

cd , cd ~ : 홈 디렉토리
```

## pwd
```
pwd 
현재 작업 디렉토리 출력
```

## mkdir
```
mkdir [이름]
디렉토리 생성
```

## rmdir
```
rmdir [이름]
디렉토리 삭제
!!!! 빈 디렉토리여야함 !!!!
```

## touch
```
touch [이름]
파일 생성 or 파일 수정시간을 현재시간으로
```

## rm
```
rm [이름]
파일, 디렉토리 삭제

-i 삭제시 확인 (y 삭제, n 삭제안함)
-r 디렉토리 삭제시 지정
```

## cat
```
cat [이름]
파일 한꺼번에 출력
cat > new_file
파일 생성 [ Ctrl + d ]
cat file1 file2 file3 > all_in_one_file
파일 결합
```

## more
```


