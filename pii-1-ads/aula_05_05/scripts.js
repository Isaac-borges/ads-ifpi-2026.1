function getById(id)
{
    return document.getElementById(id);
}

function q(selector)
{
    return document.querySelector(selector);
}

let id = 1;

q('#cadastrar').addEventListener('click', () =>
{
    let descricao = q('#descricao').value;
    let status = q('#status').value;
    
    let tarefas = q('#tarefas');

    //criando uma linha
    let linha = document.createElement('tr');
    linha.id = id;
    //criando as colunas
    let tdId = document.createElement('td');
    let tdDescricao = document.createElement('td');
    let tdStatus = document.createElement('td');
    let tdInicio = document.createElement('td');
    let tdFim = document.createElement('td');
    let tdAcoes = document.createElement('td');
    let botaoIniciar = document.createElement('button');
    let botaoConcluir = document.createElement('button');

    //preenchendo as colunas 
    tdId.innerText = id;
    tdDescricao.innerText = descricao;
    tdStatus.innerText = status;
    botaoIniciar.value = 'iniciar';
    botaoIniciar.innerText = "Iniciar";
    botaoConcluir.innerText = "Concluir";
    botaoConcluir.style.display = "none";
    
    linha.appendChild(tdId);
    linha.appendChild(tdDescricao);
    linha.appendChild(tdStatus);
    linha.appendChild(tdInicio);
    linha.appendChild(tdFim);
    linha.appendChild(tdAcoes);
    tdAcoes.appendChild(botaoIniciar);
    tdAcoes.appendChild(botaoConcluir);

    tarefas.appendChild(linha);

    botaoIniciar.addEventListener("click", () =>
    {
        tdStatus.innerText = "Iniciada";
        let dataInicio = new Date();
        tdInicio.innerText = dataInicio.toLocaleDateString('pt-BR');
        botaoIniciar.style.display = 'none';
        botaoConcluir.style.display = 'inline';
    });

    botaoIniciar.addEventListener("click", () =>
    {
        botaoConcluir.style.display = "none";
        tdStatus.innerText = "Concluida";
        let dataFim = new Date();
        tdFim.innerText 
    });
});