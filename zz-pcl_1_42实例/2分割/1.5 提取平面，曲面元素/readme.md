![img.png](img.png)

PointIndices是PCL库中用于存储点云索引的结构体。它包含以下成员：

indices：存储点云索引的vector。
header：存储点云头信息。
PointIndices结构用于以下算法：

提取滤波器：用于提取点云的子集。
分割算法：用于分割点云，其中点云索引用于指定要分割的子集。