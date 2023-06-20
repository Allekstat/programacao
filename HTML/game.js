const canvas = document.getElementById('canvas');
const c = canvas.getContext('2d');
const log = console.log;

function canvas_calibrar_tamanho(resolucao = 100) {
	if (resolucao > 100 || resolucao < 1) { return false; }

	//canvas.style.height = document.body.clientHeight -canvas.computedStyleMap().get('border-top-width').value *2 +'px';
	const ar = getComputedStyle(canvas).aspectRatio.split(' / '),
		h = resolucao / 100 * (canvas.style.height.slice(0, -2) * 1),
		w = Math.floor((ar[0] * 1) / (ar[1] * 1) * h);
	canvas.width = w;
	canvas.height = h;
	if (canvas.width === w && canvas.height === h) return true;
	return false;
};
//canvas_calibrar_tamanho();

canvas.addEventListener('mousemove',
	function (evento) {
		mouse.x = evento.x;
		mouse.y = evento.y;
	}, {passive: true}
);
canvas.addEventListener('wheel',
	function (evento) {
		mouse.w = evento.deltaY;
		if (mouse.w < 0) {
			mouse.w = -1;
		} else {
			mouse.w = 1;
		}
		player.girar(mouse.w);
		log(evento);
	}, {passive: true}
);
canvas.addEventListener('keydown',
	function (evento) {
		console.log(evento);
	}, {passive: true}
);
const mouse = {
	x: null,
	y: null,
	w: null
};
const keys = {
	w: false,
	a: false,
	s: false,
	d: false
}

const translacao = { w: c.canvas.width / 2, h: c.canvas.height / 2 };
c.translate(translacao.w, translacao.h);
function canvas_limpar() {
	c.clearRect(-translacao.w, -translacao.h, canvas.width, canvas.height);
};

const player = new Nave({ tamanho: 30, vel_rotacao: 15 });

function game_loop(timestamp, deltatime) {
	let delta = timestamp - deltatime;
	// console.log(timestamp,deltatime,delta);
	canvas_limpar();
	player.calcular(delta);
	player.desenhar(c);
	requestAnimationFrame(function (ts) { game_loop(ts, timestamp) });
};
requestAnimationFrame(function () { game_loop(0, 0) });
