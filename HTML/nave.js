class Nave {
	constructor(specs = {}) {
		const padrao = { x: 0, y: 0, a: 0, v: 1, tamanho: 1, vel_rotacao: 1, vel_disparo: 1, dano: 1, poligono: 3 };
		specs = { ...padrao, ...specs };
		for (let s in specs) {
			this[s] = specs[s];
		}
	}
	desenhar(c) {

		const { x, y, tamanho, a } = this;
		const { seno, coseno, grau_radiano } = matematica;

		c.beginPath();
		c.strokeStyle = 'white';
		c.lineWidth = 3;
		//c.moveTo(x, y);
		c.moveTo(x + (seno(grau_radiano(a))) * tamanho, y - (coseno(grau_radiano(a))) * tamanho);
		c.lineTo(x + (seno(grau_radiano(a + 360 / 3))) * tamanho, y - (coseno(grau_radiano(a + 360 / 3))) * tamanho);
		c.lineTo(x + (seno(grau_radiano(a + 360 / 3 * 2))) * tamanho, y - (coseno(grau_radiano(a + 360 / 3 * 2))) * tamanho);
		c.closePath();
		c.stroke();

		// c.fillRect(x, y, tamanho, tamanho);
	}
	calcular(dt) {
		var { x, y } = this;
		x = mouse.x - translacao.w;
		y = mouse.y - translacao.h;
		this.x = x;
		this.y = y;
	}
	girar(direcao) {
		var { a, vel_rotacao } = this;
		direcao * vel_rotacao
		a = (a + direcao * vel_rotacao) % 360;
		this.a = a;
	}
}
