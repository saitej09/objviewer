void readMaterial(string FileName){
	
	if (matl_ObjFile.is_open())
		matl_ObjFile.close();
	
	char * S = new char[FileName.length() + 1];
	std::strcpy(S,FileName.c_str());
	matl_ObjFile.open(S, std::ifstream::in);
	
	if(matl_ObjFile == NULL){
		
		cout<<"Unable To Open Material File :"<<std::endl;
		
	}
	
	else{
		cout<<"Opened Material File Sucessfully :"<<std::endl;
		
	}
	string line;
	MaterialInfo matl_data;
	Vector3f ka,kd,ks,tf;
	int illum_val;
	//float ns_exp;
	while (std::getline(matl_ObjFile, line)) {
		
		if(line.empty()){
			continue; //skip blank lines
		}
		trimline(line);
		std::vector < std::string > matl_values = splitline(line, ' ');
		if(matl_values[0] == "#"){
			continue;
		}
		//new mtl names
		else if(matl_values[0] == "newmtl"){
			
			matl_data.matl_name = matl_values[1];
		//	cout<< "Material name"<<matl_data.matl_name<< endl;
		}
		//Material color and illumination statements:
		
		//color, transparency, and reflectivity values.
		
		else if(matl_values[0] == "Ka"){
			
			if(matl_values[1] == "xyz"){
				//Ka xyz x y z "x y z" are the values of the CIEXYZ color space. 
			}
			else if(matl_values[1] == "spectral"){
				//Ka spectral file.rfl factor
			}
			//ka r g b  g and b optional (if not given make them equal to r )
			else{
				//if all r g b values r present
				if(matl_values.size() == 4){ 
					ka[0] = std::atof(matl_values[1].c_str());
					ka[1] = std::atof(matl_values[2].c_str());
					ka[2] = std::atof(matl_values[3].c_str());
		//			cout <<"ka" << ka[0] << ka[1] << ka[2]<< endl;
					matl_data.Ka = ka;
				}
				//if only r & g are present
				
				else if(matl_values.size() == 3){
					ka[0] = std::atof(matl_values[1].c_str());
					ka[1] = std::atof(matl_values[2].c_str());
					ka[2] = ka[0];
					matl_data.Ka = ka;
				}
				//if only r is present
				else if(matl_values.size() == 2){
					ka[0] = std::atof(matl_values[1].c_str());
					ka[1] = ka[2] = ka[0];
					matl_data.Ka = ka;
				}
				
				
			}
			
		}
		
		//kd diffusive reflectivity
		else if(matl_values[0] == "Kd"){
			
			if(matl_values[1] == "xyz"){
				//Kd xyz x y z "x y z" are the values of the CIEXYZ color space. 
			}
			else if(matl_values[1] == "spectral"){
				//Kd spectral file.rfl factor
			}
			//kd r g b  g and b optional (if not given make them equal to r )
			else{
				
				//if all r g b values r present
				if(matl_values.size() == 4){ 
					kd[0] = std::atof(matl_values[1].c_str());
					kd[1] = std::atof(matl_values[2].c_str());
					kd[2] = std::atof(matl_values[3].c_str());
					//cout <<"kd" << kd[0] << kd[1] << kd[2]<< endl;
					matl_data.Kd = kd;
				}
				//if only r & g are present
				
				else if(matl_values.size() == 3){
					kd[0] = std::atof(matl_values[1].c_str());
					kd[1] = std::atof(matl_values[2].c_str());
					kd[2] = kd[0];
					matl_data.Kd = kd;
				}
				//if only r is present
				else if(matl_values.size() == 2){
					kd[0] = std::atof(matl_values[1].c_str());
					kd[1] = kd[2] = kd[0];
					matl_data.Kd = kd;
				}
			}
			
		}
		//ks specular reflectivity
		
		else if(matl_values[0] == "Ks"){
			
			if(matl_values[1] == "xyz"){
				//Ks xyz x y z "x y z" are the values of the CIEXYZ color space. 
			}
			else if(matl_values[1] == "spectral"){
				//Ks spectral file.rfl factor
			}
			//ks r g b  g and b optional (if not given make them equal to r )
			else{
				
				//if all r g b values r present
				if(matl_values.size() == 4){ 
					ks[0] = std::atof(matl_values[1].c_str());
					ks[1] = std::atof(matl_values[2].c_str());
					ks[2] = std::atof(matl_values[3].c_str());
					//cout <<"ks" << ks[0] << ks[1] << ks[2]<< endl;
					matl_data.Ks = ks;
				}
				//if only r & g are present
				
				else if(matl_values.size() == 3){
					ks[0] = std::atof(matl_values[1].c_str());
					ks[1] = std::atof(matl_values[2].c_str());
					ks[2] = ks[0];
					matl_data.Ks = ks;
				}
				//if only r is present
				else if(matl_values.size() == 2){
					ks[0] = std::atof(matl_values[1].c_str());
					ks[1] = ks[2] = ks[0];
					matl_data.Ks = ks;
				}
			}
			
		}
		
		//Tf transmission filter
		
		else if(matl_values[0] == "Tf"){
			
			if(matl_values[1] == "xyz"){
				//Tf xyz x y z "x y z" are the values of the CIEXYZ color space. 
			}
			else if(matl_values[1] == "spectral"){
				//Tf spectral file.rfl factor
			}
			//Tf r g b  g and b optional (if not given make them equal to r )
			else{
				//if all r g b values r present
				if(matl_values.size() == 4){ 
					tf[0] = std::atof(matl_values[1].c_str());
					tf[1] = std::atof(matl_values[2].c_str());
					tf[2] = std::atof(matl_values[3].c_str());
					//cout <<"tf" << tf[0] << tf[1] << tf[2]<< endl;
					matl_data.Tf = tf;
				}
				//if only r & g are present
				
				else if(matl_values.size() == 3){
					tf[0] = std::atof(matl_values[1].c_str());
					tf[1] = std::atof(matl_values[2].c_str());
					tf[2] = tf[0];
					matl_data.Tf = tf;
				}
				//if only r is present
				else if(matl_values.size() == 2){
					tf[0] = std::atof(matl_values[1].c_str());
					tf[1] = tf[2] = tf[0];
					matl_data.Tf = tf;
				}
				
				
			}
			
		}
		
		//illum illum_# from 0 to 10
		
		else if(matl_values[0] == "illum"){
			matl_data.illum = std::atoi(matl_values[1].c_str());
		}
		//dissolve factor
		else if(matl_values[0] == "d"){
			
			//d -halo 0.6600
			
			
			if(matl_values[1] == "-halo"){
				
			}
			// d factor Specifies the dissolve for the current material.
			else {
				matl_data.d = std::atof(matl_values[1].c_str());
			}
		}
		
		//Ns exponent specular exponent for the current material
		
		else if(matl_values[0] == "Ns"){  
			matl_data.Ns = std::atof(matl_values[1].c_str());
			//cout <<  "Ns" << '\t' << matl_data.Ns << endl;
		}
		
		//sharpness value
		
		else if(matl_values[0] == "sharpness"){
			
		}
		//Ni optical_density
		
		else if(matl_values[0] == "Ni"){
			
		}
		//transparency
		else if(matl_values[0] == "Tr"){
			matl_data.Tr = std::atof(matl_values[1].c_str());
		}
		
		
		
		
	}//end of file reading
	materials_data.push_back(matl_data);
	//cout << "Size of materails data vector" <<  '\t' << materials_data.size() << endl;
	
	
}