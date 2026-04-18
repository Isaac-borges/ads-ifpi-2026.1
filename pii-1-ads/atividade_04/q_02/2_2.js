function getById(id)
{
    return document.getElementById(id);
}

function getByTag(tag_name)
{
    return document.getElementsByTagName(tag_name);
}

let botao = getByTag("button")[0];

botao.addEventListener("click", () =>
{
    let paragrafos = getByTag("p");
    let div_resultado = getByTag("div")[0];

    let posicao = 0;

    for (i=0; i<paragrafos.length; i++)
    {
        if (Number(paragrafos[i].innerText) == 3)
        {
            posicao = i + 1;
        }
    }

    div_resultado.innerText = `O número 3 está no ${posicao}º parágrafo!`;
});
