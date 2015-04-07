#include <QGLWidget>  
#include <qopenglfunctions_4_3_core.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <QtGui/QOpenGLShaderProgram>
#include <QTime>
#include <QMouseEvent>
#include <qmath.h>
#include <qtimer.h>



typedef float float3[3];
#define THRESHOLD 254.0
#ifndef MAIN_WIDGET
#define MAIN_WIDGET




struct Point
{
	float3 Normal; //法向量
	float3 coord;//坐标
	float3 texCoord;//纹理坐标
	float grayValue;//灰度值
};


//六面体
struct Cube
{
	Cube()
	{
		vertexes = new Point[8];
	}
	Point *vertexes;//六面体的八个顶点
};

struct Triangle
{
	Triangle(){};
	Point Vertex_1;
	Point Vertex_2;
	Point Vertex_3;
};

static const GLfloat g_vertex_buffer_data[] = {
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	-1.0f, -1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	-1.0f, -1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, -1.0f,
	1.0f, -1.0f, -1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, -1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, -1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, 1.0f, 1.0f,
	-1.0f, 1.0f, 1.0f,
	1.0f, -1.0f, 1.0f
};



class CMainWidget : public QGLWidget, protected QOpenGLFunctions_4_3_Core{
	Q_OBJECT
private:
	QMatrix4x4 Projection;
	QMatrix4x4 View;
	QMatrix4x4 Model;
	QPoint StartPoint;     //记录鼠标按下的点
	QPoint EndPoint;       //鼠标移动过程中的点
 
	QVector3D right;
	QVector3D up;

	float CurrentAngleZ;     //当前与Z轴的夹角
	float CurrentAngleY;     //当前与Y轴的夹角

	float LastAngleZ;        //上一次与Z轴的夹角
	float LastAngleY;        //上一次与Y轴的夹角

	QVector3D position;
	QVector3D direction;

	QOpenGLShaderProgram program;
	QMatrix4x4 MVP;
	GLuint VertexArrayID;
	GLuint vertexbuffer[3];
	GLuint colorbuffer;
	GLuint MatrixID;
	GLuint indexID;
	Triangle* tris[3];
	int vcnt[3]; //共有3*三角形个数顶点
	GLfloat* p_vertex[3];
	GLfloat rotate;
	QTimer *timer;
public:
	CMainWidget();
	CMainWidget(Triangle* in_tris[3], int tris_cnt[3]){
		for (int i = 0; i < 3; i++)
		{
			tris[i] = in_tris[i];
			vcnt[i] = tris_cnt[i] * 3;
		}
	};
	~CMainWidget();

protected:
	void initializeGL();
	void initShaders();
	void initData();
	void InitializeVertexBuffer();
	void initMVP();
	void paintGL();
	void resizeGL(int iWidth, int iHeight);
	void mouseMoveEvent(QMouseEvent *e);
	void mousePressEvent(QMouseEvent *e);
	void mouseReleaseEvent(QMouseEvent *e);
	void RotateViewPoint();
	void initTimer();
};

#endif