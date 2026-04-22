function getById(id)
{
    return document.getElementById(id);
}

let botao_calcular = getById("calc");
let operacoes = getById("operacoes").children;
let div_resultado = getById("resultado");

function check_operandos(operando1, operando2)
{
    return (Number.isNaN(operando1) && Number.isNaN(operando2));
}

function mostrar_resultado(resultado)
{
    div_resultado.innerText = `Resultado: ${resultado}`;
}

function adicionar(operando1, operando2)
{
    let resultado = operando1 + operando2;

    mostrar_resultado(resultado);
}

function subtrair(operando1, operando2)
{
    let resultado = operando1 - operando2;

    mostrar_resultado(resultado);
}

function multiplicar(operando1, operando2)
{
    let resultado = operando1 * operando2;

    mostrar_resultado(resultado);
}

function dividir(operando1, operando2)
{
    if (operando2 == 0)
    {
        mostrar_resultado("Indefinido");
        return;
    }

    let resultado = operando1 / operando2;

    mostrar_resultado(resultado);
}

botao_calcular.addEventListener("click", () =>
{   
    let operando1 = parseFloat(getById("operando1").value);
    let operando2 = parseFloat(getById("operando2").value);

    if (check_operandos(operando1, operando2)) {
        div_resultado.innerText = "Operandos inválidos";
        return;
    }

    for (i=0; i<operacoes.length; i++)
    {
        if (operacoes[i].checked)
        {
            if (operacoes[i].value == "adicao") adicionar(operando1, operando2);
            if (operacoes[i].value == "subtracao") subtrair(operando1, operando2);
            if (operacoes[i].value == "multiplicacao") multiplicar(operando1, operando2);
            if (operacoes[i].value == "divisao") dividir(operando1, operando2);
        } 
    }
});