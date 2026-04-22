function getById(id)
{
    return document.getElementById(id);
}

getById("adicionar").addEventListener("click", () =>
{
    let input = getById("input_item");
    let valor = input.value;

    if (valor != "")
    {
        let nova_opcao = document.createElement("option");
        nova_opcao.textContent = valor;
        nova_opcao.value = valor;
        
        getById("itens").appendChild(nova_opcao);

        input.value = "";
        input.focus()
    }
});