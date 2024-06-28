
class Camera{
  constructor(configuracao){
    let predefinido = {
      posicao: { x:0, y:0, z:180 },
      orientacao: { alfa:0, beta:0, gama:0 },
      campo_de_visao: 90,
      distancia: 360
    };
    configuracao = {...predefinido, ...configuracao};
    this.posicao = configuracao.posicao;
    this.orientacao = configuracao.orientacao;
    this.campo_de_visao = configuracao.campo_de_visao;
    this.distancia = configuracao.distancia;
  }
  get pos(){
    return [this.posicao.x, this.posicao.y, this.posicao.z];
  }
  get ori(){
    return [this.orientacao.alfa, this.orientacao.beta, this.orientacao.gama];
  }
  }
