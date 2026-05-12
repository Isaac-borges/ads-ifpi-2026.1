import {create_error, show_error} from "../error_show.js"

create_error("Não foi selecionada nenhuma opção!", "#mensagem_erro", "sem_opcao")

function qAll(selector)
{
    return document.querySelectorAll(selector);
}

function q(selector)
{
    return document.querySelector(selector);
}

q("#botao_enviar").addEventListener('click', () =>
{
    let opcoes = qAll("input");
    let redes_selecionadas = [];

    for (let i = 0; i<opcoes.length; i++)
    {
        if (opcoes[i].checked) redes_selecionadas.push(opcoes[i]);
    }

    if (redes_selecionadas.length <= 0) 
    {
        show_error("sem_opcao");
        q("#redes_selecionadas").innerText = "";
        return;
    }

    let texto = "";

    for (let rede of redes_selecionadas)
    {
        texto += rede.value + " "; 
    }

    q("#redes_selecionadas").innerText = texto;
});