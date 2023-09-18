PCL完全是一个模块化的现代C++模板库，基于一下第三方库：Boost,Eigen,FLANN,VTK,CUDA,OpenNI,Qhull，实现点云的获取，滤波，分割，配准，检索，特征提取，识别，追踪，曲面重建，可视化等。

![image-20230918163203398](./image/image-20230918163203398.png)

## 可用Point类型

```
PointXYZ
PointXYZI
PointXYZRGBA
PointXYZRGB
PointXY
InterestPoint
Normal
PointNormal
PointXYZRGBNormal
PointXYZINormal
PointWithRange
PointWithViewpoint
MomentInvariants
PrincipalRadiiRSD
Boundary
PrincipalCurvatures
BounPFHSignature125dary
FPFHSignature33
VFHSignature308
Narf36
BorderDescription
IntensityGradient
Histogram
PointWithScale
PointSurfel
```



MovingLeastSquares是PCL库中用于点云插值的滤波器。它使用滑动最小二乘法来拟合点云，并根据拟合结果插值新点。

MovingLeastSquares滤波器可以用于以下场景：

点云上采样：使用MovingLeastSquares滤波器可以将低密度的点云上采样为高密度的点云。
点云平滑：使用MovingLeastSquares滤波器可以将点云中的噪声和畸变进行平滑。
点云重建：使用MovingLeastSquares滤波器可以将点云中的空洞进行填充。
MovingLeastSquares滤波器有以下参数：

searchRadius：滑动窗口的半径。
upsamplingMethod：上采样方法。
interpolationMethod：插值方法。
outputNormals：是否输出法向量。