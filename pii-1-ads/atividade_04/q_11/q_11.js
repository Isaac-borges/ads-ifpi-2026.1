function getById(id)
{
    return document.getElementById(id);
}

getById("botao_adicionar").addEventListener("click", () =>
{
    let input = getById("input_item");
    let valor = input.value;

    if (valor != "")
    {
        let novo_item = document.createElement("li");
        novo_item.textContent = valor;

        getById("lista").appendChild(novo_item);

        input.value = "";
        input.focus();
    }
});