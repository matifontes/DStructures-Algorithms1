int* intercalarVector(int* v1, int* v2, int l1, int l2){
	int indiceV1 = 0;
	int indiceV2 = 0;
	int lTotal = l1 + l2;
	
	if (l1 == 0 && l2 == 0) {
		return NULL;
	}else{
		int* vecRes = new int[lTotal];
		for (int i = 0; i < lTotal; i++) {
			if (indiceV1 < l1 && indiceV2 < l2 && v1[indiceV1] <= v2[indiceV2]) {
				int nuevo = v1[indiceV1];
				vecRes[i] = nuevo;
				indiceV1++;
			}
			else if (indiceV1 < l1 && indiceV2 < l2 && v1[indiceV1] > v2[indiceV2]) {
				int nuevo = v2[indiceV2];
				vecRes[i] = nuevo;
				indiceV2++;
			}
			else if (indiceV1 >= l1 && indiceV2 < l2) {
				int nuevo = v2[indiceV2];
				vecRes[i] = nuevo;
				indiceV2++;
			}
			else if (indiceV2 >= l2 && indiceV1 < l1) {
				int nuevo = v1[indiceV1];
				vecRes[i] = nuevo;
				indiceV1++;
			}
		}

		return vecRes;
	}
	
}
