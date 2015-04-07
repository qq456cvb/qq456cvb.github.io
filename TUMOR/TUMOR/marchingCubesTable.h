
//线性插值法获得中点的坐标及法向
void getMiddlePoint(Point &p1,Point &p2,Point &result)
{
	result.coord[0]=p2.coord[0]+(THRESHOLD-p2.grayValue)*(p1.coord[0]-p2.coord[0])/(p1.grayValue-p2.grayValue);
	
	result.coord[1]=p2.coord[1]+(THRESHOLD-p2.grayValue)*(p1.coord[1]-p2.coord[1])/(p1.grayValue-p2.grayValue);
	
	result.coord[2]=p2.coord[2]+(THRESHOLD-p2.grayValue)*(p1.coord[2]-p2.coord[2])/(p1.grayValue-p2.grayValue);
	
	
	result.Normal[0]=p2.Normal[0]+(THRESHOLD-p2.grayValue)*(p1.Normal[0]-p2.Normal[0])/(p1.grayValue-p2.grayValue);
	
	result.Normal[1]=p2.Normal[1]+(THRESHOLD-p2.grayValue)*(p1.Normal[1]-p2.Normal[1])/(p1.grayValue-p2.grayValue);
	
	result.Normal[2]=p2.Normal[2]+(THRESHOLD-p2.grayValue)*(p1.Normal[2]-p2.Normal[2])/(p1.grayValue-p2.grayValue);
}

void getTriangleFromCubeInOneBlackPoint(Cube *cube,Triangle *tri)
{
	if(cube->vertexes[0].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri->Vertex_3);
	}
	else if(cube->vertexes[1].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri->Vertex_3);
	}
	else if(cube->vertexes[2].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri->Vertex_3);
	}
	else if(cube->vertexes[3].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri->Vertex_3);
	}
	else if(cube->vertexes[4].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri->Vertex_3);
	}
	else if(cube->vertexes[5].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri->Vertex_3);
	}
	else if(cube->vertexes[6].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri->Vertex_3);
	}
	else if(cube->vertexes[7].grayValue<THRESHOLD)
	{
		getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri->Vertex_1);
		
		getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri->Vertex_2);
		
		getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri->Vertex_3);
	}
}



void getTriangleFromCubeInTwoBlackPoints(Cube *cube,Triangle *tri_collection)
{
	if(cube->vertexes[0].grayValue<THRESHOLD)
	{
		if(cube->vertexes[1].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[2].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
		
	}
	else if(cube->vertexes[1].grayValue<THRESHOLD)
	{
		if(cube->vertexes[2].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
		
	}
	else if(cube->vertexes[2].grayValue<THRESHOLD)
	{
		if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
	}
	else if(cube->vertexes[3].grayValue<THRESHOLD)
	{
		if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
	}
	else if(cube->vertexes[4].grayValue<THRESHOLD)
	{
		if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
	}
	else if(cube->vertexes[5].grayValue<THRESHOLD)
	{
		if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
	}
	else if(cube->vertexes[6].grayValue<THRESHOLD)
	{
		if(cube->vertexes[7].grayValue<THRESHOLD)
		{
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
		}
	}
}



void getTriangleFromCubeInThreeBlackPoints(Cube *cube,Triangle *tri_collection)
{
	if(cube->vertexes[0].grayValue<THRESHOLD)
	{
		if(cube->vertexes[1].grayValue<THRESHOLD)
		{
			if(cube->vertexes[2].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);


				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);


				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[3].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[2].grayValue<THRESHOLD)
		{
			if(cube->vertexes[3].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[1].grayValue<THRESHOLD)
	{
		if(cube->vertexes[2].grayValue<THRESHOLD)
		{
			if(cube->vertexes[3].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[2].grayValue<THRESHOLD)
	{
		if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[3].grayValue<THRESHOLD)
	{
		if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);

				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[4].grayValue<THRESHOLD)
	{
		if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[5].grayValue<THRESHOLD)
	{
		if(cube->vertexes[6].grayValue<THRESHOLD)
		{
			if(cube->vertexes[7].grayValue<THRESHOLD)
			{
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
		}
	}
}


void getTriangleFromCubeInFourBlackPoints(Cube *cube,Triangle *tri_collection,int &tri_num)
{
	if(cube->vertexes[0].grayValue<THRESHOLD)
	{
		if(cube->vertexes[1].grayValue<THRESHOLD)
		{
			if(cube->vertexes[2].grayValue<THRESHOLD)
			{
				if(cube->vertexes[3].grayValue<THRESHOLD)
				{
					tri_num=2;

					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				}
				else if(cube->vertexes[4].grayValue<THRESHOLD)
				{
					tri_num=4;

					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);


					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[3].grayValue<THRESHOLD)
			{
				if(cube->vertexes[4].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=2;
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[2].grayValue<THRESHOLD)
		{
			if(cube->vertexes[3].grayValue<THRESHOLD)
			{
				if(cube->vertexes[4].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=2;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
					
				}
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_3);
				}
			}
		}
	}
	else if(cube->vertexes[1].grayValue<THRESHOLD)
	{
		if(cube->vertexes[2].grayValue<THRESHOLD)
		{
			if(cube->vertexes[3].grayValue<THRESHOLD)
			{
				if(cube->vertexes[4].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=2;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);



					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					

					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{//1347
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//1367
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{//1456
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//1467
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//1567
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
		}
	}
	else if(cube->vertexes[2].grayValue<THRESHOLD)
	{
		if(cube->vertexes[3].grayValue<THRESHOLD)
		{
			if(cube->vertexes[4].grayValue<THRESHOLD)
			{
				if(cube->vertexes[5].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{//2356
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=2;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
					
				}
			}
		}
		else if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{//2456
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//2467
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
					
					

					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//2567
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				}
			}
		}
	}
	else if(cube->vertexes[3].grayValue<THRESHOLD)
	{
		if(cube->vertexes[4].grayValue<THRESHOLD)
		{
			if(cube->vertexes[5].grayValue<THRESHOLD)
			{
				if(cube->vertexes[6].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
				else if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
			}
			else if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//3467
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
			}
		}
		else if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{//3567
					tri_num=4;
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
					
					getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
					
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
				}
			}
		}
	}
	else if(cube->vertexes[4].grayValue<THRESHOLD)
	{
		if(cube->vertexes[5].grayValue<THRESHOLD)
		{
			if(cube->vertexes[6].grayValue<THRESHOLD)
			{
				if(cube->vertexes[7].grayValue<THRESHOLD)
				{
					tri_num=2;
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
					
					getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
					
					
					
					getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
					
					getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
					
					getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
				}
			}
		}
	}
}





void getTriangleFromCubeInFiveBlackPoints(Cube *cube,Triangle *tri_collection,int &tri_num)
{
	if(cube->vertexes[0].grayValue>THRESHOLD)
	{
		if(cube->vertexes[1].grayValue>THRESHOLD)
		{
			if(cube->vertexes[2].grayValue>THRESHOLD)
			{
				tri_num=3;

				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);



				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);



				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_3);
					
			}
			else if(cube->vertexes[3].grayValue>THRESHOLD)
			{
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[4].grayValue>THRESHOLD)
			{
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[2].grayValue>THRESHOLD)
		{
			if(cube->vertexes[3].grayValue>THRESHOLD)
			{//023
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[4].grayValue>THRESHOLD)
			{//024
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue>THRESHOLD)
			{//025
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{//026
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{//027
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[3].grayValue>THRESHOLD)
		{
			if(cube->vertexes[4].grayValue>THRESHOLD)
			{
				//034
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_3);
				
			}
			else if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				//035
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//036
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//037
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
				
			}
		}
		else if(cube->vertexes[4].grayValue>THRESHOLD)
		{
			if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				//045
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//046
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//047
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
				
			}
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{
			if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//056
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//057
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//067
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[1].grayValue>THRESHOLD)
	{
		if(cube->vertexes[2].grayValue>THRESHOLD)
		{
			if(cube->vertexes[3].grayValue>THRESHOLD)
			{
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[4].grayValue>THRESHOLD)
			{
				//124
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				//125
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_3);
				
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//126
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
				
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//127
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);



				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[4].Vertex_3);
				
			}
		}
		else if(cube->vertexes[3].grayValue>THRESHOLD)
		{
			if(cube->vertexes[4].grayValue>THRESHOLD)
			{
				//134
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				//135
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//136
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//137
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[4].grayValue>THRESHOLD)
		{
			if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				//145
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//146
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_3);




				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//147
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
				
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{
			if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//156
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//157
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);



				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//167
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[4].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[2].grayValue>THRESHOLD)
	{
		if(cube->vertexes[3].grayValue>THRESHOLD)
		{
			if(cube->vertexes[4].grayValue>THRESHOLD)
			{
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[5].grayValue>THRESHOLD)
			{//235
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{//236
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_3);

			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{//237
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_3);
				
			}
		}
		else if(cube->vertexes[4].grayValue>THRESHOLD)
		{
			if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				//245
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//246
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//247
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{
			if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//256
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);

			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//257
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_3);
				


				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[4].Vertex_3);
				
			}
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//267
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[3].grayValue>THRESHOLD)
	{
		if(cube->vertexes[4].grayValue>THRESHOLD)
		{
			if(cube->vertexes[5].grayValue>THRESHOLD)
			{
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[6].grayValue>THRESHOLD)
			{//346
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{//347
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);

			}
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{
			if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				//356
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[4].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//357
				tri_num=5;
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[4].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[4].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[4].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				//367
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
				
			}
		}
	}
	else if(cube->vertexes[4].grayValue>THRESHOLD)
	{
		if(cube->vertexes[5].grayValue>THRESHOLD)
		{
			if(cube->vertexes[6].grayValue>THRESHOLD)
			{
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
			}
			else if(cube->vertexes[7].grayValue>THRESHOLD)
			{//457
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_3);
			}
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			if(cube->vertexes[7].grayValue>THRESHOLD)
			{//467
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
		}
	}
	else if(cube->vertexes[5].grayValue>THRESHOLD)
	{
		if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			if(cube->vertexes[7].grayValue>THRESHOLD)
			{
				tri_num=3;
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_2);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
				
				
				
				getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
				
				getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_2);
				
				getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_3);
			}
		}
	}
}




void getTriangleFromCubeInSixBlackPoints(Cube *cube,Triangle *tri_collection,int &tri_num)
{
	if(cube->vertexes[0].grayValue>THRESHOLD)
	{
		if(cube->vertexes[1].grayValue>THRESHOLD)
		{
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[2].grayValue>THRESHOLD)
		{//02
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);



			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
		}
		else if(cube->vertexes[3].grayValue>THRESHOLD)
		{//03
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
			
		}
		else if(cube->vertexes[4].grayValue>THRESHOLD)
		{//04
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
			
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{//05
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[3].Vertex_3);
			
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{//06
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);

		}
		else if(cube->vertexes[7].grayValue>THRESHOLD)
		{//07
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[3].Vertex_3);
			
		}
	}
	else if(cube->vertexes[1].grayValue>THRESHOLD)
	{
		if(cube->vertexes[2].grayValue>THRESHOLD)
		{
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[3].grayValue>THRESHOLD)
		{//13
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_3);
			
		}
		else if(cube->vertexes[4].grayValue>THRESHOLD)
		{//14
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[3].Vertex_3);
			
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{//15
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_3);

			
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{//16
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[3].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue>THRESHOLD)
		{//17
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
			
		}
	}
	else if(cube->vertexes[2].grayValue>THRESHOLD)
	{
		if(cube->vertexes[3].grayValue>THRESHOLD)
		{
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
			
		}
		else if(cube->vertexes[4].grayValue>THRESHOLD)
		{//24
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
			
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{//25
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[3].Vertex_3);
			
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{//26
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_3);
			
		}
		else if(cube->vertexes[7].grayValue>THRESHOLD)
		{//27
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_3);
			
		}
	}
	else if(cube->vertexes[3].grayValue>THRESHOLD)
	{
		if(cube->vertexes[4].grayValue>THRESHOLD)
		{
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_3);
		}
		else if(cube->vertexes[5].grayValue>THRESHOLD)
		{//35
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);

		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{//36
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[3].Vertex_3);
			
		}
		else if(cube->vertexes[7].grayValue>THRESHOLD)
		{//37
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_3);
			
		}
	}
	else if(cube->vertexes[4].grayValue>THRESHOLD)
	{
		if(cube->vertexes[5].grayValue>THRESHOLD)
		{
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[6].grayValue>THRESHOLD)
		{//46
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[3].Vertex_3);
			
		}
		else if(cube->vertexes[7].grayValue>THRESHOLD)
		{//47
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
			
			
		}
	}
	else if(cube->vertexes[5].grayValue>THRESHOLD)
	{
		if(cube->vertexes[6].grayValue>THRESHOLD)
		{
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
		}
		else if(cube->vertexes[7].grayValue>THRESHOLD)
		{//57
			tri_num=4;
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[2].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[2].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[2].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[3].Vertex_1);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[3].Vertex_2);
			
			getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[3].Vertex_3);
		}
	}
	else if(cube->vertexes[6].grayValue>THRESHOLD)
	{
		if(cube->vertexes[7].grayValue>THRESHOLD)
		{
			tri_num=2;
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[0].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[0].Vertex_2);
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[0].Vertex_3);
			
			
			
			getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
			
			getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
		}
	}
}




void getTriangleFromCubeInSevenBlackPoints(Cube *cube,Triangle *tri_collection,int &tri_num)
{
	if(cube->vertexes[0].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[0],cube->vertexes[3],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[0],cube->vertexes[1],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[0],cube->vertexes[4],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[1].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[1],cube->vertexes[0],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[1],cube->vertexes[2],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[1],cube->vertexes[5],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[2].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[2],cube->vertexes[1],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[2],cube->vertexes[3],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[2],cube->vertexes[6],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[3].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[3],cube->vertexes[2],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[3],cube->vertexes[0],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[3],cube->vertexes[7],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[4].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[4],cube->vertexes[7],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[4],cube->vertexes[5],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[4],cube->vertexes[0],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[5].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[5],cube->vertexes[4],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[5],cube->vertexes[6],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[5],cube->vertexes[1],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[6].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[6],cube->vertexes[5],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[6],cube->vertexes[7],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[6],cube->vertexes[2],tri_collection[1].Vertex_3);
	}
	else if(cube->vertexes[7].grayValue>THRESHOLD)
	{
		tri_num=1;
		
		getMiddlePoint(cube->vertexes[7],cube->vertexes[6],tri_collection[1].Vertex_1);
		
		getMiddlePoint(cube->vertexes[7],cube->vertexes[4],tri_collection[1].Vertex_2);
		
		getMiddlePoint(cube->vertexes[7],cube->vertexes[3],tri_collection[1].Vertex_3);
	}
}

