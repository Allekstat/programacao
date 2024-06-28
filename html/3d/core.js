
const canvas = document.getElementsByTagName("canvas")[0];
const c = canvas.getContext("2d");

function HndD(e){
  switch(e.code){
    case "KeyA": {
      camera.posicao.x -= 1;
    } break;
    case "KeyD": {
      camera.posicao.x += 1;
    } break;
    case "KeyW": {
      camera.posicao.z -= 1;
    } break;
    case "KeyS": {
      camera.posicao.z += 1;
    } break;
  }
}
function HndU(){}
document.addEventListener('keydown', HndD);
document.addEventListener('keyup', HndU);

var objetos = [];
var camera = new Camera({posicao: {x:0, y:0, z:10}});
var pause = false;

function setup(){
  objetos.push(new Objeto({
    tamanho: 10,
    posicao: { x:0, y:0, z:0 },
    faces:[
      {pontos:[
        { x:-10, y:-10, z:0 },
        { x:10, y:-10, z:0 },
        { x:10, y:10, z:0 },
        { x:-10, y:10, z:0 }
      ],
      fechado: true},
      {pontos:[
        { x:10, y:-10, z:0 },
        { x:10, y:-10, z:-10 },
        { x:10, y:10, z:-10 },
        { x:10, y:10, z:0 }
      ],
      fechado: true}]
  }));

  return true;
}

function loop(){
  c.reset();
  c.translate(canvas.width/2, canvas.height/2);
  //c.clearRect(-canvas.width, -canvas.height, 2* canvas.width, 2* canvas.height);
  for(objeto of objetos){
    objeto.draw(c, canvas, camera);
  }

  if(!pause){
    requestAnimationFrame(loop);
  }
}

setup();
requestAnimationFrame(loop);
