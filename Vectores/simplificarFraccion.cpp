void simplificar(int n, int d) {
	if (n == 0 || d == 1) {
		cout << n << "/" << d;
	}else{
		bool esMax = false;
		int max = abs(n);
		while (max > 1 && !esMax) {
			if (n % max == 0 && d % max == 0) {
				n = n / max;
				d = d / max;
				esMax = true;
			}
			max--;
		}

		if (d < 0 && n>0) {
			n = -n;
			d = abs(d);
		}else if (d < 0 && n < 0) {
			n = abs(n);
			d = abs(d);
		}
		cout << n << "/" << d;
	}
}
