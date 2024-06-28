
// usar palavras em inglês se possível,
// para preservar leitura e estética de códigos!

const canvas = document.getElementById('canvas');
const fps = document.getElementById('fps');

const c = canvas.getContext('2d');

var lastTimeStamp = 0;

const player = new Player();

function holdKey(e) {
	if(e.code == 'KeyW') player.keys.w = true;
	if(e.code == 'KeyA') player.keys.a = true;
	if(e.code == 'KeyS') player.keys.s = true;
	if(e.code == 'KeyD') player.keys.d = true;
	if(e.code == 'KeyQ') player.keys.q = true;
	if(e.code == 'KeyE') player.keys.e = true;
}

function dropKey(e) {
	if(e.code == 'KeyW') player.keys.w = false;
	if(e.code == 'KeyA') player.keys.a = false;
	if(e.code == 'KeyS') player.keys.s = false;
	if(e.code == 'KeyD') player.keys.d = false;
	if(e.code == 'KeyQ') player.keys.q = false;
	if(e.code == 'KeyE') player.keys.e = false;
}

document.addEventListener('keydown', holdKey);
document.addEventListener('keyup', dropKey);

function loop(timeStamp) {
	
	c.clearRect(0, 0, canvas.width, canvas.height);
	
	if(player.xPosition > canvas.width) player.xPosition -= canvas.width;
	if(player.xPosition < 0) player.xPosition += canvas.width;
	if(player.yPosition > canvas.height) player.yPosition -= canvas.height;
	if(player.yPosition < 0) player.yPosition += canvas.height;
	
	player.updateControls();
	player.updatePosition();
	player.draw(c);
	//
	//	//
	//	//	//
	//	//
	//
	fps.textContent = Math.floor(1000000 / (timeStamp - lastTimeStamp)) / 1000;
	
	lastTimeStamp = timeStamp;
	
	requestAnimationFrame(loop);
}

requestAnimationFrame(loop);
    
