#include "K_means.h"

float CalcDiff(CvScalar s1, CvScalar s2)
{
	float result = 0;
	for (int i = 0; i < 3; i++) //三通道
	{
		result += pow((float)s1.val[i] - (float)s2.val[i], 2);
	}
	return result;
}

IplImage* Kmeans(const string& path)
{
	IplImage* img = cvLoadImage(path.c_str());//加载图像，图像放在Desktop文件夹里，这里是绝对路径

	//cvNamedWindow("原始图像", 1); //创建窗口
	//cvShowImage("原始图像", img); //显示图像
	//cvWaitKey(0); //等待按键

	CvMat *samples = cvCreateMat(img->height, img->width, CV_32FC3);//样本矩阵，32位浮点3通道
	CvMat *clusters = cvCreateMat(img->height, img->width, CV_32SC1);//创建类别标记矩阵，CV_32SF1代表32位整型1通道

	int i, j;
	for (i = 0; i<img->width; i++)
	{
		for (j = 0; j<img->height; j++)
		{
			CvScalar s;
			//获取图像各个像素点的三通道值（RGB）
			s.val[0] = (float)cvGet2D(img, j, i).val[0];
			s.val[1] = (float)cvGet2D(img, j, i).val[1];
			s.val[2] = (float)cvGet2D(img, j, i).val[2];
			cvSet2D(samples, j, i, s);//将像素点三通道的值按顺序排入样本矩阵
		}
	}

	CvScalar centers[NCLUSTER], before[NCLUSTER];
	int count[NCLUSTER]; //每类点个数
	float sum[NCLUSTER][3]; //各通道分别求和
	srand(time(NULL)); //初始随机中心,舍
	float step = 255 / (NCLUSTER - 1);
	for (i = 0; i < NCLUSTER; i++)
	{
		//int m = rand() % img->height, n = rand() % img->width;
		centers[i].val[0] = step * i;
		centers[i].val[1] = step * i;
		centers[i].val[2] = step * i;
	}

	int t = 0;
	bool flag = 0;
	while (t++ < ITERS)
	{
		flag = 0;
		for (int k = 0; k < NCLUSTER; k++) //初始化
			count[k] = 0;
		for (int k = 0; k < NCLUSTER; k++)
		{
			for (int n = 0; n < 3; n++)
				sum[k][n] = 0;
		}
		for (i = 0; i < img->width; i++)
		{
			for (j = 0; j < img->height; j++)
			{
				int minDiff = -1, clus = 0;
				for (int k = 0; k < NCLUSTER; k++)
				{
					if (minDiff == -1) {
						minDiff = CalcDiff(cvGet2D(samples, j, i), centers[k]);
					}
					else {
						if (minDiff > CalcDiff(cvGet2D(samples, j, i), centers[k])) {
							minDiff = CalcDiff(cvGet2D(samples, j, i), centers[k]);
							clus = k;
						}
					}
				}
				count[clus]++;
				sum[clus][0] += (float)cvGet2D(samples, j, i).val[0]; //R
				sum[clus][1] += (float)cvGet2D(samples, j, i).val[1]; //G
				sum[clus][2] += (float)cvGet2D(samples, j, i).val[2]; //B
				clusters->data.i[j*clusters->cols + i] = clus;
			}
		}
		for (int k = 0; k < NCLUSTER; k++)
			before[k] = centers[k];
		for (int k = 0; k < NCLUSTER; k++)
		{
			centers[k].val[0] = sum[k][0] / count[k];
			centers[k].val[1] = sum[k][1] / count[k];
			centers[k].val[2] = sum[k][2] / count[k];
			if (abs(centers[k].val[0] - before[k].val[0]) > THRESH ||
				abs(centers[k].val[1] - before[k].val[1]) > THRESH ||
				abs(centers[k].val[2] - before[k].val[2]) > THRESH)
				flag = 1;
		}
		if (!flag)
			break;
	}

	IplImage *bin = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);//创建用于显示的图像，二值图像

	int val = 0;
//	float step = 255 / (NCLUSTER - 1);

	for (i = 0; i<img->width; i++)
	{
		for (j = 0; j<img->height; j++)
		{
			val = (int)clusters->data.i[j*clusters->cols + i];
			//if (val != 0)
			//	printf("%d\n", val); //DEBUGGING!
			CvScalar s;
			s.val[0] = val * step;//这个是将不同类别取不同的像素值，
			cvSet2D(bin, j, i, s);	//将每个像素点赋值	
		}
	}

	//cvNamedWindow("聚类图像", 1); //创建窗口
	//cvShowImage("聚类图像", bin); //显示图像
	//cvWaitKey(0); //等待按键

	//cvDestroyWindow("原始图像");//销毁窗口
	//cvReleaseImage(&img); //释放图像
	//cvDestroyWindow("聚类图像");//销毁窗口
	//cvReleaseImage(&bin); //释放图像
	return bin;
}