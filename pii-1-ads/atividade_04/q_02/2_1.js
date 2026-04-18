function getById(id)
{
    return document.getElementById(id);
}

getById("multiplicar").addEventListener("click", () =>
{
    let num1 = Number(getById("num1").value);
    let num2 = Number(getById("num2").value);

    let resultado_div = getById("resultado");
    let resultado = num1 * num2;
    resultado_div.innerText = `Resultado: ${resultado}`;
});