function getById(id)
{
    return document.getElementById(id);
}

getById("contar").addEventListener("click", () =>
{
    let div = getById("div_teste");
    let count_p = 0;
    let count_c = 0;

    for (i=0; i < div.children.length; i++)
    {
        if (div.children[i].nodeName == "P") count_p += 1;
        count_c += 1;
    }

    getById("resultado_conta").innerText = `Quantidade de parágrafos = ${count_p}\nQuantidade de filhos = ${count_c} (<br> também entra)`;
});