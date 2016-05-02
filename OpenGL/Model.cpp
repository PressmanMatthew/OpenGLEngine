#include "Model.h"

Model::Model()
{
	vertArr = 0;
	vertCount = 0;
}


Model::~Model()
{
}

bool Model::Buffer(string objFile)
{
	vector<vec3> locs;
	vector<vec2> uvs;
	vector<vec3> normals;
	vector<VertInd> indices;

	ifstream inFile;
	inFile.open(objFile);
	if (inFile.is_open())
	{
		string line;
		while (std::getline(inFile, line))
		{
			std::istringstream stream(line);
			string label;
			stream >> label;
			if (label == "v") //Vertex Location
			{
				float x, y, z;
				stream >> x >> y >> z;
				locs.push_back(vec3(x, y, z));
			}
			else if (label == "vt") //Vertex UV
			{
				float x, y;
				stream >> x >> y;
				uvs.push_back(vec2(x, y));
			}
			else if (label == "vn") //Vertex Normal
			{
				float x, y, z;
				stream >> x >> y >> z;
				normals.push_back(vec3(x, y, z));
			}
			else if (label == "f") //Vertex Index
			{
				VertInd vert;
				char slash;

				for (int i = 0; i < 3; i++)
				{
					//Read in all of integers
					stream >> vert.locInd >> slash;
					stream >> vert.uvInd >> slash;
					stream >> vert.normInd;

					//Decrement all of those numbers
					vert.locInd--;
					vert.uvInd--;
					vert.normInd--;

					//Add that Index to its list
					indices.push_back(vert);
				}
			}
		}

		inFile.close();
	}

	vertCount = indices.size();
	vector <Vertex> vertBufData(vertCount);
	for (unsigned int i = 0; i < vertCount; i++)
	{
		vertBufData[i] = { locs[indices[i].locInd], 
						   uvs[indices[i].uvInd], 
						   normals[indices[i].normInd]	};
	}
	GLuint vertBuf;

	glGenVertexArrays(1, &vertArr);
	glGenBuffers(1, &vertBuf);
	glBindVertexArray(vertArr);
	glBindBuffer(GL_ARRAY_BUFFER, vertBuf);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * vertCount, &vertBufData[0], GL_STATIC_DRAW);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), 0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void*)sizeof(vec3));
	glBindVertexArray(0);
	glClearColor(0.5f, 0.0f, 0.0f, 1.0f);

	return true;
}

void Model::Render()
{
	glBindVertexArray(vertArr);
	glDrawArrays(GL_TRIANGLES, 0, vertCount);
}
