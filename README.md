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

**5-1. 설치 및 실행**

```
git clone git@github.com:ebcode2021/miniRT.git

cd miniRT

make

./miniRT [.rt file]
```

.rt file은 scene 폴더에 있다.

**5-2. 작동법** \
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
조건 : 움직임 모드가 `물체 모드` or `빛 모드` \
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
![draw_scene](https://github.com/minsubro/42-miniRT/assets/84271971/babceeea-4d9a-461c-a1b2-deff5c1ba6e6)

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
