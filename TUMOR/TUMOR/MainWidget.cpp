#include "MainWidget.h"  
#include <qmessagebox.h>


CMainWidget::CMainWidget() {
	this->setGeometry(50, 50, 800, 600);
	this->setWindowTitle(QString("Hello OpenGL"));
}
CMainWidget::~CMainWidget() {
	delete(timer);
}

void CMainWidget::initializeGL() {
	initializeOpenGLFunctions();

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	// Enable depth test
	glEnable(GL_DEPTH_TEST);
	// Accept fragment if it closer to the camera than the former one
	glDepthFunc(GL_LESS);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_COLOR, GL_DST_COLOR);
	
	initData();
	initTimer();
	InitializeVertexBuffer();
	initMVP();
	initShaders();

}

void CMainWidget::initData()
{
	for (uint t = 0; t < 3; t++)
	{
		p_vertex[t] = new GLfloat[vcnt[t] * 3]; //每个顶点还要再*3, x,y,z分量
		//p_vertex = (GLfloat*) g_vertex_buffer_data;
		for (int i = 0; i < vcnt[t]; i += 3)
		{
			p_vertex[t][3 * i] = tris[t][i / 3].Vertex_1.coord[0] - 128;
			p_vertex[t][3 * i + 1] = tris[t][i / 3].Vertex_1.coord[1];
			p_vertex[t][3 * i + 2] = tris[t][i / 3].Vertex_1.coord[2] - 128;
			p_vertex[t][3 * i + 3] = tris[t][i / 3].Vertex_2.coord[0] - 128;
			p_vertex[t][3 * i + 4] = tris[t][i / 3].Vertex_2.coord[1];
			p_vertex[t][3 * i + 5] = tris[t][i / 3].Vertex_2.coord[2] - 128;
			p_vertex[t][3 * i + 6] = tris[t][i / 3].Vertex_3.coord[0] - 128;
			p_vertex[t][3 * i + 7] = tris[t][i / 3].Vertex_3.coord[1];
			p_vertex[t][3 * i + 8] = tris[t][i / 3].Vertex_3.coord[2] - 128;
		}
	}
	
}

void CMainWidget::initMVP()
{
	position = QVector3D(3, 0, 3);
	CurrentAngleZ = 0;
	CurrentAngleY = 0;
	LastAngleZ = M_PI + M_PI / 3;
	LastAngleY = 0;

	direction = QVector3D(cos(LastAngleY) * sin(LastAngleZ), sin(LastAngleY), cos(LastAngleY) * cos(LastAngleZ));
	right = QVector3D(sin(LastAngleY - M_PI / 2.0f), 0, cos(LastAngleY - M_PI / 2.0f));
	up = QVector3D::crossProduct(direction, right);


	View.lookAt(position, position + direction, up);

	Projection.perspective(45.0f, 4.0f / 3.0f, 0.1f, 100.0f);
	

	Model.scale(0.01f);
	rotate = 0.0f;
	// Our ModelViewProjection : multiplication of our 3 matrices
	MVP = Projection * View * Model; // Remember, matrix multiplication is the other way around
}

void CMainWidget::initTimer()
{
	timer = new QTimer(this); 
	timer->start(20);//FPS 50
	connect(timer, SIGNAL(timeout()), this, SLOT(updateGL()));
}

void CMainWidget::InitializeVertexBuffer()
{	
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);

	
	glGenBuffers(3, vertexbuffer);

	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[0]);
	glBufferData(GL_ARRAY_BUFFER, vcnt[0]*3*sizeof(GLfloat), p_vertex[0], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[1]);
	glBufferData(GL_ARRAY_BUFFER, vcnt[1] * 3 * sizeof(GLfloat), p_vertex[1], GL_STATIC_DRAW);

	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[2]);
	glBufferData(GL_ARRAY_BUFFER, vcnt[2] * 3 * sizeof(GLfloat), p_vertex[2], GL_STATIC_DRAW);

	
}


void CMainWidget::initShaders() {
	setlocale(LC_NUMERIC, "C");

	if (!program.addShaderFromSourceFile(QOpenGLShader::Vertex, "./vertex.vs")){
		QMessageBox::warning(this, "QOpenGLShader::Vertex", "QOpenGLShader::Vertex" + program.log());
		close();
	}

	// Compile fragment shader
	if (!program.addShaderFromSourceFile(QOpenGLShader::Fragment, "./frag.fs")){
		QMessageBox::warning(this, "QOpenGLShader::Fragment", "QOpenGLShader::Fragment" + program.log());
		close();
	}

	// Link shader pipeline
	if (!program.link())
		close();

	// Bind shader pipeline for use
	if (!program.bind())
		close();

	// Restore system locale
	setlocale(LC_ALL, "");
}
void CMainWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	rotate = 0.2f;
	Model.rotate(rotate, 0.0f, 1.0f, 0.0f);
	MVP = Projection * View * Model;
	MatrixID = program.uniformLocation("MVP");
	indexID = program.uniformLocation("index");
	program.setUniformValue(MatrixID, MVP);

	// 1rst attribute buffer : vertices

	for (int i = 0; i < 3; i++)
	{
		program.setUniformValue(indexID, i);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer[i]);
		glVertexAttribPointer(
			0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
			);



		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, vcnt[i]); // 12*3 indices starting at 0 -> 12 triangles

		glDisableVertexAttribArray(i);
	}

}
void CMainWidget::resizeGL(int iWidth, int iHeight) {
	glViewport(0, 0, iWidth, iHeight);
}

void CMainWidget::mousePressEvent(QMouseEvent *e)
{

	QPoint st(e->pos());
	StartPoint = st;

}

void CMainWidget::mouseReleaseEvent(QMouseEvent *e)
{
	/*记录上一次的角度*/
	LastAngleZ = CurrentAngleZ;
	LastAngleY = CurrentAngleY;
}

void CMainWidget::mouseMoveEvent(QMouseEvent *e)
{
	QPoint ed(e->pos());
	EndPoint = ed;
	RotateViewPoint();
	this->updateGL();
}

void CMainWidget::RotateViewPoint()
{
	float avAnale = 0.005f;

	/*把每次移动点跟开始按下鼠标记录的点作差，然后乘以avAngle,最后把上一次释放鼠标后时记录的
	角度相加起来*/
	CurrentAngleZ = (StartPoint.x() - EndPoint.x())*avAnale;
	CurrentAngleZ += LastAngleZ;
	CurrentAngleY = (StartPoint.y() - EndPoint.y())*avAnale;
	CurrentAngleY += LastAngleY;


	direction = QVector3D(cos(CurrentAngleY) * sin(CurrentAngleZ), sin(CurrentAngleY), cos(CurrentAngleY) * cos(CurrentAngleZ));
	right = QVector3D(sin(CurrentAngleY - M_PI / 2.0f), 0, cos(CurrentAngleY - M_PI / 2.0f));
	up = QVector3D::crossProduct(direction, right);
		
	View.setToIdentity();
	View.lookAt(position, position + direction, up);
	//View.lookAt(position, position+direction, up);
	//MVP = Projection * View * Model;

}
