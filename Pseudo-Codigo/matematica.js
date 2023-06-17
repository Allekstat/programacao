const matematica = {
	fix(x) { if (typeof x !== 'number' || x +'' === 'NaN' || x +'' === 'Infinity') { return null } return (x).toFixed(6) *1 },
    seno(x) { return matematica.fix(Math.sin(x)) },
	coseno(x) { return matematica.fix(Math.cos(x)) },
	tan(x) { return matematica.fix(Math.tan(x)) },
	atan(x) { return matematica.fix(Math.atan(x)) },
	pi: Math.PI,
	grau_radiano(g) { return g *matematica.pi /180 },
	radiano_grau(r) { return r *180 /matematica.pi },
	direcao(angulo) { return {x: matematica.coseno(matematica.grau_radiano(angulo)), y: matematica.seno(matematica.grau_radiano(angulo)) } },
	arredondar(x) { return 0 +matematica.fix(x +matematica.atan(matematica.tan(-x *matematica.pi -matematica.pi /(2 **50))) /matematica.pi) },
	chao(x) { return 0 +matematica.fix(x +matematica.atan(matematica.tan(-x *matematica.pi +matematica.pi /2 -matematica.pi /(2 **50))) /matematica.pi -0.5) },
	teto(x) { return 0 +matematica.fix(x +matematica.atan(matematica.tan(-x *matematica.pi +matematica.pi /2 +matematica.pi /(2 **50))) /matematica.pi +0.5) },
	resto(x, d=1) { return x -matematica.chao(x /d) *d },
	decimal(x) {  return 0 +matematica.fix(x -matematica.chao(x)) },
	raiz(x, r=2) { return 0 +matematica.fix(x **(1 /r)) },
	soma(x=0, y=0) { x = matematica.fix(x); y = matematica.fix(y); return matematica.fix(x +y) },
	multi(x=0, y=1) { x = matematica.fix(x); y = matematica.fix(y); return matematica.fix(x *y) }
}