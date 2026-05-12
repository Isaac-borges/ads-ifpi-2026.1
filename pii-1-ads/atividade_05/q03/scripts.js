import {show_error, create_error} from "../error_show.js";

create_error("Erro: Insira dois valores válidos.","#show_errors", "valor_invalido");

function q(selector)
{
    return document.querySelector(selector);
}

q("#botao_calculo").addEventListener('click', () =>
{
    let interacoes = parseInt(q("#interacoes").value);
    let visualizacoes = parseInt(q("#visualizacoes").value);

    if ((isNaN(interacoes) || isNaN(visualizacoes))
    || (interacoes <= 0 || visualizacoes <= 0))
    {
        show_error("valor_invalido")
        return;
    }

    let engajamento = (interacoes/visualizacoes) * 100;

    let p_resultado = q("#resultado");

    p_resultado.innerText = `A taxa de engajamento é ${engajamento}%!`;
});