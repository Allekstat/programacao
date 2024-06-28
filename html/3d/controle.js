
class Controle{
  constructor(){
    
  }
  adicionar_botao(cfg){
    const std = {
      elemento: null,
      acao: {
        tipo: null,
        funcao: null
      },
      novo: false
    };
    cfg = {...std, ...cfg};
    if(cfg.elemento === null){
      return false;
    }
  }
}
