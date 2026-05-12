function q(selector)
{
    return document.querySelector(selector);
}

var select = q("#imagens");
var img = q("#imagem")
select.addEventListener('change', () =>
{
    if(select.value !== "") 
        img.src = select.value;
    else
        img.src = "";
});