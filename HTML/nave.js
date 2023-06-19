class Nave {
	constructor(specs={}) {
		const padrao = {x: 0, y: 0, a: 0, v: 1, tamanho: 1, vel_rotacao: 1, vel_disparo: 1, dano: 1, poligono: 3};
		specs = {...padrao, ...specs};
		for(let s in specs) {
			this[s] = specs[s];
		}
	}
	desenhar(c) {

		const {x, y, tamanho, a, poligono} = this;
		const {direcao} = matematica;

		c.beginPath();
		c.fillStyle = 'white';
		c.fillRect(x, y, tamanho, tamanho);
	}
	calcular() {
		var {x, y} = this;
		x = mouseX -translacao.w;
		y = mouseY -translacao.h;
		this.x = x;
		this.y = y;
	}
}
