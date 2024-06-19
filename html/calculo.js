function fx(x, d = 3){
	return +x.toFixed(d);
}
function entre(n, x = 0, y = 1){
	if(n > x && n < y) return true;
	return false;
}
function min(x, y){
	if(x < y) return x;
	return y;
}
function potencia(x, p, d = 3){
	d = min(d, 15);
	let y = 1;
	if(p >= 1) while(p >= 1) y *= x, p--;
	if(p <= -1) while(p <= -1) y /= x, p++;
	if(p != 0 && entre(p, -1)){
	p = fx(p, d);
		let z = 1, w = 1, m = 1;
		while(m != p){
			if(m > p) z = fx(z +w, d);
			if(m < p) z = fx(z -w, d), w = fx(w /10, d), z = fx(z +w, d);
			if(entre(m, fx(p -fx(potencia(10, -d-1), d), d), fx(p +fx(potencia(10, -d-1), d), d))) break;
			m = fx(1 /z, d);
		}
		p = z;
	}
	return [fx(y), p];
}
function raiz(x, r = 2, d = 3){
	d = min(d, 15);
	let s = 1, y = 0;
	while(s > potencia(10, -(d +1))){
		if(potencia(y, r) < x) y += s;
		if(potencia(y, r) > x) y -= s, s /= 10;
		if(potencia(y, r) == x) break;
	}
	return fx(y, d);
}
