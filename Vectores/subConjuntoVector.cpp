bool subconjuntoVector(int* v1, int* v2, int l1, int l2) {
	bool res = true;
	if (v1 == NULL) {
		return true;
	}
	else {
		for (int i = 0; i < l1 && res; i++) {
			bool pertenece = false;
			for (int j = 0; j < l2 && !pertenece; j++) {
				if (v1[i] == v2[j]) {
					pertenece = true;
				}
			}
			if (!pertenece) {
				res = false;
			}
		}
		return res;
	}
}
