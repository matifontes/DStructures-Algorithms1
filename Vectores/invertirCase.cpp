char* invertirCase(char* palabra){


	char* nueva = new char[largo(palabra)+1];
	
	int i = 0;
	while (palabra[i]!=0){
		if (palabra[i] <= 'Z' && palabra[i] >= 'A') {
			nueva[i] = (palabra[i] + ('a' - 'A'));
		}
		else if (palabra[i] <= 'z' && palabra[i] >= 'a') {
			nueva[i] = (palabra[i] - ('a'- 'A'));
		}
		else {
			nueva[i] = palabra[i];
		}
		++i;
	}
	nueva[i] = '\0';
	return nueva;
}
