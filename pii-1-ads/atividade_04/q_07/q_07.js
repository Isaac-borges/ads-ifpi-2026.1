function getById(id) 
{
    return document.getElementById(id);
}

let caixa_baixa = getById("min_text");
let caixa_alta = getById("max_text");

caixa_baixa.addEventListener("keyup", ()=>
{
    caixa_alta.value = caixa_baixa.value.toUpperCase();
});