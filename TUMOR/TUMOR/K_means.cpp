#include "K_means.h"

float CalcDiff(CvScalar s1, CvScalar s2)
{
	float result = 0;
	for (int i = 0; i < 3; i++) //��ͨ��
	{
		result += pow((float)s1.val[i] - (float)s2.val[i], 2);
	}
	return result;
}

IplImage* Kmeans(const string& path)
{
	IplImage* img = cvLoadImage(path.c_str());//����ͼ��ͼ�����Desktop�ļ���������Ǿ���·��

	//cvNamedWindow("ԭʼͼ��", 1); //��������
	//cvShowImage("ԭʼͼ��", img); //��ʾͼ��
	//cvWaitKey(0); //�ȴ�����

	CvMat *samples = cvCreateMat(img->height, img->width, CV_32FC3);//��������32λ����3ͨ��
	CvMat *clusters = cvCreateMat(img->height, img->width, CV_32SC1);//��������Ǿ���CV_32SF1����32λ����1ͨ��

	int i, j;
	for (i = 0; i<img->width; i++)
	{
		for (j = 0; j<img->height; j++)
		{
			CvScalar s;
			//��ȡͼ��������ص����ͨ��ֵ��RGB��
			s.val[0] = (float)cvGet2D(img, j, i).val[0];
			s.val[1] = (float)cvGet2D(img, j, i).val[1];
			s.val[2] = (float)cvGet2D(img, j, i).val[2];
			cvSet2D(samples, j, i, s);//�����ص���ͨ����ֵ��˳��������������
		}
	}

	CvScalar centers[NCLUSTER], before[NCLUSTER];
	int count[NCLUSTER]; //ÿ������
	float sum[NCLUSTER][3]; //��ͨ���ֱ����
	srand(time(NULL)); //��ʼ�������,��
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
		for (int k = 0; k < NCLUSTER; k++) //��ʼ��
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

	IplImage *bin = cvCreateImage(cvSize(img->width, img->height), IPL_DEPTH_8U, 1);//����������ʾ��ͼ�񣬶�ֵͼ��

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
			s.val[0] = val * step;//����ǽ���ͬ���ȡ��ͬ������ֵ��
			cvSet2D(bin, j, i, s);	//��ÿ�����ص㸳ֵ	
		}
	}

	//cvNamedWindow("����ͼ��", 1); //��������
	//cvShowImage("����ͼ��", bin); //��ʾͼ��
	//cvWaitKey(0); //�ȴ�����

	//cvDestroyWindow("ԭʼͼ��");//���ٴ���
	//cvReleaseImage(&img); //�ͷ�ͼ��
	//cvDestroyWindow("����ͼ��");//���ٴ���
	//cvReleaseImage(&bin); //�ͷ�ͼ��
	return bin;
}