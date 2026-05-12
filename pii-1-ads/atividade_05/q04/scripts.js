document.getElementById("carregar_imagem").addEventListener('click', () =>
{
    let upload_imagem = document.getElementById("upload_imagem")
    let arquivo_selecionado = upload_imagem.files[0];

    let div_resultado = document.getElementById("resultado")
    let tag_img = document.createElement('img');
    tag_img.src = URL.createObjectURL(arquivo_selecionado);
    
    div_resultado.appendChild(tag_img);
    div_resultado.appendChild(document.createElement('br'));
});