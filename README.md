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
              - 오브젝트 hit 판별식 구현 <br/>
              - 멀티 스레딩 구현
        </td>
        <td>
              - phong reflection 구현 <br />
              - .rt 파일 파싱 및 저장 
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
miniRT에서 지원하는 오브젝트는 Ambient, Lignt, Spotlight, camera, Sphere, plane, cylinder, Cone이 있다. 각각의 오브젝트들의 속성을 .rt파일에 아래 예시와 같은 형식으로 작성하면 된다. \
ambient와 camera는 .rt에 하나만 존재해야 한다.
```
Ambient: A   0.2   255,255,255
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


## 7-2.구현 기능
### 멀티스레드
화면을 빠르게 렌더링 하기위해서 화면을 분할하고 분할된 화면을 각각의 스레드를 만들어 렌더링하게 하였다.
### 레이트레이싱
카메라의 방향벡터를 기준으로 뷰포트를 생성하고 카메라에서 뷰포트로 픽셀 하나하나의 광선을 발사해 광선을 역추적해 픽셀의 색상을 계산한다. 하드웨어의 성능을 고려해 난반사와 산란은 추가하지 않았다.

### Phong shading
Phong shading은 3D 그래픽스에서 표면의 조명을 부드럽게 표현하는 기술 중 하나이다. 표면의 각 픽셀에 대해 조명의 반사를 계산하여 부드럽고 현실적인 이미지를 생성하는데 사용한다. 
1. Ambient : 주변 환경 광원에서 받는 광의 일부를 나타낸다. Ambient 반사는 표면이 주변에 둘러싸인 환경 광원에서 비직접적으로 받는 공을 표현한다. 이 광은 주변의 모든 방향에서 고르게 들어오는 광이다. 표면이 주변 광원에서 어떤 정도로 밝게 보일지에 대한 전반적인 조명을 제공하여 그림자 부분이 너무 어두워지지 않도록 한다.
2. Diffuse : 표면이 직접적인 광원에서 받은 광의 양을 나타낸다. 이는 표면이 광원 방향으로 얼마나 잘 반사되는지를 나타내는데, 표면이 광원 방향에 노출 될수록 강도가 높아진다. 물체의 형태와 표면을 강조하는데 사용된다.
3. Specular : 광택이나 빛이 반사되는 부분을 나타낸다. 표면에서 광원 방향으로 직접 반사되는 광의 반사를 표현한다.




## 8. 참고 자료
-   [WIKIPEDIA: Phong reflection model](https://en.wikipedia.org/wiki/Phong_reflection_model)
- [LEARN OpenGL](https://learnopengl.com/Lighting/Basic-Lighting)
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

