# miniRT

## 1. 프로젝트 소개


레이 트레이싱은 3차원 이미지를 렌더링 하는 기술 중 하나이다.    \
이  기술은 광선을 추적하여 빛이 어떻게 퍼지고 반사되느지를 실제 물리적인 원리에 기반하여 계산한다. \
이  프로젝트는 C언어를 기반으로 레이 트레이서의 가장 기본적인 기능만을 구현한다. \
레이트레이싱을 활용하여 인자로 오브젝트들의 정보가 담겨진 파일을 읽어 화면에 3D로 렌더링하는 프로그램을 만드는 프로젝트이다.

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
miniRT에서 지원하는 오브젝트는 Ambient, Lignt, Spotlight, camera, Sphere, plane, cylinder, Cone이 있다. 각각의 오브젝트들의 속성을 .rt파일에 아래 예시와 같은 형식으로 작성하면 된다.
```
ambien: A   0.2   255,255,255
    - identifier: A
    - ambient lighting ratio in range [0.0,1.0]: 0.2
    - R, G, B colors in range [0-255]: 255, 255, 255

Light: L    -40.0,50.0,0.0    0.6    10,0,255
    - idenfifier: L
    - x,y,z coordinates of the light point: -40.0,50.0,0.0
    - the light brightness ratio in range [0.0]: 0.6
    - R,G,B color in range [0-255]: 10, 0, 255

Spotlight: SL    0.0,0.0,-2.0    0,-1,0    0.4    0,0,255
    - idenfifier: SL
    - x,y,z coordinates of the light point: 0.0,0.0,-2.0
    - 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0,-1,0
    - R,G,B color in range [0-255]: 0,0,255

Camera: c   -50,0,0,20    0,0,1    70
    - identifier: C
    - x,y,z coordinates of the view point: -50.0,0,20
    - 3d normalized orientation vector. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    - FOV: Horizontal field of view in degrees in range [0,180]: 70

Sphere: sp    0.0,0.0,20.6    12.6    10,0,255
    - identifier: sp
    - x,y,z coordinates of the sphere center: 0.0,0.0,20.6
    - the sphere diameter: 12.6
    - R,G,B colors in range [0-255]: 10, 0, 255

Plane: pl   0.0,0.0,-10.0   0.0,1.0,0.0    0,0,225
    - identifier: pl
    - x,y,z coordinates of a point in the plane: 0.0,0.0,-10.0
    - 3d normalized normal vector. In range [-1,1] for each x,y,z axis: 0.0,1.0,0.0
    - R,G,B colors in range [0-255]: 0,0,225

Cylinder: cy    50.0,0.0,20.6    0.0,0.0,1.0    14.2    21.42    10,0,255
    - identifier: cy
    - x,y,z coordinates of the center of the cylinder: 50.0,0.0,20.6
    - 3d normalized vector of axis of cylinder. In range [-1,1] for each x,y,z axis: 0.0,0.0,1.0
    - the cylinder diameter: 14.2
    - the cylinder height: 21.42
    - R,G,B colors in range [0,255]: 10, 0, 255

Cone: cn    0,0,-5    0,1,0    5    5    0,255,0
    - identifier: cn
    - x,y,z coordinates of the center of the cone: 0,0,-5
    - 3d normalized vector of axis of cone. In range [-1,1] for each x,y,z axis: 0,1,0
    - the cone diameter: 5
    - the cone height: 5
    - R,G,B colors in range [0,255]: 0,255,0
```
.rt 파일 예시
```
A 0.2 255,255,255
C -50,50,20 0,0,1 70
L -40,0,30 0.7 255,255,255

pl 0,0,0 0,1.0,0 255,0,255
sp 0,0,20    20    255,0,0
cy 0,30,50  0,0,1.0  14.2  21.42  10,0,255
```


**7-2.구현 기능 어쩌고** \
수학 벡터 관련해서는 직접 작성 어쩌고 \
뭐 질감 어쩌고 반사각 어쩌고 subject보고 작성 어쩌고
구현하랬던 기능 어케 했는지
## 구현 과정
### scene 파일 파싱, 스레드 생성
프로그램이 시작하면 처음 .rt 파일을 읽어 렌더링 해야 하는 scene의 정보를 구조체에 저장 해놓는다. /
저장된 scene을 빠르게 렌더링 하기위해 화면을 분할하고 스레드를 생성해 각각의 스레드가 분할된 화면을 렌더링하게 한다.
### 렌더링 과정
카메라를 기준으로 카메라가 바라보는 방향에 가상의 뷰포트를 만들고 각 픽셀마다 빛을 쏜다.
모든 오브젝트를 확인하여 빛이 오브젝트에 hit 했는지를 확인하고 hit 했다면 그 정보를 hit_record에 저장한다. 아무 오브젝트에도 hit하지 않는 다면 해당 픽셀의 색상은 임의로 지정한 배경화면의 색상을 출력한다.
hit_record에 Phong reflection model을 적용하여 최종 픽셀의 색상을 구한다.
픽셀의 색상을 이미지 파일에 저장하고 모든 렌더링이 끝나며 이미지를 윈도우에 출력한다.
### 키보드 입력 이벤트
mlx_hook에 등록해 놓은 이벤트가 발생하면 지정해놓은 함수를 실행시켜 준다. 예를 들어 카메라의 위치를 바꾸는 입력이 들어오면 카메라 구조체의 좌표를 수정하고 저장해놓은 이미지를 지우고 렌더링을 처음부터 다시하여 이미지를 생성한다. 




## 8. 참고 자료
- https://en.wikipedia.org/wikiPhong_reflection_model
- https://learnopengl.com/Lighting/Basic-Lighting
- https://raytracing.github.io/books/RayTracingInOneWeekend.html
