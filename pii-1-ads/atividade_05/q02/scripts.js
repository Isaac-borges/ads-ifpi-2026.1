import {show_error, create_error} from '../error_show.js'

create_error("Conteúdo do campo não pode ser vazio", "#error_container", "mensagem_erro");

var botaoExibir = document.querySelector('#botaoExibir');
botaoExibir.addEventListener('click', exibirConteudo);

function checar_conteudo(conteudo)
{
    let conteudo_check = conteudo.trim();

    if (conteudo_check === "") return false;

    return true;
}

function exibirConteudo() {
    var conteudo = document.querySelector('#caixaDeTexto').value;
    if (!checar_conteudo(conteudo))
    {
        show_error("mensagem_erro");
        return;
    }

    document.querySelector('#conteudo').innerHTML = conteudo;
}