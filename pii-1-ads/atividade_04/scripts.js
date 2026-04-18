function getById(id)
{
    return document.getElementById(id);
}

getById('botao1').addEventListener("click", () =>
{
    let p1 = getById('p1');
    let resultado1 = getById('resultado1');
    resultado1.innerText = p1.innerHTML + " - ADS 3"; 
});

let texto2 = getById('texto2');

texto2.addEventListener('keyup', () =>
{
    let texto = texto2.value;
    texto2.value = texto.toUpperCase();
});

