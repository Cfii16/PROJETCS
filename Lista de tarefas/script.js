// apanha os elementos do html
const taskInput = document.getElementById("taskInput");
//const: Cria uma variável que não vai mudar (como uma caixa com um nome fixo).
//document: Representa toda a página HTML no JavaScript.
//getElementById("taskInput"): Procura no HTML um elemento com o id="taskInput" (o nosso <input>).
//taskInput: Agora essa variável "guarda" o campo de texto para usarmos depois.

const taskList = document.getElementById("taskList");

loadTasks(); // Chama a função loadTasks() assim que o JavaScript roda.

function addTask() { // função para adicionar tarefa à lista
    const taskText = taskInput.value; // pega o texto que se digita no campo

    if (taskText === "") {
        alert("Por favor, digite uma tarefa!");
        return;
    }

    const li = document.createElement("li"); // Cria um novo item de lista (li) para a tarefa
    li.textContent = taskText; // Coloca o texto da tarefa no item

    // Botão "Concluir"
    const completeButton = document.createElement("button");
    completeButton.textContent = "Concluir";
    completeButton.onclick = function() {
        li.classList.toggle("completed"); // Alterna a classe "completed"
        saveTasks(); // Salva o estado atualizado
    };
    li.appendChild(completeButton); // Adiciona o botão ao <li>

    // Botão "Excluir"
    const deleteButton = document.createElement("button");
    deleteButton.textContent = "Excluir";
    deleteButton.className = "delete-button"; // Adiciona a classe para o estilo vermelho
    deleteButton.onclick = function() {
        li.remove(); // Remove o <li> da lista
        saveTasks(); // Atualiza o localStorage
    };
    li.appendChild(deleteButton); // Adiciona o botão ao <li>

    taskList.appendChild(li); // Adiciona o item à lista no html

    taskInput.value = ""; // limpa o campo de entrada depois de adicionar

    saveTasks(); // guarda as tarefas no armazenamento
}

function saveTasks() { // função para salvar as tarefas no localStorage
    const tasks = []; // cria um array vazio para guardar as tarefas
    const taskItems = taskList.getElementsByTagName("li"); // pega todos os itens da lista <li>

    for (let i = 0; i < taskItems.length; i++) { // passa por cada item
        const task = {
            text: taskItems[i].textContent.replace("Concluir", "").replace("Excluir", "").trim(), // Pega o texto sem os botões
            completed: taskItems[i].classList.contains("completed") // Verifica se está concluído
        };
        tasks.push(task); // adiciona o objeto ao array
    }

    localStorage.setItem("tasks", JSON.stringify(tasks)); // salva o array no storage
}

function loadTasks() { // carregar as tarefas salvas do localStorage
    const savedTasks = localStorage.getItem("tasks"); // pega o texto salvo

    if (savedTasks) { // verifica se há algo salvo
        const tasks = JSON.parse(savedTasks); // converte o texto de volta para um array

        for (let i = 0; i < tasks.length; i++) { // para cada tarefa no array
            const li = document.createElement("li"); // cria um novo <li>
            li.textContent = tasks[i].text; // coloca o texto da tarefa

            // Botão "Concluir" para tarefas carregadas
            const completeButton = document.createElement("button");
            completeButton.textContent = "Concluir";
            completeButton.onclick = function() {
                li.classList.toggle("completed");
                saveTasks();
            };
            li.appendChild(completeButton);

            // Botão "Excluir" para tarefas carregadas
            const deleteButton = document.createElement("button");
            deleteButton.textContent = "Excluir";
            deleteButton.className = "delete-button"; // Adiciona a classe para o estilo vermelho
            deleteButton.onclick = function() {
                li.remove();
                saveTasks();
            };
            li.appendChild(deleteButton);

            if (tasks[i].completed) { // Se a tarefa estava concluída, aplica a classe
                li.classList.add("completed");
            }

            taskList.appendChild(li); // adiciona o <li> à lista
        }
    }
}

// Função para limpar todas as tarefas e o localStorage
function clearAll() {
    taskList.innerHTML = ""; // Remove todos os <li>
    localStorage.removeItem("tasks"); // Limpa as tarefas salvas
}