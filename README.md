# miniRT

## 1. 프로젝트 소개
프로젝트 miniRT는 레이 트레이싱(Ray-Tracing)과 퐁 리플렉션(Phong Reflection)을 활용한 3D 렌더링 프로그램이다. \
레이 트레이싱은 3차원 이미지를 렌더링하는 기술 중 하나로, 광선이 물체의 표면에서 반사되어 카메라를 향해 돌아오는 경로를 계산하여 물체를 렌더링할 수 있게 한다. \
렌더링된 물체를 입체적으로 표현하기 위해 퐁 리플렉션을 활용하여 주변광, 확산광, 반사광 등을 적용하여 사실적으로 보이도록 구현하였다. 이를 통해 조명과 그림자의 효과를 물체에 적용하여 시각적으로 풍부한 결과물을 얻을 수 있다. 

![메인 예시](https://github.com/minsubro/42-miniRT/assets/84271971/88305424-542c-4031-a449-c080bd682ba2)

<br />

<img width="1178" alt="예시들" src="https://github.com/minsubro/42-miniRT/assets/84271971/0d85cc15-d44c-41fd-9838-e0ef121e0ee5">


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
              - raytracing 구현 <br/>
              - 멀티 스레딩 구현
        </td>
        <td>
              - phong reflection 구현 <br />
              - .rt 파일 파싱 및 저장 
        </td>
    </tr>
</table>

## 5. 사용법

**5-1. 설치 및 실행**

```
git clone git@github.com:ebcode2021/miniRT.git

cd miniRT

make

./miniRT [.rt file] // .rt file은 scene 폴더에 있음
```

** 

**5-2. 작동법** 
> 처음 프로그램을 동작하면 모드가 NONE 이므로 이동할 수 없으므로 모드를 선택해야 움직일 수 있다. \
물체 모드일 때는 왼쪽 상단에 미니맵으로 물체가 표시된다.

**[사용 가능한 key]**
<br />

![keyboard](https://github.com/minsubro/42-miniRT/assets/84271971/37fd6194-9398-4706-9150-515a3e939c1f)



**[모드 변경]**\
`key 2` : 카메라 모드 \
`key 3` : 물체 모드 \
`key 4` : 빛 변경 [자연광(default) <-> 하이라이트]

**[이동]** \
`key D` : x축 양의 방향으로 이동 \
`key A` : x축 음의 방향으로 이동 \
`key Q` : y축 양의 방향으로 이동 \
`key E` : y축 양의 방향으로 이동 \
`key S` : z축 양의 방향으로 이동 \
`key W` : z축 음의 방향으로 이동

**[선택 오브젝트 변경]** \
움직임 모드가 `물체 모드` or `빛 모드` 일 때 \
`key left` or `key right`

**[선택 오브젝트 사이즈 조정]**\
`key J` : 물체 지름 증가 \
`key L` : 물체 반지름 감소 \
`key I` : 물체 높이 증가 \
`key L` : 물체 높이 감소

**[선택 오브젝트 회전]** \
`key pgdn` : x축 양의 방향으로 회전 \
`key del` : x축 음의 방향으로 회전 \
`key ins` : y축 양의 방향으로 회전 \
`key pgUp` : y축 음의 방향으로 회전 \
`key end` : z축 양의 방향으로 회전 \
`key home` : z축 음의 방향으로 회전

**[FOV 조정]** \
`key -` : FOV 축소 \
`key +` : FOV 확대

**[그림자 모드 변경]**\
`key 1` : 그림자 모드 ON/OFF

**[프로그램 종료]**\
`key ESC` or `왼쪽 상단에 X 클릭`

## 6. flow chart
**[Main Flow]**
![main-flow](https://github.com/minsubro/42-miniRT/assets/84271971/1a18a1da-7275-4bdc-85f0-2057c34eec2b)

<br/>

**[Draw Scene]**
![draw_scene](https://github.com/minsubro/42-miniRT/assets/84271971/7c00a683-8ef8-44b2-bbe5-1db1c6655f69)

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
**[.rt 파일 예시]**
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

### Ray-tracing
카메라의 방향벡터를 기준으로 뷰포트를 생성하고 카메라에서 뷰포트로 픽셀 하나하나의 광선을 발사해 광선을 역추적해 픽셀의 색상을 계산한다. 하드웨어의 성능을 고려해 난반사와 산란은 추가하지 않았다.

### Phong reflection model
Phong reflection model은 3D 그래픽스에서 표면의 조명을 부드럽게 표현하는 기술 중 하나이다. 표면의 각 픽셀에 대해 조명의 반사를 계산하여 부드럽고 현실적인 이미지를 생성하는데 사용한다. 
1. Ambient : 주변 환경 광원에서 받는 광의 일부를 나타낸다. Ambient 반사는 표면이 주변에 둘러싸인 환경 광원에서 비직접적으로 받는 공을 표현한다. 이 광은 주변의 모든 방향에서 고르게 들어오는 광이다. 표면이 주변 광원에서 어떤 정도로 밝게 보일지에 대한 전반적인 조명을 제공하여 그림자 부분이 너무 어두워지지 않도록 한다.
2. Diffuse : 표면이 직접적인 광원에서 받은 광의 양을 나타낸다. 이는 표면이 광원 방향으로 얼마나 잘 반사되는지를 나타내는데, 표면이 광원 방향에 노출 될수록 강도가 높아진다. 물체의 형태와 표면을 강조하는데 사용된다.
3. Specular : 광택이나 빛이 반사되는 부분을 나타낸다. 표면에서 광원 방향으로 직접 반사되는 광의 반사를 표현한다.




## 8. 참고 자료
-   [WIKIPEDIA: Phong reflection model](https://en.wikipedia.org/wiki/Phong_reflection_model)
- [LEARN OpenGL](https://learnopengl.com/Lighting/Basic-Lighting)
- [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)

