#include <cv.h>
#include <math.h>
#include <highgui.h>
using namespace std;

#ifndef KMEANS
#define KMEANS
#define NCLUSTER 2 //�������
#define ITERS 100
#define THRESH 1
#endif

IplImage* Kmeans(const string& path);