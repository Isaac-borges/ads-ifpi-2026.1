import {create_error, show_error} from "../error_show.js";

create_error("A hashtag não pode estar vazia.", "#mensagem_erro", "hashtag_vazia");
create_error("A hashtag deve ter pelo menos 2 caracteres.", "#mensagem_erro", "hashtag_min");
create_error("Limite de 5 hashtags atingido.", "#mensagem_erro", "max_hashtag");
create_error("Esta hashtag já foi adicionada.", "#mensagem_erro", "hashtag_existe")
function q(selector)
{
    return document.querySelector(selector)
}

function qAll(selector)
{
    return document.querySelectorAll(selector);
}

const input = q('#input_hashtag');
const botao_adicionar = q('#botao_adicionar');
const botao_remover = q('#botao_remover');
const select = q('#lista_hashtags');
const display_erro = q('#mensagem_erro');

botao_adicionar.addEventListener("click", () =>
{
    let valor = input.value.trim();

    if (valor === "") {
        show_error("hashtag_vazia");
        return;
    }
    if (valor.length < 2) {
        show_error("hashtag_min");
        return;
    }
    if (select.options.length >= 5) {
        show_error("max_hashtag");
        return;
    }
    
    for (let i = 0; i < select.options.length; i++) {
        if (select.options[i].value.toLowerCase() === valor.toLowerCase()) {
            show_error("hashtag_existe");
            return;
        }
    }

    const nova_option = document.createElement('option');
    nova_option.value = valor;
    nova_option.textContent = valor.startsWith('#') ? valor : '#' + valor;
    
    select.appendChild(nova_option);

    input.value = "";
    input.focus();
}) 
    
botao_remover.onclick = function() {
    display_erro.textContent = "";

    const selecionados = select.selectedOptions;

    if (selecionados.length === 0) {
        mostrarErro("Selecione uma hashtag para remover.");
        return;
    }

    select.removeChild(selecionados[0]);
};