#pragma once
#include "KinectData.h"
#include "KinectBuffer.h"
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/io/pcd_io.h>

using namespace pcl;
using namespace std;

// Class purpose: downsampling point clouds from 640x480 to 64x48
class KinectDownsampler
{
public:
  void Start ();
  KinectDownsampler(KinectBuffer * inputBuf, KinectBuffer * outputBuf);
  ~KinectDownsampler(void);
private:
  KinectBuffer * inputBuffer;
  KinectBuffer * outputBuffer;
  void downsample (const PointCloud<PointXYZ>::ConstPtr &CloudIn, PointCloud<PointXYZ>::Ptr &CloudOut);
};

