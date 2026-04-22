// Helper para pegar elementos garantindo que não são nulos e definindo o tipo
function getById<T extends HTMLElement>(id: string): T {
    const elemento = document.getElementById(id);
    if (!elemento) {
        throw new Error(`Elemento com id ${id} não encontrado.`);
    }
    return elemento as T;
}

// Tipando os elementos do DOM
const botao_calcular = getById<HTMLButtonElement>("calc");
// Usamos HTMLInputElement para o grupo de radios para acessar a propriedade .checked
const operacoes = getById<HTMLDivElement>("operacoes").children as HTMLCollectionOf<HTMLInputElement>;
const div_resultado = getById<HTMLDivElement>("resultado");

// Função com tipos explícitos para os parâmetros
function check_operandos(operando1: number, operando2: number): boolean {
    return Number.isNaN(operando1) || Number.isNaN(operando2);
}

function mostrar_resultado(resultado: number | string): void {
    div_resultado.innerText = `Resultado: ${resultado}`;
}

function adicionar(operando1: number, operando2: number): void {
    const resultado: number = operando1 + operando2;
    mostrar_resultado(resultado);
}

function subtrair(operando1: number, operando2: number): void {
    const resultado: number = operando1 - operando2;
    mostrar_resultado(resultado);
}

function multiplicar(operando1: number, operando2: number): void {
    const resultado: number = operando1 * operando2;
    mostrar_resultado(resultado);
}

function dividir(operando1: number, operando2: number): void {
    if (operando2 === 0) {
        mostrar_resultado("Indefinido");
        return;
    }
    const resultado: number = operando1 / operando2;
    mostrar_resultado(resultado);
}

botao_calcular.addEventListener("click", (): void => {   
    const input1 = getById<HTMLInputElement>("operando1");
    const input2 = getById<HTMLInputElement>("operando2");

    const operando1: number = parseFloat(input1.value);
    const operando2: number = parseFloat(input2.value);

    if (check_operandos(operando1, operando2)) {
        div_resultado.innerText = "Operandos inválidos";
        return;
    }

    // EM VEZ DE USAR O LOOP NO 'operacoes.children':
    // Buscamos diretamente o rádio que está checado dentro da div
    const radioSelecionado = document.querySelector<HTMLInputElement>('input[name="operacao"]:checked');

    if (radioSelecionado) {
        const operacao = radioSelecionado.value;
        
        if (operacao === "adicao") adicionar(operando1, operando2);
        else if (operacao === "subtracao") subtrair(operando1, operando2);
        else if (operacao === "multiplicacao") multiplicar(operando1, operando2);
        else if (operacao === "divisao") dividir(operando1, operando2);
    } else {
        div_resultado.innerText = "Selecione uma operação";
    }
});