
class Objeto{
  constructor(configuracao){
    let predefinido = {
      posicao: { x:0, y:0, z:0 },
      orientacao: { alfa:0, beta:0, gama:0 },
      tamanho: 1,
      faces:[{
          pontos:[
            { x:-1, y:-1, z:0 },
            { x:1, y:-1, z:0 },
            { x:1, y:1, z:0 },
            { x:-1, y:1, z:0 }
          ],
          fechado: true
        }]
      };

    configuracao = {...predefinido, ...configuracao};

    this.posicao = configuracao.posicao;
    this.orientacao = configuracao.orientacao;
    this.faces = configuracao.faces;
    this.tamanho = configuracao.tamanho;
  }

  draw(c, canvas, camera){
    let diferenca_do_z = camera.posicao.z -this.posicao.z;
    if(diferenca_do_z <= 0 || diferenca_do_z > camera.distancia){
      return false;
    }
    for(let face of this.faces){
      let f = true;
      for(let ponto of face.pontos){
        if(f){
          f = false;
          c.beginPath();
          c.moveTo((this.posicao.x +ponto.x *this.tamanho -camera.posicao.x) /(ponto.z +diferenca_do_z), (this.posicao.y +ponto.y *this.tamanho) /(ponto.z +diferenca_do_z));
        }else{
          c.lineTo((this.posicao.x +ponto.x *this.tamanho -camera.posicao.x) /(ponto.z +diferenca_do_z), (this.posicao.y +ponto.y *this.tamanho) /(ponto.z +diferenca_do_z));
        }
      }
      if(face.fechado){
        c.closePath();
      }
    }
    c.stroke();
  }

  get pos(){
    return [this.posicao.x, this.posicao.y, this.posicao.z];
  }
}
