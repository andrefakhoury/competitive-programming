const double EPS = 1e-9;

void binSearchDouble() {
	double lo, hi, mi;

	// Last false or first true
	while (hi - lo > EPS) {
		mi = (lo + hi) / 2.0;

		if (check(mi)) hi = mi;
		else lo = mi;
	}

	// Last true or first false
	while(hi - lo > EPS) {
		mi = (lo + hi) / 2.0;

		if (check(mi)) lo = mi;
		else hi = mi;
	}
}

void binSearchInt() {
	int lo, hi, mi;

	// Last false
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;

		if (check(mi)) hi = mi - 1;
		else lo = mi;
	}

	// First true
	while(lo < hi) {
		mi = (lo + hi) / 2;

		if (check(mi)) hi = mi;
		else lo = mi + 1;
	}

	// Last true
	while(lo < hi) {
		mi = (lo + hi + 1) / 2;

		if (check(mi)) lo = mi;
		else hi = mi - 1;
	}

	// First false
	while(lo < hi) {
		mi = (lo + hi) / 2;

		if (check(mi)) lo = mi + 1;
		else hi = mi;
	}
}