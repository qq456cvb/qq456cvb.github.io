#define CUBESIZE 3 //CUBE大小(像素点)
#include <QApplication>
#include <QDir>  
#include <QList>  
#include <QFileInfoList>  
#include <QDebug>  
#include <QTextCodec>
#include "MainWidget.h"
#include "marchingCubesTable.h"
#include "K_means.h"


int g_thresh = 1;
int tris_cnt[3];
Triangle* tris[3];

//IplImage *g_image = cvLoadImage("C:\\Users\\Administrator\\pictures\\Truth\\BRATS_HG0001_truth\\BRATS_HG0001_truth_95.png");

IplImage* Skeleton(const std::string& path)
{
	IplImage *g_image = cvLoadImage(path.c_str());
	IplImage *g_gray = NULL;
	CvMemStorage *g_storage = NULL;
	if (g_storage == NULL)
	{
		g_gray = cvCreateImage(cvGetSize(g_image), 8, 1);
		g_storage = cvCreateMemStorage(0);
	}
	else
	{
		cvClearMemStorage(g_storage);
	}
	CvSeq* contours = 0;
	cvCvtColor(g_image, g_gray, CV_BGR2GRAY);
	cvThreshold(g_gray, g_gray, g_thresh, 255, CV_THRESH_BINARY);
	//cvShowImage("Contours", g_gray);
	cvFindContours(g_gray, g_storage, &contours);
	if (contours)
	{
		cvDrawContours(g_gray, contours, cvScalarAll(255), cvScalarAll(255), 100);

	}
	//cvShowImage("Contours", g_gray);
	return g_gray;
}

Triangle* Model(std::string path, int index)
{
	if (index == 2) {//special due to the tumor images given
		g_thresh = 250;
	}
	else {
		g_thresh = 1;
	}
	Triangle* tris = new Triangle[100000];
	path = path + "%d.png";
	IplImage* images[300];
	CvMat* m[300];
	int inum = 1;
	QString filename;
	filename.sprintf(path.c_str(), inum);
	QFileInfo *temp = new QFileInfo;

	//cvNamedWindow("Contours", 1);
	while (temp->exists(filename))
	{
		if (index == 2 && inum == 106) //special
			break;
		images[inum - 1] = Skeleton(filename.toStdString());
		//cvShowImage("skeleton", images[inum - 1]);
		inum++;
		filename.sprintf(path.c_str(), inum);
	}
	
	/*cvShowImage("skeleton", images[154]);
	return tris;*/
	for (int k = 0; k < inum - 1; k++)
	{
		m[k] = cvCreateMat(images[0]->height, images[0]->width, CV_32FC3);
	}

	int i, j, k;
	for (i = 0; i<images[0]->width; i++)
	{
		for (j = 0; j<images[0]->height; j++)
		{
			CvScalar s;
			//获取图像各个像素点的三通道值（RGB）

			for (k = 0; k < inum - 1; k++)
			{
				s.val[0] = (float)cvGet2D(images[k], j, i).val[0];
				s.val[1] = (float)cvGet2D(images[k], j, i).val[1];
				s.val[2] = (float)cvGet2D(images[k], j, i).val[2];
				cvSet2D(m[k], j, i, s);//将像素点三通道的值按顺序排入样本矩阵
			}
		}
	}

	Cube* mesh = new Cube;
	//TODO:50000个三角形元，需修改为动态
	Point p;
	for (k = 0; k < inum - 2; k++)
	{
		for (i = 0; i < images[k]->width; i += CUBESIZE - 1)
		{
			for (j = 0; j < images[k]->height; j += CUBESIZE - 1)
			{
				int tris_num;
				int bk = 0; //Blank points sum
				p.coord[0] = i;			//openGL-x
				p.coord[1] = k + 1;        //openGL-y
				p.coord[2] = j + CUBESIZE - 1;     //openGL-z
				p.grayValue = 255 - cvGet2D(m[k+1], j, i).val[0];
				mesh->vertexes[0] = p;
				p.coord[1] = k;
				p.grayValue = 255 - cvGet2D(m[k], j, i).val[0];
				mesh->vertexes[3] = p;
				p.coord[2] = j;
				p.grayValue = 255 - cvGet2D(m[k], j, i).val[0];
				mesh->vertexes[7] = p;
				p.coord[1] = k+1;
				p.grayValue = 255 - cvGet2D(m[k+1], j, i).val[0];
				mesh->vertexes[4] = p;
				p.coord[0] = i + CUBESIZE - 1;
				p.grayValue = 255 - cvGet2D(m[k+1], j, i).val[0];
				mesh->vertexes[5] = p;
				p.coord[1] = k;
				p.grayValue = 255 - cvGet2D(m[k], j, i).val[0];
				mesh->vertexes[6] = p;
				p.coord[2] = j + CUBESIZE - 1;
				p.grayValue = 255 - cvGet2D(m[k], j, i).val[0];
				mesh->vertexes[2] = p;
				p.coord[1] = k+1;
				p.grayValue = 255 - cvGet2D(m[k+1], j, i).val[0];
				mesh->vertexes[1] = p;
				for (int u = 0; u < 8; u++)
				{
					if (mesh->vertexes[u].grayValue < THRESHOLD)
						bk++;
				}
				//if (bk && bk != 8) //DEBUG
				//{
				//	if (k >150)
				//		bk = bk;
				//}
				switch (bk)	{
				case 0:
					break;
				case 1:
					getTriangleFromCubeInOneBlackPoint(mesh, tris + tris_cnt[index]);
					tris_cnt[index] += 1;
					break;
				case 2:
					getTriangleFromCubeInTwoBlackPoints(mesh, tris + tris_cnt[index]);
					tris_cnt[index] += 2;
					break;
				case 3:
					getTriangleFromCubeInThreeBlackPoints(mesh, tris + tris_cnt[index]);
					tris_cnt[index] += 3;
					break;
				case 4:
					getTriangleFromCubeInFourBlackPoints(mesh, tris + tris_cnt[index], tris_num);
					tris_cnt[index] += tris_num;
 					break;
				case 5:
					getTriangleFromCubeInFiveBlackPoints(mesh, tris + tris_cnt[index], tris_num);
					tris_cnt[index] += tris_num;
					break;
				case 6:
					getTriangleFromCubeInSixBlackPoints(mesh, tris + tris_cnt[index], tris_num);
					tris_cnt[index] += tris_num;
					break;
				case 7:
					getTriangleFromCubeInSevenBlackPoints(mesh, tris + tris_cnt[index], tris_num);
					tris_cnt[index] += tris_num;
					break;
				case 8:
					break;
				}
				/*if (bk == 4 && tris_num == 2)
				{
					if (k + 2 < inum) {
						Triangle t1, t2;
						t1 = *(tris + tris_cnt[index] - tris_num);
						t2 = *(tris + tris_cnt[index] - tris_num + 1);
						if (255 - cvGet2D(m[k + 2], j, i).val[0] < THRESHOLD)
						{
							Point x = t1.Vertex_1;
							Point y = t1.Vertex_3;
							Point z = t2.Vertex_1;
						}
						else {
							Point x = t1.Vertex_2;
							Point y = t2.Vertex_2;
							Point z = t2.Vertex_3;
						}
						
					}
				}*/
				
				//i = i1->width;
				//break;
			}
		}
	}
	return tris;
}


int main(int argc, char* argv[])
{
	QApplication app(argc, argv);

	QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));
	//QTextCodec::setCodecForTr(codec);
	
	QDir d("C:/Users/Administrator/pictures/Truth/BRATS_HG0001_truth");
	d.setFilter(QDir::Files | QDir::Hidden | QDir::NoSymLinks | QDir::AllDirs);//列出文件,列出隐藏文件（在Unix下就是以.开始的为文件）,不列出符号链接（不支持符号连接的操作系统会忽略）  
	d.setSorting(QDir::Name);//按文件大小排序，相反的排序顺序  
	const QFileInfoList list = d.entryInfoList();//返回这个目录中所有目录和文件的QFileInfo对象的列表  
	QFileInfoList::const_iterator iterator = list.begin();
	qDebug() << "The total num of dirs and files: " << d.count();//返回找到的目录和文件的数量  
	qDebug() << "fileName                             size";
	
	while (iterator != list.end()){
		qDebug() << (*iterator).fileName() << "                " << (*iterator).size();
		iterator++;
	}
	qDebug() << "Current dir: " << d.current();//返回应用程序当前目录。  
	qDebug() << "Current dir's absolute path:" << d.currentPath();//返回应用程序当前目录的绝对路径。  

	//g_image = cvLoadImage("E:/images/BRATS_HG0001/BRATS_HG0001_T1/BRATS_HG0001_T1_100.png");
	/*cvNamedWindow("Origin", 1);
	cvShowImage("Origin", g_image);

	cvNamedWindow("Contours", 1);
	cvCreateTrackbar("Threshold", "Contours", &g_thresh, 10, &Skeleton);
	Skeleton(0);
	cvWaitKey();*/

	
	tris[0] = Model("E:/images/BRATS_HG0001/BRATS_HG0001_T1/BRATS_HG0001_T1_", 0);
	tris[1] = Model("C:/Users/Administrator/pictures/Truth/BRATS_HG0001_truth/BRATS_HG0001_truth_", 1);
	tris[2] = Model("C:/Users/Administrator/pictures/Truth/BRATS_HG0001_truth/BRATS_HG0001_truth_", 2);

	CMainWidget* pMainWidget = new CMainWidget(tris, tris_cnt);
	pMainWidget->show();

	return (app.exec());
}