import {create_error, show_error} from "../error_show"

create_error("O campo deve ser preenchido", "#body");

document.querySelector('#botaoErro').addEventListener('click', show_error());

export {create_error, show_error}