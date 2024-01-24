# miniRT

## 1. 프로젝트 소개

이 프로젝트는 레이트레이싱 기반 어쩌고 프로그램 \
레이트레이싱(Ray-Tracing)은 어떤 기술 멀티스레드 어쩌고\
이를 통해서 뭘 구현했고 어쩌고 mlx를 사용했고 어쩌고\

미리보기 사진들 촵촵촵 간지나는걸로 촥촥

## 2. 개발 기간

23.01 - 23.03

## 3. 개발 환경

개발 언어 : C \
그래픽 라이브러리 : mlx

## 4. 멤버구성

<table align="center">
    <tr>
        <td />
        <td align="center">
            <a href="https://github.com/ebcode2021">
                <img src="https://avatars.githubusercontent.com/u/84271971?v=4" width="100" />
            </a>
        </td>
        <td align="center">
            <a href="https://github.com/minsubro">
                <img src="https://avatars.githubusercontent.com/u/96279704?v=4" width="100" />
            </a>
        </td>
    </tr>
    <tr>
        <td />
        <td align="center">
            👩🏻‍💻 <a href="https://github.com/ebcode2021"> eunbi son </a>
        </td>
        <td align="center">
            🐼 <a href="https://github.com/minsubro"> minsu kang </a>
        </td>
    </tr>
    <tr>
        <td>역할 분담</td>
        <td>
              - 수학 어쩌고 <br/>
              - 도형 hit 어쩌고
        </td>
        <td>
              - 거의 다했죠? <br />
              - 3d 렌더링 뭐 어쩌고
        </td>
    </tr>
</table>

## 5. 사용법

**5-1. 설치**

```
git clone git@github.com:ebcode2021/miniRT.git

cd miniRT

make

./miniRT [.rt file]
```

**5-2. 작동법** \
빛은 오직 하나. 물체는 복수. 빛도 복수 \

여기에 keyboard 중 동작하는 버튼들 그림으로 촥촥 \

기본 오브젝트 이랑 기본 빛은 뭐고 \
바꾸려면 어케하고 왼쪽 상단에 미니맵에 보인다 어쩌고\
**[오브젝트 이동]** \
`key D` : x축 양의 방향으로 회전 \
`key A` : x축 음의 방향으로 회전 \
`key Q` : y축 양의 방향으로 회전 \
`key E` : y축 양의 방향으로 회전 \
`key S` : z축 양의 방향으로 회전 \
`key W` : z축 음의 방향으로 회전

**[오브젝트 회전]** \
`key pgDn` : x축 양의 방향으로 회전 \
`key del` : x축 음의 방향으로 회전 \
`key ins` : y축 양의 방향으로 회전 \
`key pgUp` : y축 음의 방향으로 회전 \
`key end` : z축 양의 방향으로 회전 \
`key home` : z축 음의 방향으로 회전

**[오브젝트 변경]** \
선택한 모드 + `key left` or `key right` : 물체 선택

**[오브젝트 사이즈 조정]**\
`key J` : 물체 지름 증가 \
`key L` : 물체 반지름 감소 \
`key I` : 물체 높이 증가 \
`key L` : 물체 높이 감소

**[FOV 조정]** \
`key -` : 화면 축소 \
`key +` : 화면 확대

**[모드 변경]**\
`key 1` : 그림자 모드 ON/OFF \
`key 2` : 움직임 - 카메라(default) \
`key 3` : 움직임 모드 - 물체 \
`key 4` : 모드 - 빛 (자연광 <-> 하이라이트)
`key ESC` : 프로그램 종료

## 6. flow chart

옛날에 사진찍어둔거 기반으로 촵촵

## 7. 주요 기능

**7-1.rt파일 설정** \
지원하는 도형은 4가진데 어쩌고 \
rt파일 작성법? rgb 어쩌고

**7-2.구현 기능 어쩌고** \
수학 벡터 관련해서는 직접 작성 어쩌고 \
뭐 질감 어쩌고 반사각 어쩌고 subject보고 작성 어쩌고
구현하랬던 기능 어케 했는지

## 8. 참고 자료

수학 공식은 여기서 봤고 어쩌고 \
레이트레이싱 관련 논문 어쩌고 \
픽사 관련 사이트도 봤고 \
영어로된 뭐 그 가이드라인 어쩌고
