### VI EDITER

## vi 시작하기
```
vi [이름], vim [이름], view [이름]

+[n] 파일 라인으로 커서 이동 그냥 + 할시 맨 마지막 부분
-r 파일 복구
-c (예시: vi -c /철인/ [파일이름]) 철인이라는 단어에 커서 위치
```

## vi 종료
```
:q [Enter] => 수정 없을 시 종료
:q! [Enter] => 강제 종료
```

## vi 저장
```
:w [Enter] => vi 종료 X 저장
:w [이름] [Enter] => 다른이름으로 저장
:w! [이름] [Enter] => 다른이름으로 저장(겹치면 덮어쓰기)

:wq => 저장 후 종료
ZZ => ZZ == :wq
```

## 화면 및 커서 이동
```
^ : 제일 처음 단어 위치 이동 [Home Key]
0 : 라인의 제일 왼쪽 이동
$ : 제일 제일 오른쪽으로 이동 [End Key]
ctrl + b : 한 화면 위로 올라감 [PnUp Key]
ctrl + f : 한 화면 아래로 올라감 [PnDn Key]
ctrl + u : 반 화면 위로 올라감
ctrl + d : 반 화면 아래로 내려감
```

## 간단한 명령어
```
J  현재 행과 다음 행을 연결
.  전에 수행했던 명령 반복 수행
nG  n 라인 번호로 이동
G   맨 끝 라인으로 이동
:set nu 줄 번호 설정
:set nonu 줄 번호 해제
:set tabstop=4 탭 크기 설정
:set autoindent 자동 인던트 설정
:set noautoindent 자동 인던트 해제
:set all 모든 설정 옵션 보여줌
```
