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
	float3 Normal; //������
	float3 coord;//����
	float3 texCoord;//��������
	float grayValue;//�Ҷ�ֵ
};


//������
struct Cube
{
	Cube()
	{
		vertexes = new Point[8];
	}
	Point *vertexes;//������İ˸�����
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
	QPoint StartPoint;     //��¼��갴�µĵ�
	QPoint EndPoint;       //����ƶ������еĵ�
 
	QVector3D right;
	QVector3D up;

	float CurrentAngleZ;     //��ǰ��Z��ļн�
	float CurrentAngleY;     //��ǰ��Y��ļн�

	float LastAngleZ;        //��һ����Z��ļн�
	float LastAngleY;        //��һ����Y��ļн�

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
	int vcnt[3]; //����3*�����θ�������
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