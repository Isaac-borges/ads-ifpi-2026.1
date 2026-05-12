function create_error(texto_erro, pai_id, nome_erro)
{
    if (document.querySelector(`#show_error_${nome_erro}`) === null)
    {
        let div_filho = document.createElement('div');
        div_filho.innerText = texto_erro;
        div_filho.id = `show_error_${nome_erro}`
        div_filho.classList.add('show_error_oculto')

        let div_pai = document.querySelector(pai_id);
        div_pai.appendChild(div_filho);
    }
}

function show_error(nome_erro) {
    var errorMessage = document.querySelector(`#show_error_${nome_erro}`);
    errorMessage.classList.remove('show_error_oculto');
    errorMessage.classList.add('show_error_mostrar');

    setTimeout(function() {
        errorMessage.classList.add('show_error_oculto');
    }, 3000);
}

export {show_error, create_error}