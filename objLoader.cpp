

void loadInput(Object *obj)
{
	// load the OBJ file here
	char buffer[MAX_BUFFER_SIZE];
	bool has_normal=false, has_texture = false,has_group = false;  
	string matlFileName;
	
	
	while(cin.getline(buffer, MAX_BUFFER_SIZE)!=0)
	{
		stringstream ss(buffer);
		std::string line = ss.str();
		
		// empty line stream
		if(line.empty()){
			continue; //skip blank lines
			//cout<<"this is empty"<<endl;
		}
		trimline(line);
		std::vector < std::string > values = splitline(line, ' ');
		Vector3f v;
		
		//skipping comments
		if(values[0] == "#"){
			continue;
		}
		
		//mtlib file name
		
		else if(values[0] == "mtllib"){
			matlFileName = values[1];
			readMaterial(matlFileName);
			continue;
		}
		
		//groups / objects
		else if(values[0] == "g"){
			has_group = true;
			obj = new Object;
			
			Model.push_back(obj);
			
			obj->obj_name = values[1];
			
			
		}
		//usemtl 
		
		//Reading Vertices
		
		else if(values[0] == "v"){
			//std::cout << "Reading Vertices :" << '\t' << values[1] << '\t'<< values[2]<< '\t' <<
		//values[3]
		//<< std::endl;
			v[0] = std::atof(values[1].c_str());
			v[1] = std::atof(values[2].c_str());
			v[2] = std::atof(values[3].c_str());
			
			if(v[0]<xmin)
				xmin=v[0];
			if(v[0]>xmax)
				xmax=v[0];

			if(v[1]<ymin)
				ymin=v[1];
			if(v[1]>ymax)
				ymax=v[1];

			if(v[2]<zmin)
				zmin=v[2];
			if(v[2]>zmax)
				zmax=v[2];
			//cout << v[0] << endl;
			vecv.push_back(v);
			
			//cout << obj->vecv[0] << endl;
		}
		
		//Reading texture
		else if(values[0] == "vt"){
			
			has_texture = true;
			if(values.size() == 4){
				v[0] = std::atof(values[1].c_str());
				v[1] = std::atof(values[2].c_str());
				v[2] = std::atof(values[3].c_str());
			}
			else if(values.size() == 3){
				v[0] = std::atof(values[1].c_str());
				v[1] = std::atof(values[2].c_str());
				v[2] = 0;
			}
			else{
				v[0] = std::atof(values[1].c_str());
				v[1] = 0;
				v[2] = 0;
			}
			
			
			vec_tex.push_back(v);
			
		}
		
		//Reading Normals
		else if(values[0] == "vn"){
			has_normal = true;
			if(values.size() == 4){
				v[0] = std::atof(values[1].c_str());
				v[1] = std::atof(values[2].c_str());
				v[2] = std::atof(values[3].c_str());
			//	std::cout << "Reading Vertex Normal :" << '\t'<< values[1] << '\t'<< values[2]<< '\t' <<
		//values[3]
		//<< std::endl;
			}
			// for less than two  need to add
			vecn.push_back(v);
		}
		
		//Reading Faces (f v/vt/vn v/vt/vn v/vt/vn v/vt/vn  a/b/c d/e/f g/h/i)
		else if(values[0] == "f"){
			//for triangles 
			if(!has_group){
				obj = new Object;
				Model.push_back(obj);
				obj->obj_name = "group_default";
				has_group = true;
			}
			vector<unsigned> face;
			//with both texture and normal variables
			if(has_normal == true && has_texture == true){
				vector<string> flds1 = splitline(values[1],'/');
				vector<string> flds2 = splitline(values[2],'/');
				vector<string> flds3 = splitline(values[3],'/');
				face.push_back(atoi(flds1[0].c_str()));face.push_back(atoi(flds1[1].c_str()));face.push_back(atoi(flds1[2].c_str()));
				face.push_back(atoi(flds2[0].c_str()));face.push_back(atoi(flds2[1].c_str()));face.push_back(atoi(flds2[2].c_str()));
				face.push_back(atoi(flds3[0].c_str()));face.push_back(atoi(flds3[1].c_str()));face.push_back(atoi(flds3[2].c_str()));
				
				
				obj->vecf.push_back(face);
				//cout << "1st loop" <<endl;
			}
			else if(has_normal == true && has_texture == false){    //b e and h are absent 
				//cout << "2nd loop" <<endl;
				vector<string> flds1 = splitline(values[1],'/');
				vector<string> flds2 = splitline(values[2],'/');
				vector<string> flds3 = splitline(values[3],'/');
				//cout << flds1.size() << endl;
				face.push_back(atoi(flds1[0].c_str()));face.push_back(0);face.push_back(atoi(flds1[1].c_str()));
				face.push_back(atoi(flds2[0].c_str()));face.push_back(0);face.push_back(atoi(flds2[1].c_str()));
				face.push_back(atoi(flds3[0].c_str()));face.push_back(0);face.push_back(atoi(flds3[1].c_str()));
				obj->vecf.push_back(face);
				
			}
			else if(has_normal == false && has_texture == true){    //c f and i are absent
				
				vector<string> flds1 = splitline(values[1],'/');
				vector<string> flds2 = splitline(values[2],'/');
				vector<string> flds3 = splitline(values[3],'/');
				face.push_back(atoi(flds1[0].c_str()));face.push_back(atoi(flds1[1].c_str()));face.push_back(0);
				face.push_back(atoi(flds2[0].c_str()));face.push_back(atoi(flds2[1].c_str()));face.push_back(0);
				face.push_back(atoi(flds3[0].c_str()));face.push_back(atoi(flds3[1].c_str()));face.push_back(0);
				obj->vecf.push_back(face);
				//cout << "3rd loop" <<endl;
			}
			
			else if(has_normal == false && has_texture == false){
				
				std::size_t found = values[1].find_first_of('/');
				if(found != std::string::npos){
					vector<string> flds1 = splitline(values[1],'/');
					vector<string> flds2 = splitline(values[2],'/');
					vector<string> flds3 = splitline(values[3],'/');
					face.push_back(atoi(flds1[0].c_str()));face.push_back(0);face.push_back(0);
					face.push_back(atoi(flds2[0].c_str()));face.push_back(0);face.push_back(0);
					face.push_back(atoi(flds3[0].c_str()));face.push_back(0);face.push_back(0);
					obj->vecf.push_back(face);
				}
				else{
					//cout << values[1] << '\t' << values[2] << '\t' << values[3] << endl;
					
					face.push_back(atoi(values[1].c_str()));face.push_back(atoi("0"));face.push_back(atoi("0"));
					face.push_back(atoi(values[2].c_str()));face.push_back(atoi("0"));face.push_back(atoi("0"));
					face.push_back(atoi(values[3].c_str()));face.push_back(atoi("0"));face.push_back(atoi("0"));
					obj->vecf.push_back(face);
				}
				
			}
			
			
			
			
		} //face loop ends
		
		
		
		
		
		

	}
	for(unsigned int i=0; i< Model.size(); i++){
		if(Model[i]->vecf.size() == 0)
			Model.erase(Model.begin()+i);
	}
	
		
	
	cout<<vecv.size()<<"\t"<<vecn.size() <<"\t"  << vec_tex.size()<<endl;
	cout <<"Model Size \t" << Model.size() << endl;
	//cout << "Model Name \t" << Model[0]->obj_name << endl;
	//cout << "Face Index \t" << Model[0]->vecf[0][3] << Model[0]->vecf[0][4] << Model[0]->vecf[0][5]  << endl;
	cout << "Vecf size\t" << Model[0]->vecf.size() << endl;
}


