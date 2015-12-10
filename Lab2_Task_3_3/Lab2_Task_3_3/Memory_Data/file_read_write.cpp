/*int data;
	int d;
	int mem_data[1040];
	int i = 0;
	FILE *mem = fopen("Memory_Data\\T1.txt", "r");
	if (!mem) {
		cout << "Could not open the file\n";

	}
	while (fscanf(mem, "%d %xn ", &data, &d) != EOF) {

		//cout << data << "\t" << std::hex <<d << "\n";
		mem_data[data] = d;
		i++;

	}

	for (int j = 0; j < i; j++) {
		cout << j << "\t";
		cout << std::hex << mem_data[j] << endl;
	}
	*/