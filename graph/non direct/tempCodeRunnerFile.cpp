void docfile(dothi &g) {
	int i, j;
	i = 0;
	char c;
	FILE*f = fopen("DSK.txt","r");
	fscanf(f,"%d",&g.V);
	while(i <= g.V) {
		fscanf(f, "%c", &c);
		if(c == '\n') {
			i++;
		}
		else {
			if(c != ' ') {
				j = c - '0';
				g.a[i][j] =  1;
			}
		}
	}
	fclose(f);
}